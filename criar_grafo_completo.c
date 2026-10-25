#include "grafo.h"

void completa_grafo(Grafo *g)
{
    if (g == NULL) {
        return;
    }
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            g->mat[i][j] = (i != j);
        }
    }
    atualiza_vizinhos(g);
}