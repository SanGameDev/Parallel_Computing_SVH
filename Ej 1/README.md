# Create Naive Multiplication in C  matrix by matrix

To multiply two matrices, we need to follow set of rules. we have two matrices A and B, with dimensions m x n and n x p, respectively. The resulting matrix C will have dimensions m x p.

Here’s how to calculate the elements of C:

For each element in the resulting matrix C, take the dot product of the corresponding row in matrix A and the corresponding column in matrix B.
Add up the products from step 1 to get the value of the element in C.

---

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


This code performs matrix multiplication using three nested loops. 
It multiplies two 10x10 matrices 'matris_A' and 'matris_B' and stores the result in matrix 'cmatris_R'. 
Here's a breakdown of the code:

1. It uses three nested 'for' loops:
   - The outermost loop (i) iterates from 0 to 9.
   - The middle loop (j) iterates from 0 to 9.
   - The innermost loop (k) iterates from 0 to 9.

2. Inside the innermost loop, it calculates the product of elements 'a[i][k]' 
and 'b[k][j]' and adds it to the corresponding element 
in the result matrix 'c[i][j]'.

In summary, this code performs a naive matrix multiplication, 
where each element in the result matrix 'c' is the sum of the products of 
corresponding elements from matrices 'a' and 'b'. It does this by using three 
nested loops to iterate through the indices of the matrices.
