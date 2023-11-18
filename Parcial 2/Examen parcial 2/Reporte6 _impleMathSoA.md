# Examen

Chale profe sigo vivo como le hago?
---
### Reporte 6  simpleMathSoA
Igual que en el otro voy a dejar solo con el código y los valores del análisis todos los que ya se hayan repetido =,D  **x2**

Se realizaron un total de 4 operaciones en la GPU y son las siguientes:

- [CUDA memcpy DtoH]:
	> Las lineas 160 y 170 Se llamo 2 veces, con un tiempo promedio de ejecución de **6.1076ms** y le tomo un total de **73.35%** del tiempo total de las operaciones de la GPU.

- [CUDA memcpy HtoD]:
	> La linea 130 Se llamo 1 vez, con un tiempo promedio de ejecución de **3.9265ms** y le tomo un total de **23.58%** del tiempo total de las operaciones de la GPU.

- warmup2(InnerArray*, InnerArray*, int):
	> Las lineas 99/112 y 155 
	``__global__ void warmup2(InnerArray *data, InnerArray * result, const int n) { unsigned  int i = blockIdx.x * blockDim.x + threadIdx.x; if (i < n) { float tmpx = data->x[i]; float tmpy = data->y[i]; tmpx += 10.f; tmpy += 20.f; result->x[i] = tmpx; result->y[i] = tmpy; } }``
	``warmup2<<<grid, block>>>(d_A, d_C, nElem);`` pues es un kernel que hace una operación sencilla que calcula el indice `i` en función de `blockIdx.x`, `threadIdx.x` luego accede a los valores de `x` y `y` de `i` de `data` luego este valor se le incrementa a la `x` 10 y la `y` 20, al final estos valores se almacenan en `result`. Se llamo 1 vez, con un tiempo promedio de ejecución de **256.03us** y le tomo un total de **1.54%** del tiempo total de las operaciones de la GPU.

- testInnerArray(InnerArray*, InnerArray*, int):
	> Las lineas 82/97 y 165, es un kernel que realiza la misma operacion que ``warmup2(InnerArray*, InnerArray*, int)``  Se llamo 1 vez, con un tiempo promedio de ejecución de **256.03us** y le tomo un total de **1.54%** del tiempo total de las operaciones de la GPU.

---

Se realizaron un total de 16 operaciones con las funciones de la API de CUDA

- cudaMalloc:
	> En las lineas 138/139 Se llamo 2 veces, con un tiempo de ejecución de **292.45ms** y le tomo un total de **90.98%** del tiempo total de las operaciones con la API.

- cudaDeviceReset:
	> En la linea 181 Se llamo 1 vez con un tiempo de ejecución de **35.165ms** y le tomo un total de **5.47%** del tiempo total de las operaciones con la API.

- cudaMemcpy:
	> En las lineas 142, 160 y 170 Se llamo 3 veces con un tiempo de ejecución de **6.1881ms** y le tomo un total de **2.89%** del tiempo total de las operaciones con la API.

- cuDeviceGetPCIBusId:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **2.4897ms** y le tomo un total de **0.39%** del tiempo total de las operaciones de la API.

- cudaFree:
	> En las lineas 174/175 Se llamo 2 veces con un tiempo de ejecución de **490.90us** y le tomo un total de **0.15%** del tiempo total de las operaciones con la API.

- cudaDeviceSynchronize:
	> En las lineas 156 y 166 Se llamo 2 veces con un tiempo de ejecución de **341.10us** y le tomo un total de **0.11%** del tiempo total de las operaciones con la API.

- cudaLaunchKernel:
	> Se llamo 2 veces con un tiempo de ejecución de **47.100us** y le tomo un total de **0.01%** del tiempo total de las operaciones con la API.

- cuDeviceGetAttribute:
	> Se llamo 101 veces con un tiempo promedio de ejecución de **163ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **5.9000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties:
	> En la linea 120 Se llamo 1 vez, con un tiempo promedio de ejecución de **5.1000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetLastError:
	> Se llamo 2 veces con un tiempo de ejecución de **2.3500us** y le tomo un total de **0.00%** del tiempo total de las operaciones con la API.

-   cuDeviceGetCount:
    > Se llamo 3 veces, con un tiempo promedio de ejecución de  **466ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGetName:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **1.2000us**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.

-   cuDeviceGet:
    > Se llamo 2 veces, con un tiempo promedio de ejecución de  **550ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceTotalMem:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **300ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
    
-   cuDeviceGetUuid:
    > Se llamo 1 vez, con un tiempo promedio de ejecución de  **200ns**  y le tomo un total de  **0.00%**  del tiempo total de las operaciones de la API.
