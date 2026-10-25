#include "grafo.h"
#include <stdlib.h>
void libera_grafo(Grafo *G)
{
    if (G == NULL)
    {
        return;
    }

    if (G->v != NULL)
    {
        for (int i = 0; i < G->vertices; i++)
        {
            if (G->v[i].vizinho != NULL)
            {
                free(G->v[i].vizinho);
                G->v[i].vizinho = NULL;
            }
        }
        free(G->v);
        G->v = NULL;
    }

    if (G->mat != NULL)
    {
        for (int i = 0; i < G->vertices; i++)
        {
            if (G->mat[i] != NULL)
            {
                free(G->mat[i]);
                G->mat[i] = NULL;
            }
        }
        free(G->mat);
        G->mat = NULL;
    }

    free(G);
}
