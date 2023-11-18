# Padding en una matriz

Codigo propocionado por Paul Andres Solis Villanueva

Este codigo hace un pading en una matriz de x * y con valores aleatorios y que realize la suma de los valores de manera paralela

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

#define X 5
#define Y 5
#define PADDING_SIZE_X 1

#define BLOCK_SIZE_X 16
#define BLOCK_SIZE_Y 16

__global__ void applyPadding(int *matrix, int *paddedMatrix, int width, int height, int paddingX) {
    
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;
    unsigned int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row  < height) {
        paddedMatrix[row * (width + paddingX) + col + paddingX] = matrix[row * width + col];
    }
}

__global__ void sumColumns(int *matrix, int *result, int width, int height) {
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (col < width) {
        int sum = 0;
        for (int row = 0; row < height; ++row) {
            sum += matrix[(row) * width + col];
        }
        result[col] = sum;
    }
}

int main() {
    int matrix[X][Y];
    int paddedMatrix[X + PADDING_SIZE_X][Y];
    int result[Y];

    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            //We add one so that we can see the padding as 0's and nothing else
            matrix[i][j] = (rand() % 9)+1;
            //for testing purposes to compare to the image in the book
            //matrix[i][j] = j+1;
        }
    }
    // Print original matrix
    printf("Original:\n");
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    //GPU variables
    int *d_matrix, *d_paddedMatrix, *d_padMatrix, *d_resultSum;

    //allocates memory of variables of the GPU for the first kernel
    cudaMalloc((void **)&d_matrix, X * Y * sizeof(int));
    cudaMalloc((void **)&d_paddedMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int));

    //For the second kernel
    cudaMalloc((void **)&d_padMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int));
    cudaMalloc((void **)&d_resultSum, Y * sizeof(int));

    cudaMemcpy(d_matrix, matrix, X * Y * sizeof(int), cudaMemcpyHostToDevice);

    // Define the dimention of block and grid
    dim3 gridDim((Y + BLOCK_SIZE_X - 1) / BLOCK_SIZE_X, (X + BLOCK_SIZE_Y - 1) / BLOCK_SIZE_Y, 1);
    dim3 blockDim(BLOCK_SIZE_X, BLOCK_SIZE_Y, 1);

    applyPadding<<<gridDim, blockDim>>>(d_matrix, d_paddedMatrix, Y, X, PADDING_SIZE_X);

    cudaMemcpy(paddedMatrix, d_paddedMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int), cudaMemcpyDeviceToHost);

    // Print matrix with padding
    printf("\nWith Padding:\n");
    //you have to add the padding size to the for
    for (int i = 0; i < X + PADDING_SIZE_X; ++i) {
        for (int j = 0; j < Y ; ++j) {
            printf("%d\t", paddedMatrix[i][j]);
        }
        printf("\n");
    }

    cudaMemcpy(d_padMatrix, paddedMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int), cudaMemcpyHostToDevice);

    sumColumns<<<gridDim, blockDim>>>(d_padMatrix, d_resultSum, Y, X + PADDING_SIZE_X);

    cudaMemcpy(result, d_resultSum, Y * sizeof(int), cudaMemcpyDeviceToHost);

    // Print Sum's
    printf("\nColumn Sums:\n");
    for (int j = 0; j < Y; ++j) {
        printf("%d\t", result[j]);
    }
    printf("\n");

    //Free memory from all the variables of the GPU
    cudaFree(d_matrix);
    cudaFree(d_paddedMatrix);
    cudaFree(d_padMatrix);
    cudaFree(d_resultSum);

    return 0;
}
```

## Explicación del codigo 

Primero se llaman las librerias necesarias 

```c++
#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
```

ahora hay que definir las variables para el tamanio de la matriz y el tamanio del padding
```c++
#define X 5
#define Y 5
#define PADDING_SIZE_X 1

#define BLOCK_SIZE_X 16
#define BLOCK_SIZE_Y 16
```

### los kernels

se toma la matriz y se le agrega un padding (o relleno de `0` como lo quiera ver xD) y este se ejecuta de manera paralela para
cada columna de la matriz
```c++
__global__ void applyPadding(int *matrix, int *paddedMatrix, int width, int height, int paddingX) {
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;
    unsigned int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row  < height) {
        paddedMatrix[row * (width + paddingX) + col + paddingX] = matrix[row * width + col];
    }
}
```

este kernel suma las columnas de la matriz y almacena el resultado en `result` igual que el anterior kernel se ejecuta en 
paralelo con cada columna de la matriz (joder estoy escribiendo matriz muchas veces ;-;)
```c++
__global__ void sumColumns(int *matrix, int *result, int width, int height) {
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (col < width) {
        int sum = 0;
        for (int row = 0; row < height; ++row) {
            sum += matrix[(row) * width + col];
        }
        result[col] = sum;
    }
}
```

### en el main 

se crea la matriz original donde se llenara con valores aleatorios y se imprime una vez llena con los valores 
aleatorios, se definin los punteros `d_matrix`, `d_paddedMatrix`, `d_padMatrix` y `d_resultSum` los primeros 3 para las 
matrices y el ultimo es para el resultado
```c++
    int *d_matrix, *d_paddedMatrix, *d_padMatrix, *d_resultSum;
```

luego se le asigana memoria a la gpu para pasar los datos de las matrices desde la cpu a la gpu
```c++
    cudaMalloc((void **)&d_matrix, X * Y * sizeof(int));
    cudaMalloc((void **)&d_paddedMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int));

    cudaMalloc((void **)&d_padMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int));
    cudaMalloc((void **)&d_resultSum, Y * sizeof(int));
```

se definen las dimensiones de los bloques y la cuaddricual para llamar a los kernels 
```c++
    dim3 gridDim((Y + BLOCK_SIZE_X - 1) / BLOCK_SIZE_X, (X + BLOCK_SIZE_Y - 1) / BLOCK_SIZE_Y, 1);
    dim3 blockDim(BLOCK_SIZE_X, BLOCK_SIZE_Y, 1);
```

se llama el primer kernel `applyPadding` para darle los valores de la matriz original y luego se jalan los valores de regreso
```c++
    applyPadding<<<gridDim, blockDim>>>(d_matrix, d_paddedMatrix, Y, X, PADDING_SIZE_X);

    cudaMemcpy(paddedMatrix, d_paddedMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int), cudaMemcpyDeviceToHost);
```

se imprime el padding
```c++
    printf("\nWith Padding:\n");
    for (int i = 0; i < X + PADDING_SIZE_X; ++i) {
        for (int j = 0; j < Y ; ++j) {
            printf("%d\t", paddedMatrix[i][j]);
        }
        printf("\n");
    }
```

ahora se llama el segundo kernel `sumColumns` para hacer la suma de las columnas de la matriz y tambien se jalan los valores de
regreso 
```c++
    cudaMemcpy(d_padMatrix, paddedMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int), cudaMemcpyHostToDevice);

    sumColumns<<<gridDim, blockDim>>>(d_padMatrix, d_resultSum, Y, X + PADDING_SIZE_X);
```

y se imrimen los resultados de la suma 
```c++
    printf("\nColumn Sums:\n");
    for (int j = 0; j < Y; ++j) {
        printf("%d\t", result[j]);
    }
    printf("\n");
```

y pues se libera la memoria
```c++
    cudaFree(d_matrix);
    cudaFree(d_paddedMatrix);
    cudaFree(d_padMatrix);
    cudaFree(d_resultSum);
```
