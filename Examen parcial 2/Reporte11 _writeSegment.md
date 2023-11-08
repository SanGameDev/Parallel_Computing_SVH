# Examen

EL ULTIMOOOOO SIUUUUUUUUUUUUUUUU
---
### Reporte 11  writeSegment
Igual que en el otro voy a dejar solo con el código y los valores del análisis todos los que ya se hayan repetido =,,,,D  **x666** 

Se realizaron un total de 6 (a su madre son un shingo) operaciones en la GPU y es la siguiente:

-   [CUDA memcpy DtoH]:
    > En las lineas 161, 174 y 187  Se llamo 3 veces, con un tiempo promedio de ejecución de  **704.29us**  y le tomo un total de  **65.98%**  del tiempo total de las operaciones de la GPU.

-   [CUDA memcpy HtoD]:
    > La linea 139/140 Se llamo 2 veces, con un tiempo promedio de ejecución de  **470.12us**  y le tomo un total de  **29.36%**  del tiempo total de las operaciones de la GPU.

- writeOffset(float*, float*, float*, int, int):
	> En las lineas 47/54 y 153 
	``__global__ void writeOffset(float *A, float *B, float *C, const int n, int offset) { unsigned  int i = blockIdx.x * blockDim.x + threadIdx.x; unsigned  int k = i + offset; if (k < n) { C[k] = A[i] + B[i]; } }``
	``writeOffset<<<grid, block>>>(d_A, d_B, d_C, nElem, offset);``
	en este kernel toma dos matrices de entrada, realiza una suma entre los elementos de las matrices `A` y `B`, y almacena el resultado en la matriz `C`. La adición se realiza con un desplazamiento especificado por `offset`. Se llamo 1 vez, con un tiempo promedio de ejecución de  **49.504us**  y le tomo un total de  **1.55%**  del tiempo total de las operaciones de la GPU.

- warmup(float*, float*, int, int):
	> En las lineas 56/62 y 144 Se llamo 1 vez, con un tiempo promedio de ejecución de  **47.712us**  y le tomo un total de  **1.49%**  del tiempo total de las operaciones de la GPU.

-   readOffsetUnroll2(float*, float*, float*, int, int):
    > En las lineas 64/75 y 166  Se llamo 1 vez, con un tiempo promedio de ejecución de  **29.120us**  y le tomo un total de  **0.91%**  del tiempo total de las operaciones de la GPU.

-   readOffsetUnroll4(float*, float*, float*, int, int):
    > De las lineas 77/90 y la linea 179  Se llamo 1 vez, con un tiempo promedio de ejecución de  **23.072us**  y le tomo un total de  **0.72%**  del tiempo total de las operaciones de la GPU.
	
---

Se realizaron un total de 16 operaciones con las funciones de la API de CUDA

- cudaMalloc: 
	> En las lineas 134/136 Se llamo 3 veces con un tiempo de ejecución de **193.08ms** y le tomo un total de **92.61%** del tiempo total de las operaciones con la API.

- cudaDeviceReset:
	> En la linea 198 Se llamo 1 vez con un tiempo de ejecución de **37.576ms** y le tomo un total de **6.01%** del tiempo total de las operaciones con la API.

- cudaMemcpy:
	> En las lineas 139/140, 161, 174 y 187 Se llamo 5 veces con un tiempo de ejecución de **1.0360ms** y le tomo un total de **0.83%** del tiempo total de las operaciones con la API.

- cuDeviceGetPCIBusId:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **2.1550ms** y le tomo un total de **0.34%** del tiempo total de las operaciones de la API.

- cudaFree:
	> En las lineas 191/193 Se llamo 3 veces con un tiempo de ejecución de **229.17us** y le tomo un total de **0.11%** del tiempo total de las operaciones con la API.

-   cudaDeviceSynchronize:
    > En las lineas 145, 154, 167 y 180 Se llamo 4 veces con un tiempo de ejecución de  **99.750us**  y le tomo un total de  **0.06%**  del tiempo total de las operaciones con la API.

- cudaLaunchKernel:
	> Se llamo 4 veces con un tiempo de ejecución de **56.400us** y le tomo un total de **0.04%** del tiempo total de las operaciones con la API.

- cuDeviceGetAttribute:
	> Se llamo 101 veces con un tiempo promedio de ejecución de **142ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties:
	> En la linea 97 Se llamo 1 vez, con un tiempo promedio de ejecución de **4.9000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **4.1000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

-   cudaGetLastError:
    > Se llamo 4 veces con un tiempo de ejecución de  **825ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones con la API.

-   cuDeviceGetCount:
    > Se llamo 3 veces, con un tiempo promedio de ejecución de  **400ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGet:
    > Se llamo 2 veces, con un tiempo promedio de ejecución de  **550ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGetName:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **700ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceTotalMem:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **300ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceGetUuid:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **100ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
