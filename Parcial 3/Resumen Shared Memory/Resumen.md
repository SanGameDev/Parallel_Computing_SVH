# **Shared Memory**
Aqui el resumen de lo que nos pidio

### Square Shared Memory

Esta puede usar la memoria compartida para almacenar datos globales con dimensiones cuadradas de manera sensilla la cual facilita el calculo de desplazamientos de memoria 1D a partir de indices de hilo 2D.

- La manera de declarar una variable d memoria compartida 2D es con `__shared__ int tile[N][N];`

-  Dado que la memoria compartida es cuadrada, se puede acceder a ella desde un bloque de hilos 2D con hilos vecinos que acceden a elementos otros elementos vecinos en las dimensiones x o y, en el libro se mencionan dos métodos de acceso que son `tile[threadIdx.y][threadIdx.x]` y `tile[threadIdx.x][threadIdx.y]`.

#### Accessing Row-Major versus Column-Major

para esto se usa un grid con un bloque 2D que contenga 32 hilos en cada dimension. El kernel realiza dos operaciones simples: escribe índices globales de hilo en una matriz de memoria compartida 2D en orden de fila y luego lee esos valores de la memoria compartida en orden de fila y los almacena en memoria global.
- Se declara estáticamente una matriz de memoria compartida 2D: `__shared__ int tile[BDIMY][BDIMX];`
- Calcula el índice global del hilo utilizando su identificador 2D: `unsigned int idx = threadIdx.y * blockDim.x + threadIdx.x;`
- Escribe el índice global en la memoria compartida en orden de fila: `tile[threadIdx.y][threadIdx.x] = idx;`
- Lee desde la memoria compartida y almacena en memoria global en orden de fila: `out[idx] = tile[threadIdx.y][threadIdx.x];`
- 





