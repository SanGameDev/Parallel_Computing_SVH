# Examen

Y según yo se terminaba temprano esto x,D 
---
### Reporte 10  transpose
Igual que en el otro voy a dejar solo con el código y los valores del análisis todos los que ya se hayan repetido =,,,,D  **x5**

Se realizaron un total de 3 operaciones en la GPU y es la siguiente:

-   [CUDA memcpy HtoD]:
    > La linea 147/148 Se llamo 2 veces, con un tiempo promedio de ejecución de  **13.550ms**  y le tomo un total de  **65.52%**  del tiempo total de las operaciones de la GPU.

- copyRow(float*, float*, int, int):
	> En las lineas 80/89 y 321
	``__global__ void  copyRow(float *out, float *in, const int nx, const int ny) { unsigned  int ix = blockDim.x * blockIdx.x + threadIdx.x; unsigned  int iy = blockDim.y * blockIdx.y + threadIdx.y; if (ix < nx && iy < ny) { out[iy * nx + ix] = in[iy * nx + ix]; } }``
	lo que hace es copiar datos de una matriz de entrada `in` a una matriz de salida `out` utilizando un patrón de acceso por filas. Se llamo 1 vez, con un tiempo promedio de ejecución de  **151.49us**  y le tomo un total de  **6.62%**  del tiempo total de las operaciones de la GPU.

- warmup(float*, float*, int, int):
	> 68/77 y 263 Se llamo 1 vez, con un tiempo promedio de ejecución de  **150.02us**  y le tomo un total de  **6.56%**  del tiempo total de las operaciones de la GPU.
	
---

Se realizaron un total de 16 operaciones con las funciones de la API de CUDA

- cudaMalloc: 
	> En las lineas 255/256 Se llamo 2 veces con un tiempo de ejecución de **317.05ms** y le tomo un total de **86.44%** del tiempo total de las operaciones con la API.

- cudaDeviceReset:
	> En la linea 347 Se llamo 1 vez con un tiempo de ejecución de **93.791ms** y le tomo un total de **12.79%** del tiempo total de las operaciones con la API.

- cudaMemcpy:
	> En la linea 259 Se llamo 1 vez con un tiempo de ejecución de **2.3634ms** y le tomo un total de **0.32%** del tiempo total de las operaciones con la API.

- cuDeviceGetPCIBusId:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **2.2569ms** y le tomo un total de **0.31%** del tiempo total de las operaciones de la API.

- cudaFree:
	> En las lineas 340/341 Se llamo 2 veces con un tiempo de ejecución de **274.90us** y le tomo un total de **0.07%** del tiempo total de las operaciones con la API.

-   cudaDeviceSynchronize:
    > En las lineas 264 y 322 Se llamo 2 veces con un tiempo de ejecución de  **202.25us**  y le tomo un total de  **0.06%**  del tiempo total de las operaciones con la API.

- cudaLaunchKernel:
	> Se llamo 2 veces con un tiempo de ejecución de **28.500us** y le tomo un total de **0.01%** del tiempo total de las operaciones con la API.

- cuDeviceGetAttribute:
	> Se llamo 101 veces con un tiempo promedio de ejecución de **163ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **5.4000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties:
	> En la linea 211 Se llamo 1 vez, con un tiempo promedio de ejecución de **5.0000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

-   cuDeviceGetCount:
    > Se llamo 3 veces, con un tiempo promedio de ejecución de  **466ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cudaGetLastError:
    > Se llamo 2 veces con un tiempo de ejecución de  **650ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones con la API.

-   cuDeviceGet:
    > Se llamo 2 veces, con un tiempo promedio de ejecución de  **500ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGetName:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **600ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceTotalMem:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **400ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceGetUuid:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **200ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
