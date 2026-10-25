#include <stdlib.h>
#include <string.h>
#include"grafo.h"

Grafo* altera_tamanho_grafo(Grafo *g, int Nnovo)
{
    if (g == NULL || Nnovo < 0) {
        return NULL;
    }

    int antigo = g->vertices;
    if (Nnovo < antigo) {
        for (int i = Nnovo; i < antigo; i++) {
            free(g->mat[i]);
        }
    }

    int **mat = realloc(g->mat, (size_t)Nnovo * sizeof(*mat));
    Vertice *vertices = realloc(g->v, (size_t)Nnovo * sizeof(*vertices));
    if ((Nnovo > 0) && (mat == NULL || vertices == NULL)) {
        return NULL;
    }
    g->mat = mat;
    g->v = vertices;

    for (int i = 0; i < Nnovo; i++) {
        if (i < antigo) {
            int *linha = realloc(g->mat[i], (size_t)Nnovo * sizeof(*linha));
            if (Nnovo > 0 && linha == NULL) {
                return NULL;
            }
            g->mat[i] = linha;
            if (Nnovo > antigo) {
                memset(g->mat[i] + antigo, 0,
                       (size_t)(Nnovo - antigo) * sizeof(*g->mat[i]));
            }
        } else {
            g->mat[i] = calloc((size_t)Nnovo, sizeof(**g->mat));
            if (Nnovo > 0 && g->mat[i] == NULL) {
                return NULL;
            }
        }
    }
    g->vertices = Nnovo;
    g->arestas = 0;
    atualiza_vizinhos(g);
    return g;
}