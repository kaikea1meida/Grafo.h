#include "grafo.h"
int eh_simetrica(int ordem, int mat[ordem][ordem])
{
    for(int i=0;i<ordem;i++)
    {
        for(int j=i+1;j<ordem;j++)
        {
                if(mat[i][j]!=mat[j][i])
                {
                    return 0;
                }
        }
    }
    return 1;
}