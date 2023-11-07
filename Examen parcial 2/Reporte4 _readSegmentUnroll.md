# Examen

AYUDAAAAAAAAAAAAAA
---
### Reporte 4  readSegmentUnroll

Se realizaron un total de 7 operaciones en la GPU y son las siguientes:

- [CUDA memcpy DtoH]: 
	> En las lineas 166, 180 y 194
	``CHECK(cudaMemcpy(gpuRef, d_C, nBytes, cudaMemcpyDeviceToHost));
	``CHECK(cudaMemcpy(gpuRef, d_C, nBytes, cudaMemcpyDeviceToHost));``
	``CHECK(cudaMemcpy(gpuRef, d_C, nBytes, cudaMemcpyDeviceToHost));``
	se encarga de la transferencia de los datos de la GPU (que es el arreglo de `d_C`) y los manda a la CPU (que es el arreglo de `gpuRef`), `nbytes` se encarga igual de indicarle la cantidad de bytes necesarios para almacenar los datos y `cudaMemcpyDeviceToHost` se encarga de indicar que se esta realizando una copia de el dispositivo al host (GPU al CPU), esto se hace para transferir los resultados de las operaciones realizadas en la GPU a la CPU. Se llamo 3 veces, con un tiempo promedio de ejecución de **689.07us** y le tomo un total de **64.13%** del tiempo total de las operaciones de la GPU.

- [CUDA memcpy HtoD]:
	> En las lineas 143/144 
	``CHECK(cudaMemcpy(d_A, h_A, nBytes, cudaMemcpyHostToDevice));``
	``CHECK(cudaMemcpy(d_B, h_A, nBytes, cudaMemcpyHostToDevice));``
	se encarga de copiar los datos desde el CPU a la GPU desde el puntero `h_A` hacia los punteros `d_A` y `d_B` y ya se sabe el resto al igual que yo. Se llamo 2 veces, con un tiempo promedio de ejecución de **447.83us** y le tomo un total de **27.79%** del tiempo total de las operaciones de la GPU.

- [CUDA memset]:
	> En las lineas 154, 168, 182 y 196 
	``CHECK(cudaMemset(d_C, 0x00, nBytes));``
	se usa para llenar el dispositivo de memoria `d_C` con el valor de`0x00` en un número de bytes `nBytes`, en el código se usa para inicializar en ceros la memoria de la GPU apuntada por `d_C` antes de que se hagan las operaciones para que no se vean afectadas unas por otras =D. Se llamo 4 veces, con un tiempo promedio de ejecución de **15.648us** y le tomo un total de **1.94%** del tiempo total de las operaciones de la GPU.

- readOffsetUnroll4(float*, float*, float*, int, int):
	> De las lineas 78/94 y la linea 186
	``__global__ void readOffsetUnroll4(float *A, float *B, float *C, const int n, int offset) { unsigned  int i = blockIdx.x * blockDim.x * 4 + threadIdx.x; unsigned  int k = i + offset; if (k < n) C[i] = A[k] + B[k]; if (k + blockDim.x < n) { C[i + blockDim.x] = A[k + blockDim.x] + B[k + blockDim.x]; } if (k + 2 * blockDim.x < n) { C[i + 2 * blockDim.x] = A[k + 2 * blockDim.x] + B[k + 2 * blockDim.x]; } if (k + 3 * blockDim.x < n) { C[i + 3 * blockDim.x] = A[k + 3 * blockDim.x] + B[k + 3 * blockDim.x]; } }``
	``readOffsetUnroll4<<<grid.x / 4, block>>>(d_A, d_B, d_C, nElem, offset);``
	donde es un kernel que toma 3 punteros `A`, `B`, `C`, 1 entero `n` y otro entero `offset`, este kernel hace una operacion de suma en paralelo con los vectores `A` y `B` con un desplazamiento que es indicado por `offset` y esto se almacena en `C` y el kernel de la linea 186 hace que se realice la operación en la GPU, donde lo que haces es (tuve que pedirle ayuda aeternet para saber que hacia) un desenrollado manual de bucles (es una técnica de optimizan de código que se usa para mejorar el rendimiento de bucles en los programas). Se llamo 1 vez, con un tiempo promedio de ejecución de **50.368us** y le tomo un total de **1.56%** del tiempo total de las operaciones de la GPU.

- readOffset(float*, float*, float*, int, int):
	> De las lineas 57/64 y 158 
	``__global__ void readOffset(float *A, float *B, float *C, const int n, int offset) { unsigned  int i = blockIdx.x * blockDim.x + threadIdx.x; unsigned  int k = i + offset; if (k < n) C[i] = A[k] + B[k]; }``
	``readOffset<<<grid, block>>>(d_A, d_B, d_C, nElem, offset);``
	donde es un kernel que toma 3 punteros `A`, `B`, `C`, 1 entero `n` y otro entero `offset`, este kernel hace una operacion de suma en paralelo con los vectores `A` y `B` con un desplasamiento que es indicado por `offset` y esto se almacena en `C` y el kernel de la linea 158 hace que se realize la operacion en la GPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **49.984us** y le tomo un total de **1.55%** del tiempo total de las operaciones de la GPU.

- readOffsetUnroll2(float*, float*, float*, int, int):
	> En las lineas 66/78 y 172 ``__global__ void readOffsetUnroll2(float *A, float *B, float *C, const int n, int offset) { unsigned  int i = blockIdx.x * blockDim.x * 2 + threadIdx.x; unsigned  int k = i + offset; if (k < n) C[i] = A[k] + B[k]; if (k + blockDim.x < n) { C[i + blockDim.x] = A[k + blockDim.x] + B[k + blockDim.x]; } }``
	``readOffsetUnroll2<<<grid.x/2, block>>>(d_A, d_B, d_C, nElem, offset);``
	este se trabaja igual que el ``readOffsetUnroll4(float*, float*, float*, int, int)`` que sirve para optimizar el código el reducir la sobrecarga del bucle, mejora el acceso a la memoria, hace la paralelización mas eficiente  y reduce la latencia de instrucciones. Se llamo 1 vez, con un tiempo promedio de ejecución de **49.632us** y le tomo un total de **1.54%** del tiempo total de las operaciones de la GPU.
	
- warmup(float*, float*, float*, int, int):
	> De las lineas 49/55 y 148
	``__global__ void warmup(float *A, float *B, float *C, const int n, int offset) { unsigned  int i = blockIdx.x * blockDim.x + threadIdx.x; unsigned  int k = i + offset; if (k < n) C[i] = A[k] + B[k]; }``
	``warmup<<<grid, block>>>(d_A, d_B, d_C, nElem, offset);``
	en esta definición de kernel se toman igual 3 punteros `A`, `B`, `C`, 1 entero `n` y otro entero `offset` este kernel hace una operacion de suma en paralelo con los vectores `A` y `B` con un desplasamiento que es indicado por `offset` y esto se almacena en `C` y el kernel de la linea 148 hace que se realize la operacion en la GPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **47.904us** y le tomo un total de **1.49%** del tiempo total de las operaciones de la GPU.
	
---
Se realizaron un total de 17 operaciones con las funciones de la API de CUDA

Profe de las funciones que sean lo mismo que en los pasados análisis voy a poner únicamente el código y los valores de el análisis para agilizar esto que apenas voy en el 4 y faltan unas horas pa su clase ;=;

- cudaMalloc: 
	> En las lineas 137/140 
	``float *d_A, *d_B, *d_C;``
``CHECK(cudaMalloc((float**)&d_A, nBytes)); CHECK(cudaMalloc((float**)&d_B, nBytes)); CHECK(cudaMalloc((float**)&d_C, nBytes));`` 
	Se llamo 3 veces, con un tiempo promedio de ejecución de **197.49ms** y le tomo un total de **93.30%** del tiempo total de las operaciones con la API. 

- cudaDeviceReset:
	> En la linea 206 ``CHECK(cudaDeviceReset());`` Se llamo 1 vez, con un tiempo promedio de ejecución de **34.676ms** y le tomo un total de **5.46%** del tiempo total de las operaciones de la API.

- cudaMemcpy:
	> En las lienas 143/144, 166, 180 y 194 
	``CHECK(cudaMemcpy(d_A, h_A, nBytes, cudaMemcpyHostToDevice)); CHECK(cudaMemcpy(d_B, h_A, nBytes, cudaMemcpyHostToDevice));``
	``CHECK(cudaMemcpy(gpuRef, d_C, nBytes, cudaMemcpyDeviceToHost));``
	``CHECK(cudaMemcpy(gpuRef, d_C, nBytes, cudaMemcpyDeviceToHost));``
	``CHECK(cudaMemcpy(gpuRef, d_C, nBytes, cudaMemcpyDeviceToHost));``
Se llamo 5 veces, con un tiempo promedio de ejecución de **881.04us** y le tomo un total de **0.69%** del tiempo total de las operaciones con la API. 

- cuDeviceGetPCIBusId:
	>Se llamo 1 vez, con un tiempo promedio de ejecución de **2.0617ms** y le tomo un total de **0.32%** del tiempo total de las operaciones de la API.

- cudaFree:
	> En las lineas 199/201 
``CHECK(cudaFree(d_A));``
``CHECK(cudaFree(d_B));``
``CHECK(cudaFree(d_C));``
Se llamo 3 veces, con un tiempo promedio de ejecución de **249.87us** y le tomo un total de **0.12%** del tiempo total de las operaciones con la API. 

- cudaDeviceSynchronize:
	> En las lineas 149, 159, 173 y 187
	``CHECK(cudaDeviceSynchronize());``
	``CHECK(cudaDeviceSynchronize());``
	``CHECK(cudaDeviceSynchronize());``
	``CHECK(cudaDeviceSynchronize());``
	Se llamo 4 veces, con un tiempo promedio de ejecución de **89.325us** y le tomo un total de **0.06%** del tiempo total de las operaciones con la API. 

- cudaMemset:
	> En las lineas 154, 168, 182 y 196
	``CHECK(cudaMemset(d_C, 0x00, nBytes));``
	``CHECK(cudaMemset(d_C, 0x00, nBytes));``
	``CHECK(cudaMemset(d_C, 0x00, nBytes));``
	``CHECK(cudaMemset(d_C, 0x00, nBytes));``
	(Por que le tomo mas tiempo hacerlo si en los procesos de la GPU es la misma funcion?)
	Se llamo 4 veces, con un tiempo promedio de ejecución de **36.225us** y le tomo un total de **0.02%** del tiempo total de las operaciones con la API. 

- cudaLaunchKernel:
	> Se llamo 4 veces, con un tiempo promedio de ejecución de **22.825us** y le tomo un total de **0.01%** del tiempo total de las operaciones con la API. 

- cuDeviceGetAttribute:
	> Se llamo 101 como siempre veces con un tiempo promedio de ejecución de **144ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties:
	> En la linea 101 `CHECK(cudaGetDeviceProperties(&deviceProp, dev));` Se llamo 1 vez, con un tiempo promedio de ejecución de **6.9000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice: 
	> En la linea 104 `CHECK(cudaSetDevice(dev));` Se llamo 1 vez, con un tiempo promedio de ejecución de **5.7000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetLastError:
	> Se llamo 4 veces, con un tiempo promedio de ejecución de **600ns** y le tomo un total de **0.00%** del tiempo total de las operaciones con la API. 

- cuDeviceGet: 
	> Se llamo 2 veces, con un tiempo promedio de ejecución de **750ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.
	
- cuDeviceGetCount:
	> Se llamo 3 veces, con un tiempo promedio de ejecución de **400ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGetName:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **800ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceTotalMem: 
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **400ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGetUuid: 
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **200ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

