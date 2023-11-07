# Examen

Profe esto esta muy tardado y apenas voy en el 2 ;-;
---
### Reporte 3  pinMemTransfer

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

