#include <stdlib.h>
#include"grafo.h"

void ligar_vertice(Grafo *g, int v1, int v2)
{
    if (g == NULL || v1 < 0 || v2 < 0 || v1 == v2 || g->mat[v1][v2]) 
    {
        return;
    }
    g->mat[v1][v2] = 1;
    g->mat[v2][v1] = 1;
    g->arestas++;
    verifica_vizinhos(g,v1);
    verifica_vizinhos(g,v2);

    
}