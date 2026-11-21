#include "grafo.h"

int eh_bisimplicial(Grafo* G, int x,int y)
{
    if(G==NULL||G->mat[x][y]==0)//só pode ser bisimplicial se existir a aresta
    {
        return 0;
    }

    for(int i=0;i<G->vertices;i++)
    {
        if(G->mat[x][i])//pega um vizinho de x
        {
            for(int j=0;j<G->vertices;j++)
            {
                if(G->mat[y][j]&&G->mat[i][j]==0)//dois vizinhos precisam se ver
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}