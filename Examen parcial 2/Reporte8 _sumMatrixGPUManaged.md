# Examen

Ya no se que poner aqui, tons le dejo un `^*^`
---
### Reporte 8  sumMatrixGPUManaged
Igual que en el otro voy a dejar solo con el código y los valores del análisis todos los que ya se hayan repetido =,,,D  **x4**

Se realizaron un total de 1 `0.o` operacion en la GPU y es la siguiente:

- sumMatrixGPU(float*, float*, float*, int, int):
	> En las lineas 72/83 y 139 
	``__global__ void sumMatrixGPU(float *MatA, float *MatB, float *MatC, int nx, int ny) { unsigned  int ix = threadIdx.x + blockIdx.x * blockDim.x; unsigned  int iy = threadIdx.y + blockIdx.y * blockDim.y; unsigned  int idx = iy * nx + ix; if (ix < nx && iy < ny) { MatC[idx] = MatA[idx] + MatB[idx]; } }``
``sumMatrixGPU<<<grid, block>>>(A, B, gpuRef, 1, 1);``
este kernel se ejecuta igual que los de los otros códigos en la GPU, este toma 3 matrices siendo `MatA`, `MatB`, `MatC` y las dimensiones `nx` y `ny`, se suman los elementos de `MatA` y `MatB` y almacena el resultado en `MatC`. Los índices `ix` e `iy` se calculan a partir de los hilos y bloques en la cuadrícula, y se utiliza `idx` para acceder a los elementos de las matrices. Se llamo 2 veces con un tiempo promedio de ejecución de **6.4741ms** y le tomo un total de **100.00%** del tiempo total de las operaciones de la GPU.

---

Se realizaron un total de 15 operaciones con las funciones de la API de CUDA

- cudaMallocManaged:
	> En las lineas 110/113
``CHECK(cudaMallocManaged((void **)&A, nBytes));`` ``CHECK(cudaMallocManaged((void **)&B, nBytes));`` ``CHECK(cudaMallocManaged((void **)&gpuRef, nBytes));`` ``CHECK(cudaMallocManaged((void **)&hostRef, nBytes));``
este asigna la memoria y devuelve un puntero que puede ser utilizado tanto en la CPU como en la GPU sin necesidad de transferencias manuales de datos entre los dos, asi las variables `A`, `B`, `gpuRef` y `hostRef` se asignan con memoria manejada de esta manera. Se llamo 4 veces, con un tiempo de ejecución de **203.85ms** y le tomo un total de **91.39%** del tiempo total de las operaciones con la API.

- cudaDeviceReset:
	> En la linea 164 Se llamo 1 vez con un tiempo de ejecución de **30.801ms** y le tomo un total de **3.45%** del tiempo total de las operaciones con la API.

- cudaFree:
	> En las lineas 158/161 y 182 Se llamo 4 veces con un tiempo de ejecución de **7.3922ms** y le tomo un total de **3.31%** del tiempo total de las operaciones con la API.

-   cudaDeviceSynchronize:
    > En la linea 146 Se llamo 1 vez con un tiempo de ejecución de  **2.1681ms**  y le tomo un total de  **1.52%**  del tiempo total de las operaciones con la API.

- cuDeviceGetPCIBusId:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **2.1756ms** y le tomo un total de **0.24%** del tiempo total de las operaciones de la API.

- cudaLaunchKernel:
	> Se llamo 2 veces con un tiempo de ejecución de **322.10us** y le tomo un total de **0.07%** del tiempo total de las operaciones con la API.

- cuDeviceGetAttribute:
	> Se llamo 101 veces con un tiempo promedio de ejecución de **139ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **5.8000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties:
	> En la linea 92 ``CHECK(cudaGetDeviceProperties(&deviceProp, dev));``
	en este aparte de darle el indice en 0 como los otros se le pasa un puntero para que lo llene con la información sobre la GPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **4.0000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

-   cuDeviceGetCount:
    > Se llamo 3 veces, con un tiempo promedio de ejecución de  **400ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGet:
    > Se llamo 2 veces, con un tiempo promedio de ejecución de  **550ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cudaGetLastError:
    > Se llamo 1 vez con un tiempo de ejecución de  **900ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones con la API.

-   cuDeviceGetName:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **700ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceTotalMem:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **300ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceGetUuid:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **200ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
