# Examen

Ya es musho profe ;-; kiero un pan
---
### Reporte 5  simpleMathAoS
Igual que en el otro voy a dejar solo con el código y los valores del análisis todos los que ya se hayan repetido =,D 

Se realizaron un total de 4 operaciones en la GPU y son las siguientes:

- [CUDA memcpy DtoH]:
	> Las lineas 148 y 159 Se llamo 2 veces, con un tiempo promedio de ejecución de **11.652ms** y le tomo un total de **80.19%** del tiempo total de las operaciones de la GPU.

- [CUDA memcpy HtoD]:
	> La linea 130 Se llamo 1 vez, con un tiempo promedio de ejecución de **5.2457ms** y le tomo un total de **18.05%** del tiempo total de las operaciones de la GPU.

- warmup(innerStruct*, innerStruct*, int):
	> Las lineas 90/101 y 143 Se llamo 1 vez, con un tiempo promedio de ejecución de **256.10us** y le tomo un total de **0.88%** del tiempo total de las operaciones de la GPU.

- testInnerStruct(innerStruct*, innerStruct*, int):
	> Las lineas 76/88 y 154 Se llamo 1 vez, con un tiempo promedio de ejecución de **255.85us** y le tomo un total de **0.88%** del tiempo total de las operaciones de la GPU.

---

Se realizaron un total de 16 operaciones con las funciones de la API de CUDA

- cudaMalloc:
	> En las lineas 126/127 Se llamo 2 veces, con un tiempo de ejecución de **283.19ms** y le tomo un total de **88.83%** del tiempo total de las operaciones con la API.

- cudaDeviceReset:
	> En la linea 171 Se llamo 1 vez con un tiempo de ejecución de **35.742ms** y le tomo un total de **5.61%** del tiempo total de las operaciones con la API.

- cudaMemcpy:
	> En las lineas 130, 148 y 159 Se llamo 3 veces con un tiempo de ejecución de **10.422ms** y le tomo un total de **4.90%** del tiempo total de las operaciones con la API.

- cuDeviceGetPCIBusId:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **2.1562ms** y le tomo un total de **0.34%** del tiempo total de las operaciones de la API.

- cudaFree:
	> En las lineas 164/165 Se llamo 2 veces con un tiempo de ejecución de **610.00us** y le tomo un total de **0.19%** del tiempo total de las operaciones con la API.

- cudaDeviceSynchronize:
	> En las lineas 144 y 155 Se llamo 2 veces con un tiempo de ejecución de **334.95us** y le tomo un total de **0.11%** del tiempo total de las operaciones con la API.

- cudaLaunchKernel:
	> Se llamo 2 veces con un tiempo de ejecución de **80.800us** y le tomo un total de **0.03%** del tiempo total de las operaciones con la API.

- cuDeviceGetAttribute:
	> Se llamo 101 veces con un tiempo promedio de ejecución de **144ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **6.1000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetLastError:
	> Se llamo 2 veces con un tiempo de ejecución de **2.9000us** y le tomo un total de **0.00%** del tiempo total de las operaciones con la API.

- cudaGetDeviceProperties:
	> En la linea 108 Se llamo 1 vez, con un tiempo promedio de ejecución de **4.7000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

-   cuDeviceGetCount:
    > Se llamo 3 veces, con un tiempo promedio de ejecución de  **466ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGet:
    > Se llamo 2 veces, con un tiempo promedio de ejecución de  **400ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceGetName:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **600ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceTotalMem:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **400ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceGetUuid:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **200ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
