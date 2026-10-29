#include "grafo.h"
void copiar_matriz(Grafo* g, int matriz[g->vertices][g->vertices])
{
    for(int i=0;i<g->vertices;i++)
    {
        for(int j=0;j<g->vertices;j++)
        {
            g->mat[i][j]=matriz[i][j];
        }
    }
}