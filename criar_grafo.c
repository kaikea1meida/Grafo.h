#include <stdlib.h>
#include "grafo.h"

Grafo* cria_grafo(int n)
{
    if (n < 0) 
    {
        return NULL;
    }

    Grafo *g = (Grafo*)calloc(1, sizeof(*g));
    if (g == NULL) 
    {
        return NULL;
    }

    g->vertices = n;
    g->arestas = 0;

    if (n == 0)
    {
        g->mat = NULL;
        g->v = NULL;
        return g;
    }

    g->mat = calloc(n, sizeof(*g->mat));
    g->v = calloc(n, sizeof(*g->v));

    if (g->mat == NULL || g->v == NULL) 
    {
        libera_grafo(g);
        return NULL;
    }

    for (int i = 0; i < n; i++) 
    {
        g->mat[i] = calloc(n, sizeof(**g->mat));
        if (g->mat[i] == NULL) 
        {
            libera_grafo(g);
            return NULL;
        }

        g->v[i].japassou = 0;
        g->v[i].vizinho = NULL;
        g->v[i].qntsvizinhos = 0;
        g->v[i].grau = 0;
    }

    return g;
}
