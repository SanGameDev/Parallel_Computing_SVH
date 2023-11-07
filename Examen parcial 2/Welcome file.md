# Examen

Yo creo que si me quedo chida esta madre
---
### Reporte 1  memTransfer

Se realizaron un total de 2 operaciones en la GPU y son las siguientes:
- [CUDA memcpy DtoH]:
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










