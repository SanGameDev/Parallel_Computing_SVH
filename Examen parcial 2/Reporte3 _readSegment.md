# Examen

Ta chido el tema pero es musho pa me pendejo cerebro 
---
### Reporte 4  readSegment

Se realizaron un total de 3 operaciones en la GPU y son las siguientes:

- [CUDA memcpy DtoH]: 
	> En la linea 133 ``CHECK(cudaMemcpy(gpuRef, d_C, nBytes, cudaMemcpyDeviceToHost));`` se encarga de la transferencia de los datos de la GPU (que es el arreglo de `d_C`) y los manda a la CPU (que es el arreglo de `gpuRef`), `nbytes` se encarga igual de indicarle la cantidad de bytes necesarios para almacenar los datos y `cudaMemcpyDeviceToHost` se encarga de indicar que se esta realizando una copia de el dispositivo al host (GPU al CPU), esto se hace para transferir los resultados de las operaciones realizadas en la GPU a la CPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **992.10us** y le tomo un total de **49.71%** del tiempo total de las operaciones de la GPU.

- [CUDA memcpy HtoD]:
	> En las lineas 112/113 
	``CHECK(cudaMemcpy(d_A, h_A, nBytes, cudaMemcpyHostToDevice));``
	``CHECK(cudaMemcpy(d_B, h_A, nBytes, cudaMemcpyHostToDevice));``
	se encarga de copiar los datos desde el CPU a la GPU desde el puntero `h_A` hacia los punteros `d_A` y `d_B` y ya se sabe el resto al igual que yo. Se llamo 2 veces, con un tiempo promedio de ejecución de **453.23us** y le tomo un total de **45.41%** del tiempo total de las operaciones de la GPU.

- readOffset(float*, float*, float*, int, int):
	> De las lineas 56/63 y la linea 125 
	``__global__ void readOffset(float *A, float *B, float *C, const int n, int offset) { unsigned  int i = blockIdx.x * blockDim.x + threadIdx.x; unsigned  int k = i + offset; if (k < n) C[i] = A[k] + B[k]; }``
	``readOffset<<<grid, block>>>(d_A, d_B, d_C, nElem, offset);``
	donde es un kernel que toma 3 punteros `A`, `B`, `C`, 1 entero `n` y otro entero `offset`, este kernel hace una operacion de suma en paralelo con los vectores `A` y `B` con un desplasamiento que es indicado por `offset` y esto se almacena en `C` y el kernel de la linea 125 hace que se realize la operacion en la GPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **49.408us** y le tomo un total de **2.48%** del tiempo total de las operaciones de la GPU.

- warmup(float*, float*, float*, int, int):
	> De las lineas 48/54 y 117 (hay wey como el jefe maestro) 
	``__global__ void warmup(float *A, float *B, float *C, const int n, int offset) { unsigned  int i = blockIdx.x * blockDim.x + threadIdx.x; unsigned  int k = i + offset; if (k < n) C[i] = A[k] + B[k]; }``
	``warmup<<<grid, block>>>(d_A, d_B, d_C, nElem, offset);``
	en esta definición de kernel se toman igual 3 punteros `A`, `B`, `C`, 1 entero `n` y otro entero `offset` este kernel hace una operacion de suma en paralelo con los vectores `A` y `B` con un desplasamiento que es indicado por `offset` y esto se almacena en `C` y el kernel de la linea 117 (hay wey como el jefe maestro) hace que se realize la operacion en la GPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **48.001us** y le tomo un total de **2.40%** del tiempo total de las operaciones de la GPU.
	
---
Se realizaron un total de 16 operaciones con las funciones de la API de CUDA

- cudaMalloc: 
	> En las lineas 106/109 
	``float *d_A, *d_B, *d_C;``
``CHECK(cudaMalloc((float**)&d_A, nBytes)); CHECK(cudaMalloc((float**)&d_B, nBytes)); CHECK(cudaMalloc((float**)&d_C, nBytes));`` 
	estas 3 llamadas a `cudaMalloc` se usan para reservar memoria en el dispositivo para los punteros `d_A`, `d_B`, y `d_C` lo cual se usara para realizar cálculos en la GPU. Se llamo 3 veces, con un tiempo promedio de ejecución de **201.26ms** y le tomo un total de **93.88%** del tiempo total de las operaciones con la API. 

- cudaDeviceReset:
	> En la linea 144 ``CHECK(cudaDeviceReset());`` esta se encarga reiniciar la GPU y por lo tanto libera cualquier recurso que se halla usado y es casi si no obligatorio usarlo al final de un código de este tipo para dejar limpia la GPU y lista para otro código o otras acciones. Se llamo 1 vez, con un tiempo promedio de ejecución de **32.299ms** y le tomo un total de **5.02%** del tiempo total de las operaciones de la API.

- cudaMemcpy:
	> En las lienas 112/113 y 133 
	``CHECK(cudaMemcpy(d_A, h_A, nBytes, cudaMemcpyHostToDevice)); CHECK(cudaMemcpy(d_B, h_A, nBytes, cudaMemcpyHostToDevice));``
	``CHECK(cudaMemcpy(gpuRef, d_C, nBytes, cudaMemcpyDeviceToHost));``
se utiliza para transferir datos entre la CPU y la GPU. Se llamo 3 veces, con un tiempo promedio de ejecución de **1.1213ms** y le tomo un total de **0.52%** del tiempo total de las operaciones con la API. 

- cuDeviceGetPCIBusId:
	>pues ya sabemos que es una función interna de CUDA que se usa para obtener la identificación del bus PCI de una GPU especifica. Se llamo 1 vez, con un tiempo promedio de ejecución de **2.5464ms** y le tomo un total de **0.40%** del tiempo total de las operaciones de la API.

- cudaFree:
	> En las lineas 137/139 igual se usa para liberar la memoria que se aparto para las operaciones y dejar el dispositivo limpio para meterle mas chingaderas =D. Se llamo 3 veces, con un tiempo promedio de ejecución de **277.73us** y le tomo un total de **0.13%** del tiempo total de las operaciones con la API. 

- cudaDeviceSynchronize:
	> En las lineas 116/122 y 124/130 
	``iStart = seconds(); warmup<<<grid, block>>>(d_A, d_B, d_C, nElem, offset); CHECK(cudaDeviceSynchronize()); iElaps = seconds() - iStart;``
	``iStart = seconds(); readOffset<<<grid, block>>>(d_A, d_B, d_C, nElem, offset); CHECK(cudaDeviceSynchronize()); iElaps = seconds() - iStart;``
	el `cudaDeviceSynchronize` se usa para asegurarse que todas las operaciones en la GPU se hayan finalizado antes de poder seguir con el codigo, esto es de suma importancia para asegurase de que se hayan completado los kernels en la GPU antes de que se haga algo en la CPU. Se llamo 2 veces, con un tiempo promedio de ejecución de **103.15us** y le tomo un total de **0.03%** del tiempo total de las operaciones con la API. 

- cudaLaunchKernel:
	> Es una funcion interna de CUDA que se usa para especificar la configuración de hilos y bloques que se ejecutarán en la GPU y para pasar los argumentos necesarios al kernel. Se llamo 2 veces, con un tiempo promedio de ejecución de **32.900us** y le tomo un total de **0.01%** del tiempo total de las operaciones con la API. 

- cuDeviceGetAttribute:
	> Bueno otra vez esta función interna de CUDA que sale, esta se encarga de obtener atributos específicos de la GPU en el entorno de CUDA. Se llamo 101 como siempre veces con un tiempo promedio de ejecución de **156ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice: 
	> En la linea 73 `CHECK(cudaSetDevice(dev));` esto se usa cuando un dispositivo tiene mas de una GPU y es para seleccionar que GPU se usara, en este caso se usara la cantidad especificada en la variable `dev` que es 0. Se llamo 1 vez, con un tiempo promedio de ejecución de **5.5000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties:
	> En la linea 70 `CHECK(cudaGetDeviceProperties(&deviceProp, dev));` este se usa para obtener las porpiedades de la GPU y se almacena en la variable `deviceProp`. Se llamo 1 vez, con un tiempo promedio de ejecución de **4.9000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetLastError:
	> Ahuevo funcion nueva, pero es interna de CUDA ;-;, esta sirve para después de que se hagan las llamadas a funciones de la API de CUDA verifica si se produjo algún error durante la ejecución. Se llamo 2 veces, con un tiempo promedio de ejecución de **600ns** y le tomo un total de **0.00%** del tiempo total de las operaciones con la API. 
	
De las siguientes 5 funciones solo pondré la cantidad de veces que fue llamado el tiempo promedio y el % del tiempo total para hacer esto mas rápido ya que son las mismas funciones internas que en el pasado y solo cambian los valores =D

- cuDeviceGetCount:
	> Se llamo 3 veces, con un tiempo promedio de ejecución de **300ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGet: 
	> Se llamo 2 veces, con un tiempo promedio de ejecución de **400ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGetName:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **800ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceTotalMem: 
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **500ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGetUuid: 
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **200ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

