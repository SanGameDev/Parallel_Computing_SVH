#  Investigación CUDA Cores, Threads, Blocks and Grids

-Que son los CUDA Cores:
  Primero CUDA es una plataforma de computación paralela y un modelo de programación que permite incrementos dramáticos en el rendimiento de computación al aprovechar la potencia de la unidad de procesamiento de gráficos      (GPU).
  Esta plataforma se introdujo en 2006 y se ha usado desde enntonces en numerosas GPUs esta plataforma se encuentra en las gamas GeForce, Quadro y Tesla.

  Los CUDACores son los procesadores paralelos que se encargan de procesar todos los datos que entran y salen de la GPU Estos por lo general se encargan de procesar los graficos, pero tambien se usan para dividirse los        procesos y calcular varios procesos matematicos y computacionales.

-Que son los Threads:
  Son Sub-procesos o hilos que se pueden definir como una secuencia de instrucciones, estos son entidades mucho mas pequeñas, por lo cual son mas faciles de gestionar.

  Estos viven dentro de los procesos por lo que se crean, ejecutan y finalizan dentro de un procesos, y esos pueden poseer multiples threads, siendo una relacion de uno a muchos.

-Que son Blocks & Grids:
  Los grids son el mas alto nivel de parralelismo en CUDA, siendo un array de bloques tridimensional y cada bloque contiene un grupo de threads, y este define el numero de blocks que se usaran.

  Los Blocks son el segundo nivel de paralelismo y cada thread se ejecua en el mismo codigo y este define el numero de threads que se usara.

  Bibliografia:
  “Qué son los Nvidia CUDA Cores y cuál es su importancia”. Profesional Review. Accedido el 4 de octubre de 2023. [En línea]. Disponible: https://www.profesionalreview.com/2018/10/09/que-son-nvidia-cuda-core/ 
  “Threads y Procesos”. CódigoFacilito. Accedido el 4 de octubre de 2023. [En línea]. Disponible: https://codigofacilito.com/articulos/threads-procesos
  “Understanding cuda grid dimensions, block dimensions, and thread organization,” Saturn Cloud Blog, https://saturncloud.io/blog/understanding-cuda-grid-dimensions-block-dimensions-and-thread-organization/


  arquitecturas de las tarjetas graficas
  como funcionan las arquitecturas de las graficas
  core - warp - bloque 
  
