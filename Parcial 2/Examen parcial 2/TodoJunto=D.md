# Examen

#### De una vez le comento que tal vez se pudo haber hecho mejor que el tema me esta interesando un chingo pero la presión de otros proyectos, trabajo y mas pues no da tiempo ya ve ;-; 

---

Yo creo que si me quedo chida esta madre
---
### Reporte 1  memTransfer

Se realizaron un total de 2 operaciones en la GPU y son las siguientes:
- [CUDA memcpy HtoD]:
	> En la linea 40 `` CHECK(cudaMemcpy(d_a, h_a, nbytes, cudaMemcpyHostToDevice)); `` se encarga de la transferencia de datos de la CPU (que es el arreglo `h_a`) a la GPU (el arreglo `d_a`), `nbytes` se encarga de indicarle la cantidad de bytes necesarios para almacenar los datos y el `cudaMemcpyHostToDevice` es el que le indica que es de la CPU a la GPU la transferencia de datos, esta transferencia de datos se hace para que la GPU se encarge de hacer calculos que los valores que se encuentran en la CPU. Se llamo 1 vez, con un tiempo promedio de ejecución de *2.1117ms* y le tomo un total del *52.15%* de el tiempo total de las operaciones de la GPU.
	
- [CUDA memcpy DtoH]:
	> En la linea 43 ``CHECK(cudaMemcpy(h_a, d_a, nbytes, cudaMemcpyDeviceToHost));`` se encarga de la transferencia de los datos de  la GPU (que es el arreglo de `d_a`) y los manda a la CPU (que es el arreglo de `h_a`), `nbytes` se encarga igual de indicarle la cantidad de bytes necesarios para almacenar los datos y `cudaMemcpyDeviceToHost` se encarga de indicar que se esta realizando una copia de el dispositivo al host (GPU al CPU), esto se hace para transferir los resultados de las operaciones realizadas en la GPU a la CPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **1.9374ms** y le tomo un total de *47.85%* del tiempo total de las operaciones de la GPU.

---
Se realizaron un total de 13 operaciones con las funciones de la API de CUDA

- cudaMalloc:
	> En las lineas 33/34 ``float *d_a;`` ``CHECK(cudaMalloc((float **)&d_a, nbytes));`` estas se encargan de reservar memoria en la GPU para almacenar datos, la memoria almacenada es `d_a` que es una variable de tipo float y `nbytes` se esta encargando de decirle cuanta memoria almacenar, esto se hace con la intención de tener espacio en la GPU para realizar las operaciones que se necesiten. Se llamo 1 vez, con un tiempo promedio de ejecución de **577.35ms** y le tomo un total de **93.74%** del tiempo total de las operaciones con la API.

- cudaDeviceReset:
	> En la linea 50 ``CHECK(cudaDeviceReset());`` esta se encarga de por así decirlo reiniciar la GPU y por lo tanto libera cualquier recurso que se halla usado y es casi si no obligatorio usarlo al final de un código de este tipo para dejar limpia la GPU  y lista para otro código o otras acciones. Se llamo 1 vez, con un tiempo promedio de ejecución de **31.729ms** y le tomo un total de **5.15%** del tiempo total de las operaciones de la API.

- cudaMemcpy:
	> Este se uso en las lineas 40 y 43 
	``CHECK(cudaMemcpy(d_a, h_a, nbytes, cudaMemcpyHostToDevice));`` 		``CHECK(cudaMemcpy(h_a, d_a, nbytes, cudaMemcpyDeviceToHost));`` 
se usa para copiar datos entre la GPU y la CPU. Se llamo 2 veces, con un tiempo promedio de ejecución de **2.1928ms** y le tomo un total de **0.71%** del tiempo total de las operaciones de la API.

- cuDeviceGetPCIBusId: 
	> Este no encontré esta función en el código pero buscando en internet supe que tal vez se llamo de manera interna y no de manera directa del código y se usa para para obtener la identificación del bus PCI de una GPU especifica, también investigue la bus PCI es la conexión de de la GPU a la placa madre.

- cudaFree:
	> En la linea 46 ``CHECK(cudaFree(d_a));`` se usa para liberar la memoria que se asignop a la GPU y se esta liberando la memoria que se asigno con ``cudaMalloc`` con la variable `d_a`. Se llamo 1 vez, con un tiempo promedio de ejecución de **306.30us** y le tomo un total de **0.05%** del tiempo total de las operaciones de la API.

- cuDeviceGetAttribute: 
	> Esta función no se encuentra directamente en el código igual que ``cuDeviceGetPCIBusId`` y se llamo de manera interna y según el sabio y todo poderoso Internet se usa para recuperar atributos específicos de una GPU, como su capacidad de cómputo, cantidad de núcleos CUDA, entre otros detalles. Se llamo 101 veces con un tiempo promedio de ejecución de **145ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice:
	> En la linea 16 ``CHECK(cudaSetDevice(dev));`` esto se usa cuando un dispositivo tiene mas de una GPU y es para seleccionar que GPU se usara, en este caso se usara la cantidad especificada en la variable `dev` que es 0. Se llamo 1 vez, con un tiempo promedio de ejecución de **8.0000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties: 
	> En la linea 24 ``CHECK(cudaGetDeviceProperties(&deviceProp, dev));`` este se usa para obtener las porpiedades de la GPU y se almacena en la variable `deviceProp`. Se llamo 1 vez, con un tiempo promedio de ejecución de **2.8000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGetCount: 
	> Esta es otra función que se manda a llamar de manera interna y no de manera explicita en el código pero sirve para para obtener el número de GPU disponibles. Se llamo 3 veces, con un tiempo promedio de ejecución de **466ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGet:
	> Igual es una funcion interna de CUDA y se usa para para determinar el dispositivo GPU actual o para obtener información sobre la GPU en uso. Se llamo 2 veces, con un tiempo promedio de ejecución de **450ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGetName: 
	> Esta es otra función que se usa de manera interna y se usa para obtener el nombre de un dispositivo GPU específico en sistemas con múltiples GPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **900ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceTotalMem: 
	> Esta es una función que se llama de manera interna y es usada para obtener la cantidad total de memoria global disponible en un dispositivo GPU específico. Se llamo 1 vez, con un tiempo promedio de ejecución de **400ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGetUuid: 
	> La ultima es lo mismo una función interna de la API de CUDA y se usa para para obtener un identificador único para un dispositivo GPU específico. Se llamo 1 vez, con un tiempo promedio de ejecución de **200ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

---
---

Profe esto esta muy tardado y apenas voy en el 2 ;-;
---
### Reporte 2  pinMemTransfer

Se realizaron un total de 2 operaciones en la GPU y son las siguientes:
- [CUDA memcpy HtoD]:
	> En la linea 53 ``CHECK(cudaMemcpy(d_a, h_a, nbytes, cudaMemcpyHostToDevice));`` se encarga de la transferencia de datos de la CPU (que es el arreglo `h_a`) a la GPU (el arreglo `d_a`), `nbytes` se encarga de indicarle la cantidad de bytes necesarios para almacenar los datos y el `cudaMemcpyHostToDevice` es el que le indica que es de la CPU a la GPU la transferencia de datos, esta transferencia de datos se hace para que la GPU se encarge de hacer calculos que los valores que se encuentran en la CPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **1.3036ms** y le tomo un total del **50.57%** de el tiempo total de las operaciones de la GPU.
	
- [CUDA memcpy DtoH]: 
	> En la linea 56 ``CHECK(cudaMemcpy(h_a, d_a, nbytes, cudaMemcpyDeviceToHost));`` se encarga de la transferencia de los datos de  la GPU (que es el arreglo de `d_a`) y los manda a la CPU (que es el arreglo de `h_a`), `nbytes` se encarga igual de indicarle la cantidad de bytes necesarios para almacenar los datos y `cudaMemcpyDeviceToHost` se encarga de indicar que se esta realizando una copia de el dispositivo al host (GPU al CPU), esto se hace para transferir los resultados de las operaciones realizadas en la GPU a la CPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **1.2743ms** y le tomo un total de **49.43%** del tiempo total de las operaciones de la GPU.
---
Se realizaron un total de 15 operaciones con las funciones de la API de CUDA

- cudaHostAlloc:
	> En las lineas 40/41 ``float  *h_a;`` ``CHECK(cudaMallocHost((float **)&h_a, nbytes));`` esta funcion se usa para asignar cierta cantidad de memoria a la CPU para la variable `h_a` que es un puntero de tipo float, este tipo de memoria se llama page-locked y le permite un acceso mas rapido a la GPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **564.84ms** y le tomo un total de **93.65%** del tiempo total de las operaciones de la GPU.
	
- cudaDeviceReset:
	> En la linea 63 ``CHECK(cudaDeviceReset());`` esta se encarga reiniciar la GPU y por lo tanto libera cualquier recurso que se halla usado y es casi si no obligatorio usarlo al final de un código de este tipo para dejar limpia la GPU y lista para otro código o otras acciones. Se llamo 1 vez, con un tiempo promedio de ejecución de **31.051ms** y le tomo un total de **5.15%** del tiempo total de las operaciones de la API.

- cudaMemcpy:
	> Se usa en las lineas 53 y 56 
	``CHECK(cudaMemcpy(d_a, h_a, nbytes, cudaMemcpyHostToDevice));`` 
	``CHECK(cudaMemcpy(h_a, d_a, nbytes, cudaMemcpyDeviceToHost));``
	se usa para copiar datos entre la GPU y la CPU. Se llamo 2 veces, con un tiempo promedio de ejecución de **1.3660ms** y le tomo un total de **0.45%** del tiempo total de las operaciones de la API.

- cuDeviceGetPCIBusId: 
	> Es una función interna de CUDA que se usa para obtener la identificación del bus PCI de una GPU especifica. Se llamo 1 vez, con un tiempo promedio de ejecución de **2.0604ms** y le tomo un total de **0.34%** del tiempo total de las operaciones de la API.

- cudaFreeHost:
	> En la linea 60 ``CHECK(cudaFreeHost(h_a));`` se usa para liberar la memoria que se halla apartado con ``cudaMallocHost`` Se llamo 1 vez, con un tiempo promedio de ejecución de **1.8091ms** y le tomo un total de **0.30%** del tiempo total de las operaciones de la API.

- cudaMalloc: 
	> En las lineas 44/45 ``float  *d_a;`` ``CHECK(cudaMalloc((float  **)&d_a, nbytes));`` estas se encargan de reservar memoria en la GPU para almacenar datos, la memoria almacenada es `d_a` que es una variable de tipo float y `nbytes` se esta encargando de decirle cuanta memoria almacenar, esto se hace con la intención de tener espacio en la GPU para realizar las operaciones que se necesiten. Se llamo 1 vez, con un tiempo promedio de ejecución de **342.90us** y le tomo un total de **0.06%** del tiempo total de las operaciones con la API.

- cudaFree: 
	> La linea 59 ``CHECK(cudaFree(d_a));`` se usa para liberar la memoria que se asigno a la GPU. Se llamo 1 vez, con un tiempo promedio de ejecución de **261.00us** y le tomo un total de **0.04%** del tiempo total de las operaciones de la API.

- cuDeviceGetAttribute:
	> Bueno otra función interna de CUDA que sale, esta se encarga de obtener atributos específicos de la GPU en el entorno de CUDA. Se llamo 101 veces con un tiempo promedio de ejecución de **152ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaSetDevice:
	> En la linea 17 ``CHECK(cudaSetDevice(dev));`` esto se usa cuando un dispositivo tiene mas de una GPU y es para seleccionar que GPU se usara, en este caso se usara la cantidad especificada en la variable `dev` que es 0. Se llamo 1 vez, con un tiempo promedio de ejecución de **7.2000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cudaGetDeviceProperties: 
	> En la linea 25 ``CHECK(cudaGetDeviceProperties(&deviceProp, dev));`` este se usa para obtener las porpiedades de la GPU y se almacena en la variable `deviceProp`. Se llamo 1 vez, con un tiempo promedio de ejecución de **2.4000us** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

De las siguientes 5 funciones solo pondré la cantidad de veces que fue llamado el tiempo promedio y el % del tiempo total para hacer esto mas rápido ya que son las mismas funciones internas que en el pasado y solo cambian los valores =D

- cuDeviceGetCount:
	> Se llamo 3 veces, con un tiempo promedio de ejecución de **333ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGet: 
	> Se llamo 2 veces, con un tiempo promedio de ejecución de **500ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGetName:
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **600ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceTotalMem: 
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **400ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

- cuDeviceGetUuid: 
	> Se llamo 1 vez, con un tiempo promedio de ejecución de **200ns** y le tomo un total de **0.00%** del tiempo total de las operaciones de la API.

---
---

Ta chido el tema pero es musho pa me pendejo cerebro 
---
### Reporte 3  readSegment

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

---
---

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

---
---

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

---
---

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
---
---

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

---
---

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
---
---

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
---
---

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

---
---

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

---
---
# Ta bien? ;-; Por k yo no
