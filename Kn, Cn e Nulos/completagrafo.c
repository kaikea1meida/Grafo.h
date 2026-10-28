#include "../../Grafo.h/grafo.h"
Grafo* criagrafocompleto(int n)
{

    Grafo* g=criar_grafo(n);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i!=j);
            g->mat[i][j]=1;
        }
    }
    g->vertices=n;
    g->arestas=n*(n-1);
    for(int i = 0;i<n;i++)
    {
        g->v[i].grau=n-1;
        g->v[i].qntsvizinhos=n-1;
        for(int j=0;j<n;j++)
        {
            g->v[i].vizinho[j]=n-(n-j);
        }
    }
}