#include <stdlib.h>
#include "grafo.h"

Grafo* ligar_vertice(Grafo *g, int v1, int v2)
{
    if (g == NULL || g->mat == NULL || g->v == NULL ||
        v1 < 0 || v2 < 0 || v1 >= g->vertices || v2 >= g->vertices ||
        v1 == v2 || g->mat[v1] == NULL || g->mat[v2] == NULL ||
        g->mat[v1][v2])
    {
        //MUDADO: retorna NULL para entrada inválida ou ligação já existente.
        return NULL;
    }

    int adicionar_v1 = 1;
    int adicionar_v2 = 1;
    for (int i = 0; i < g->v[v1].qntsvizinhos; i++)
    {
        if (g->v[v1].vizinho != NULL && g->v[v1].vizinho[i] == v2)
        {
            adicionar_v1 = 0;
            break;
        }
    }
    for (int i = 0; i < g->v[v2].qntsvizinhos; i++)
    {
        if (g->v[v2].vizinho != NULL && g->v[v2].vizinho[i] == v1)
        {
            adicionar_v2 = 0;
            break;
        }
    }

    if (g->v[v1].qntsvizinhos < 0 || g->v[v2].qntsvizinhos < 0 ||
        (g->v[v1].qntsvizinhos > 0 && g->v[v1].vizinho == NULL) ||
        (g->v[v2].qntsvizinhos > 0 && g->v[v2].vizinho == NULL))
    {
        return NULL;
    }

    int *novos_vizinhos_v1 = NULL;
    int *novos_vizinhos_v2 = NULL;
    if (adicionar_v1)
    {
        //MUDADO: usa int no cálculo do tamanho, conforme solicitado.
        novos_vizinhos_v1 = malloc((g->v[v1].qntsvizinhos + 1) * sizeof(int));
        if (novos_vizinhos_v1 == NULL)
        {
            return NULL;
        }
        for (int i = 0; i < g->v[v1].qntsvizinhos; i++)
        {
            novos_vizinhos_v1[i] = g->v[v1].vizinho[i];
        }
        novos_vizinhos_v1[g->v[v1].qntsvizinhos] = v2;
    }
    if (adicionar_v2)
    {
        //MUDADO: usa int no cálculo do tamanho, conforme solicitado.
        novos_vizinhos_v2 = malloc((g->v[v2].qntsvizinhos + 1) * sizeof(int));
        if (novos_vizinhos_v2 == NULL)
        {
            free(novos_vizinhos_v1);
            return NULL;
        }
        for (int i = 0; i < g->v[v2].qntsvizinhos; i++)
        {
            novos_vizinhos_v2[i] = g->v[v2].vizinho[i];
        }
        novos_vizinhos_v2[g->v[v2].qntsvizinhos] = v1;
    }

    //MUDADO: atualiza as listas dos dois vértices sem depender de verifica_vizinhos,
    //que não recalcula listas já alocadas.
    if (adicionar_v1)
    {
        free(g->v[v1].vizinho);
        g->v[v1].vizinho = novos_vizinhos_v1;
        g->v[v1].qntsvizinhos++;
        g->v[v1].grau++;
    }
    if (adicionar_v2)
    {
        free(g->v[v2].vizinho);
        g->v[v2].vizinho = novos_vizinhos_v2;
        g->v[v2].qntsvizinhos++;
        g->v[v2].grau++;
    }

    g->mat[v1][v2] = 1;
    g->mat[v2][v1] = 1;
    g->arestas++;

    //MUDADO: retorna o grafo atualizado quando a ligação é criada.
    return g;
}