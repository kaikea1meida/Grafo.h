#include "../grafo.h"
Grafo* criar_grafo_completo(int n)
{

    if(n<0)
    {
        return NULL;
    }
    if(n==0)
    {
        Grafo* g=criar_grafo(n);
        if(g==NULL)
        {
            return NULL;
        }
        return g;
    }

    Grafo* g=criar_grafo(n);
    if(g==NULL)
    {
        return NULL;
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i!=j)
            {
                g->mat[i][j]=1;
            }
        }
    }
    g->vertices=n;
    g->arestas=(n*(n-1))/2;// de acordo com o o teorema do aperto de mão.
    for(int i = 0;i<n;i++)
    {
        g->v[i].grau=n-1;// todos menos ele mesmo
        g->v[i].qntsvizinhos=n-1;
        g->v[i].vizinho = (int*)calloc(n - 1, sizeof(int));// malloca cada vizinho que eu vou botar
        int k = 0;
        for (int j=0;j<n;j++)
        {       
            if(j!=i)
            {
                g->v[i].vizinho[k] = j; // ele ve tudo menos ele mesmo, pra todos os vertices, se não for ele, tem ligação
                k++;
            }
        }
    }
    return g;
}