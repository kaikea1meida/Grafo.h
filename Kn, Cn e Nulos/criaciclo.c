#include "../../grafos/grafo.h"

void cria_ciclo(Grafo *g)
{
    if (g == NULL) {
        return;
    }
    nulificar_grafo(g);
    if (g->vertices < 2) {
        return;
    }
    for (int i = 0; i < g->vertices; i++) {
        ligar_vertice(g, i, (i + 1) % g->vertices);
    }
}