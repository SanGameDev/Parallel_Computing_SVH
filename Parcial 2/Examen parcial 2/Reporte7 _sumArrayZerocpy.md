# Examen

Pus uno no es ninguno y dos es uno xD 
---
### Reporte 7  sumArrayZerocpy
Igual que en el otro voy a dejar solo con el código y los valores del análisis todos los que ya se hayan repetido =,,D  **x3**

Se realizaron un total de 4 operaciones en la GPU y son las siguientes:

- sumArraysZeroCopy(float*, float*, float*, int):
	> Las lineas 60/65 y 173 
	``__global__ void sumArraysZeroCopy(float *A, float *B, float *C, const int N) { int i = blockIdx.x * blockDim.x + threadIdx.x; if (i < N) C[i] = A[i] + B[i]; }``
	``sumArraysZeroCopy<<<grid, block>>>(d_A, d_B, d_C, nElem);``
	 este kernel se encarga de tomar tres arreglos de de tipo float `A`, `B` y `C` y la longitud que es `N`, donde sumara elemento por elemento los valores de `A` y `B` y estos se almacenaran en `C`. Se llamo 1 vez, con un tiempo promedio de ejecución de **3.5200us** y le tomo un total de **33.33%** del tiempo total de las operaciones de la GPU.

- [CUDA memcpy DtoH]:
	> Las lineas 141 y 176 Se llamo 2 veces, con un tiempo promedio de ejecución de **1.2000us** y le tomo un total de **22.73%** del tiempo total de las operaciones de la GPU.

- sumArrays(float*, float*, float*, int):
	> Lineas 53/58 y 138 
	``__global__ void  sumArrays(float  *A, float  *B, float  *C, const  int N) { int i = blockIdx.x * blockDim.x + threadIdx.x; if (i < N) C[i] = A[i] + B[i];}``
	``sumArrays<<<grid, block>>>(d_A, d_B, d_C, nElem);``
	este es muy similar a el `sumArraysZeroCopy(float*, float*, float*, int)` 
	donde se suman varios elementos y se almacenan en otro =D. Se llamo 1 vez, con un tiempo promedio de ejecución de **2.3360us** y le tomo un total de **22.12%** del tiempo total de las operaciones de la GPU.

- [CUDA memcpy HtoD]:
	> La linea 130/131 Se llamo 2 veces, con un tiempo promedio de ejecución de **1.1520us** y le tomo un total de **21.82%** del tiempo total de las operaciones de la GPU.
	
---

Se realizaron un total de 17 operaciones con las funciones de la API de CUDA

- cudaMalloc:
	> En las lineas 125/127 Se llamo 3 veces, con un tiempo de ejecución de **194.38ms** y le tomo un total de **94.24%** del tiempo total de las operaciones con la API.

- cudaDeviceReset:
	> En la linea 190 Se llamo 1 vez con un tiempo de ejecución de **31.475ms** y le tomo un total de **5.09%** del tiempo total de las operaciones con la API.

- cuDeviceGetPCIBusId:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **2.1756ms** y le tomo un total de **0.35%** del tiempo total de las operaciones de la API.

- cudaHostAlloc:
	> Lineas 156/157 
	``CHECK(cudaHostAlloc((void **)&h_A, nBytes, cudaHostAllocMapped));`` 
	``CHECK(cudaHostAlloc((void **)&h_B, nBytes, cudaHostAllocMapped));``
	este se usa para asignar memoria mapeada (memoria asignada en la RAM y se hace accesible para la GPU de manera directa) para los arreglos `h_A` y `h_B` así ya no se necesita transferir datos a través del busPCIe para que ambos GPU y CPU accedan a estos. Se llamo 2 veces, con un tiempo de ejecución de **494.30us** y le tomo un total de **0.16%** del tiempo total de las operaciones con la API.

- cudaFreeHost:
	> Lineas 183/184 
	``CHECK(cudaFreeHost(h_A));``
	``CHECK(cudaFreeHost(h_B));``
	este libera la memoria mapeada por ``cudaHostAlloc`` de los punteros `h_A` y `h_B` Se llamo 2 veces, con un tiempo de ejecución de **184.45us** y le tomo un total de **0.06%** del tiempo total de las operaciones con la API.

- cudaMemcpy:
	> En las lineas 130/131, 141 y 176 Se llamo 4 veces con un tiempo de ejecución de **89.500us** y le tomo un total de **0.06%** del tiempo total de las operaciones con la API.

- cudaFree:
	> En las lineas 147/148 y 182 Se llamo 3 veces con un tiempo de ejecución de **72.733us** y le tomo un total de **0.04%** del tiempo total de las operaciones con la API.

- cudaLaunchKernel:
	> Se llamo 2 veces con un tiempo de ejecución de **30.150us** y le tomo un total de **0.01%** del tiempo total de las operaciones con la API.

- cuDeviceGetAttribute:
	> Se llamo 101 veces con un tiempo promedio de ejecución de **147ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **6.2000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties:
	> En la linea 75 Se llamo 1 vez, con un tiempo promedio de ejecución de **2.3000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaHostGetDevicePointer:
	> Lineas 166/167 
	``CHECK(cudaHostGetDevicePointer((void **)&d_A, (void *)h_A, 0));`` ``CHECK(cudaHostGetDevicePointer((void **)&d_B, (void *)h_B, 0));``
	se usa para obtener punteros de dispositivo `d_A` y `d_B` que apuntan a las direcciones de memoria mapeada en host correspondientes. Se llamo 2 veces con un tiempo de ejecución de **1.0500us** y le tomo un total de **0.00%** del tiempo total de las operaciones con la API.

-   cuDeviceGetCount:
    > Se llamo 3 veces, con un tiempo promedio de ejecución de  **533ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGet:
    > Se llamo 2 veces, con un tiempo promedio de ejecución de  **550ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGetName:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **700ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceTotalMem:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **300ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceGetUuid:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **200ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
