#include "../../Grafo.h/grafo.h"

Grafo* nulificar_grafo(Grafo *g)
{
    if (g == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < g->vertices; i++) 
    {
        for (int j = 0; j < g->vertices; j++) 
        {
            g->mat[i][j] = 0;
        }

        free(g->v[i].vizinho);
        g->v[i].vizinho = NULL;
        g->v[i].qntsvizinhos = 0;
        g->v[i].grau = 0;
    }

    g->arestas = 0;
    for (int i = 0; i < g->vertices; i++)
    {
        verifica_vizinhos(g, i);
    }

    return g;
}