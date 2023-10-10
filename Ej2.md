# Cargar y modificar imagen con 'OpenCV'

OpenCV (Open Computer Vision):

- Es una librería de código abierto que procesa imágenes. Donde se usa principalmente las herramienta de procesamiento de imágenes para leer, modificar y mostrar datos de tipo imagen con el codigo.
  
Elementos del código:

- Definición de imágenes:
Las imágenes en términos de computación son en su expresión mas básica, son matrices de valores, equivalentes a los pixeles de la imagen en su ancho y altura, y su valor contiene la información de intencidad de cada color del pixel.
- Proceso de modificación por Color Map:
El proceso se basa en dividir la imagen en sus canales RGB, para obtener valores individuales de intensidad de cada color, y en base a esos valores, modificar los valores de pixeles de la manera deseada, en este caso se les aplica un 'Color Map', el cual modifica los pixeles en base a su valor numérico, utilizando escalas de colores definidas por el 'Color Map'.

```c++
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <filesystem>

     int main() {
         std::string image_path;
         std::cout << "Enter the path to the image: ";
         std::cin >> image_path; //Input the image file path

         //Check if filepath exists
         if (!std::filesystem::exists(image_path)) {
             std::cout << "File does not exist at the specified path" << std::endl;
             return -1;
         }

         cv::Mat image = cv::imread(image_path);
         //Check if its a valid image file
         if (image.empty()) {
             std::cout << "Error loading the image" << std::endl;
             return -1;
         }
         else {
             std::cout << "Image loaded successfully" << std::endl;
         }
         //Show original image
         cv::imshow("Image", image);

         //Wait for a keystroke in the window
         cv::waitKey(0);

         // Separate the image into its three channels
         cv::Mat bgr[3];
         cv::split(image, bgr);

         //Modify images by color maps
         cv::Mat blueChannel, greenChannel, redChannel;
         cv::applyColorMap(bgr[0], blueChannel, cv::COLORMAP_PINK);
         cv::applyColorMap(bgr[1], greenChannel, cv::COLORMAP_PLASMA);
         cv::applyColorMap(bgr[2], redChannel, cv::COLORMAP_TWILIGHT);

         // Create modified image windows
         cv::imshow("blueChannel", blueChannel);
         cv::imshow("greenChannel", greenChannel);
         cv::imshow("redChannel", redChannel);
         cv::waitKey(0);
     }
```

Análisis de complejidad de tiempo

La complejidad de tiempo de este código es de O(W * H * C). Dado que originalmente las imágenes cargadas por cv::imread tienen una complejidad de O(W * H) W siendo el ancho (width) y H la altura (height) de la imagen cargada, al ser divididas por sus canales de colores RGB por cv::split, se convierte en O(W * H * C), 'C' siendo el numero de canales en los que se divide.
