#include <stdlib.h>
#include "grafo.h"

Grafo* criar_grafo(int n)
{
    if (n == 0) // n to aceitando "grafo sem vertice"
    {
        return NULL;
    }

    Grafo *g = (Grafo*)calloc(1, sizeof(*g));// aloca um esoaço pro grafo que voce quer gerar
    if (g == NULL) 
    {
        return NULL;// se n gerou por algum motivo fala q edu ruim, retornando NULL
    }

    g->vertices = n;// os vertices são o tamanho
    g->arestas = 0;//o grafo é nulo, adiciona aresta depois com a função pra isso

    g->mat = calloc(n, sizeof(*g->mat));// faz o calloc da matriz e do struct vertice na memória
    g->v = calloc(n, sizeof(*g->v));

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
