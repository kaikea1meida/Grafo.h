#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


void imprime_grafo(Grafo *g)
{
    if (g == NULL) {
        return;
    }
    for (int i = 0; i < g->vertices; i++) {
        printf("%d:", i);
        for (int j = 0; j < g->v[i].qntsvizinhos; j++) {
            printf(" %d", g->v[i].vizinho[j]);
        }
        putchar('\n');
    }
}

static int contem_vizinho(Grafo *g, int a, int b, const int *ativo)
{
    return ativo[a] && ativo[b] && g->mat[a][b] != 0;
}

static int vertice_simples(Grafo *g, int v, const int *ativo)
{
    for (int a = 0; a < g->vertices; a++) {
        if (!contem_vizinho(g, v, a, ativo)) {
            continue;
        }
        for (int b = a + 1; b < g->vertices; b++) {
            if (!contem_vizinho(g, v, b, ativo)) {
                continue;
            }
            int a_contem_b = 1;
            int b_contem_a = 1;
            for (int x = 0; x < g->vertices; x++) {
                int a_adj = x == a || g->mat[a][x];
                int b_adj = x == b || g->mat[b][x];
                if (ativo[x] && a_adj && !b_adj) {
                    a_contem_b = 0;
                }
                if (ativo[x] && b_adj && !a_adj) {
                    b_contem_a = 0;
                }
            }
            if (!a_contem_b && !b_contem_a) {
                return 0;
            }
        }
    }
    return 1;
}

int eh_fortemente_cordal(Grafo *g)
{
    if (g == NULL) {
        return 0;
    }
    int *ativo = calloc((size_t)g->vertices, sizeof(*ativo));
    if (g->vertices > 0 && ativo == NULL) {
        return 0;
    }
    for (int i = 0; i < g->vertices; i++) {
        ativo[i] = 1;
    }
    for (int removidos = 0; removidos < g->vertices; removidos++) {
        int escolhido = -1;
        for (int i = 0; i < g->vertices; i++) {
            if (ativo[i] && vertice_simples(g, i, ativo)) {
                escolhido = i;
                break;
            }
        }
        if (escolhido < 0) {
            free(ativo);
            return 0;
        }
        ativo[escolhido] = 0;
    }
    free(ativo);
    return 1;
}