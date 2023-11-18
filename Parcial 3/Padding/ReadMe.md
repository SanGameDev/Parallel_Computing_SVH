# ACTIVITY 1 PARCIAL 3

Programación de paralelismo

**Paul Andres Solis Villanueva**

University of Advanced Technologies

Leonardo Juárez Zucco

17/11/2023

# CUDA C Matrix Padding and Column Sum Example

This CUDA C code demonstrates how to create a matrix of random values, apply padding, and calculate the sum of each column in parallel using NVIDIA's CUDA architecture.

## Prerequisites

Make sure you have a compatible GPU with CUDA support (such as the one used in the code: NVIDIA GTX 970) and the CUDA Toolkit installed on your system.

## Raw Code
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

#define X 5
#define Y 5
#define PADDING_SIZE_X 1
//my gpu has 1664 cuda cores
#define BLOCK_SIZE_X 16
#define BLOCK_SIZE_Y 16

//kernel called from the CPU to the GPU to apply the padding
__global__ void applyPadding(int *matrix, int *paddedMatrix, int width, int height, int paddingX) {
    //Set the values of the index of the blocks and threads to set them on each index
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;
    unsigned int row = blockIdx.y * blockDim.y + threadIdx.y;

    //If the values of the col or row are out of the size of the matrix
    if (col < width && row  < height) {
        //operation to add the padding every time it passes of how many numbers are in the row
        paddedMatrix[row * (width + paddingX) + col + paddingX] = matrix[row * width + col];
    }
}

//kernel called from the CPU to the GPU to add the columns
__global__ void sumColumns(int *matrix, int *result, int width, int height) {
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;

    //function to add the numbers of the same column
    if (col < width) {
        int sum = 0;
        for (int row = 0; row < height; ++row) {
            sum += matrix[(row) * width + col];
        }
        result[col] = sum;
    }
}

int main() {
    //variables that are going to be used in the cpu to print values
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

## Code Explanation
### Kernel Functions

- applyPadding: Applies padding to the input matrix on the GPU.

```cpp
__global__ void applyPadding(int *matrix, int *paddedMatrix, int width, int height, int paddingX)
```
- sumColumns: Calculates the sum of each column on the GPU.
```cpp
__global__ void sumColumns(int *matrix, int *result, int width, int height)
```

## Main Function
- Initializes a matrix with random values and prints the original matrix.
```cpp
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
```

- Allocates GPU memory for necessary variables.
```cpp
cudaMalloc((void **)&d_matrix, X * Y * sizeof(int));
cudaMalloc((void **)&d_paddedMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int));
```

- Copy the matrix to the variable that is going to be sent to the GPU "d_matrix" with size of X*Y.
```cpp
cudaMemcpy(d_matrix, matrix, X * Y * sizeof(int), cudaMemcpyHostToDevice);
```

- Calls the applyPadding kernel on the GPU.
```cpp
applyPadding<<<gridDim, blockDim>>>(d_matrix, d_paddedMatrix, Y, X, PADDING_SIZE_X);
```

- Copies the result of the padded matrix back to the CPU.
```cpp
cudaMemcpy(paddedMatrix, d_paddedMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int), cudaMemcpyDeviceToHost);
```

- Prints the matrix with padding.
```cpp
 for (int i = 0; i < X + PADDING_SIZE_X; ++i) {
        for (int j = 0; j < Y ; ++j) {
            printf("%d\t", paddedMatrix[i][j]);
        }
        printf("\n");
    }
```

- Copies the padded matrix values to the GPU variable.
```cpp
cudaMemcpy(d_padMatrix, paddedMatrix, (X + PADDING_SIZE_X) * Y * sizeof(int), cudaMemcpyHostToDevice);
```

- Calls the sumColumns kernel on the GPU.
```cpp
sumColumns<<<gridDim, blockDim>>>(d_padMatrix, d_resultSum, Y, X + PADDING_SIZE_X);
```

- Copies the result of column sums back to the CPU.
```cpp
cudaMemcpy(result, d_resultSum, Y * sizeof(int), cudaMemcpyDeviceToHost);
```

- Prints the sum of each column.
```cpp
for (int j = 0; j < Y; ++j) {
        printf("%d\t", result[j]);
    }
    printf("\n");
```

- Frees GPU memory.
```cpp
cudaFree(d_matrix);
cudaFree(d_paddedMatrix);
cudaFree(d_padMatrix);
cudaFree(d_resultSum);
```


