# Create Naive Multiplication in C  matrix by matrix

Definición de matrices:
Una matriz es una estructura rectangular de números dispuestos en filas y columnas. Se
representa generalmente como una letra mayúscula, como A, B, o C. La dimensión de una
matriz se describe mediante dos números: el número de filas y el número de columnas. Por
ejemplo, una matriz 2x3 tiene 2 filas y 3 columnas.
Multiplicación de matrices:
La multiplicación de matrices es una operación binaria que combina dos matrices para
obtener una tercera matriz. Para que la multiplicación de matrices sea posible, el número de
columnas de la primera matriz debe ser igual al número de filas de la segunda matriz. Si
tienes una matriz A de dimensiones m x n y una matriz B de dimensiones n x p, puedes
multiplicarlas para obtener una matriz C de dimensiones m x p.
Proceso de multiplicación:
Para calcular el elemento cij de la matriz resultante C, que se encuentra en la fila i y la
columna j, se realiza la siguiente operación:
cij = a1j * b1i + a2j * b2i + ... + anj * bni
Donde aij representa el elemento en la fila i y la columna j de la matriz A, y bji representa el
elemento en la fila j y la columna i de la matriz B.

Propiedades de la multiplicación de matrices:
La multiplicación de matrices no es conmutativa, es decir, en general, A * B ≠ B * A.

Multiplicación de Matrices 2

La multiplicación de matrices es asociativa, lo que significa que (A * B) * C = A * (B * C) si
se cumplen las dimensiones adecuadas.
Existe una matriz identidad, denotada como I, tal que A * I = I * A = A para cualquier matriz
A.
La multiplicación de matrices distribuye sobre la suma, es decir, A * (B + C) = A * B + A *
C.
Aplicaciones de la multiplicación de matrices:
La multiplicación de matrices se utiliza en una variedad de aplicaciones, incluyendo la
resolución de sistemas de ecuaciones lineales, la transformación de coordenadas en gráficos
por computadora, el cálculo de probabilidades en estadísticas, y la resolución de problemas
de optimización en ciencias de la computación, entre otros.

```c

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int matris_A[10][10], matris_B[10][10], matris_R[10][10];
    int numxD;
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            matris_A[i][j] = numxD;
            matris_B[i][j] = numxD;
            numxD++;
        }
    }
    
    numxD = 0;
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int xD = 0;
            for(int k = 0; k < 10; k++)
            {
                xD += matris_A[k][j] * matris_B[j][k];
            }
            matris_R[i][j] = xD;
        }
    }
    
    for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", matris_R[i][j]);
		}

		printf("\n");
	}

    return 0;
}

```


Análisis de complejidad temporal
1. Inicialización de la Matriz de Resultados:
En el código, hay dos bucles anidados que se ejecutan para inicializar la matriz de
resultados.
La cantidad de operaciones en esta parte es N x N, donde N es la dimensión de las
matrices (N x N).
Por lo tanto, la complejidad de esta parte es O(N^2).
2. Multiplicación de Matrices:
La función multiplyMatrices utiliza recursión para realizar la multiplicación de matrices.
El número total de llamadas recursivas es N^3, ya que hay tres parámetros (i, j, y k),
cada uno variando de 0 a N-1.

Multiplicación de Matrices 4

En cada llamada recursiva, se realiza una multiplicación y una suma.
Por lo tanto, el número total de operaciones para la multiplicación de matrices es
proporcional a N^3.
La complejidad de esta parte es O(N^3).
3. Impresión de la Matriz Resultante:
Hay dos bucles anidados utilizados para imprimir la matriz resultante.
Al igual que la inicialización, la cantidad de operaciones en esta parte es N x N.
Por lo tanto, la complejidad de esta parte es O(N^2).
En resumen, la complejidad temporal total del código se encuentra dominada por la
multiplicación de matrices, que es O(N^3). Las otras partes del código, como la inicialización y
la impresión, contribuyen con una complejidad de O(N^2) cada una. Por lo tanto, la
complejidad temporal general del código es O(N^3), ya que el término más grande (N^3)
domina el rendimiento a medida que N crece. Esto significa que el tiempo de ejecución
aumentará significativamente a medida que aumente el tamaño de las matrices de entrada.
