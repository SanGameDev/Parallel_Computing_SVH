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

