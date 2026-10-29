#include "grafo.h"
void simetrizar_matriz(int ordem, int mat[ordem][ordem])
{
    for(int i=0;i<ordem;i++)
    {
        for(int j=0;j<ordem;j++)
        {
            if(j>i)
            {
                if(mat[i][j]!=mat[j][i])
                {
                    mat[j][i]=((mat[j][i]+3)%2);
                }
            }
        }
    }
}