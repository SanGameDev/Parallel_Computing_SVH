# Examen

Ya no se que poner aqui, tons le dejo un `^*^`
---
### Reporte 9  sumMatrixGPUManual
Igual que en el otro voy a dejar solo con el código y los valores del análisis todos los que ya se hayan repetido =,,,D  **x4**

Se realizaron un total de 4 operaciones en la GPU y es la siguiente:

-   [CUDA memcpy HtoD]:
    > La linea 147/148 Se llamo 2 veces, con un tiempo promedio de ejecución de  **13.550ms**  y le tomo un total de  **65.52%**  del tiempo total de las operaciones de la GPU.

-   [CUDA memcpy DtoH]:
    > Las linea 158 Se llamo 1 vez, con un tiempo promedio de ejecución de  **12.669ms**  y le tomo un total de  **30.63%**  del tiempo total de las operaciones de la GPU.

- sumMatrixGPU(float*, float*, float*, int, int):
	> En las lineas 67/78, 143 y 151 Se llamo 2 veces con un tiempo promedio de ejecución de **555.89us** y le tomo un total de **2.69%** del tiempo total de las operaciones de la GPU.

-   [CUDA memset]:
    > En las lineas 141 y 142 Se llamo 4 veces, con un tiempo promedio de ejecución de  **239.71us**  y le tomo un total de  **1.16%**  del tiempo total de las operaciones de la GPU.

---

Se realizaron un total de 17 operaciones con las funciones de la API de CUDA

- cudaMalloc: 
	> En las lineas 129/131 Se llamo 3 veces con un tiempo de ejecución de **202.39ms** y le tomo un total de **87.57%** del tiempo total de las operaciones con la API.

- cudaMemcpy:
	> En las lineas 147/148 y 158 Se llamo 3 veces con un tiempo de ejecución de **15.013ms** y le tomo un total de **6.50%** del tiempo total de las operaciones con la API.

- cudaDeviceReset:
	> En la linea 178 Se llamo 1 vez con un tiempo de ejecución de **36.474ms** y le tomo un total de **5.26%** del tiempo total de las operaciones con la API.

- cuDeviceGetPCIBusId:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **2.2576ms** y le tomo un total de **0.33%** del tiempo total de las operaciones de la API.

- cudaFree:
	> En las lineas 167/169 Se llamo 3 veces con un tiempo de ejecución de **441.87us** y le tomo un total de **0.19%** del tiempo total de las operaciones con la API.

-   cudaDeviceSynchronize:
    > En la linea 153 Se llamo 1 vez con un tiempo de ejecución de  **929.30us**  y le tomo un total de  **0.13%**  del tiempo total de las operaciones con la API.

- cudaMemset:
	> En las lineas 141/142 Se llamo 2 veces con un tiempo de ejecución de **31.350us** y le tomo un total de **0.01%** del tiempo total de las operaciones con la API.

- cudaLaunchKernel:
	> Se llamo 2 veces con un tiempo de ejecución de **31.250us** y le tomo un total de **0.01%** del tiempo total de las operaciones con la API.

- cuDeviceGetAttribute:
	> Se llamo 101 veces con un tiempo promedio de ejecución de **154ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **7.3000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties:
	> En la linea 87 Se llamo 1 vez, con un tiempo promedio de ejecución de **7.1000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

-   cuDeviceGetCount:
    > Se llamo 3 veces, con un tiempo promedio de ejecución de  **433ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGetName:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **1.1000us**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGet:
    > Se llamo 2 veces, con un tiempo promedio de ejecución de  **500ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cudaGetLastError:
    > Se llamo 1 vez con un tiempo de ejecución de  **700ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones con la API.
    
-   cuDeviceTotalMem:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **300ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceGetUuid:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **200ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
