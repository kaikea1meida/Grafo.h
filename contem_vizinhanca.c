#include "grafo.h"
int contem_vizinhanca(Grafo* g,int v1, int v2)
{

    //verificar se v1 esta contido em v2!!!!
    int contem=0;
    if(g->v[v1].qntsvizinhos>g->v[v2].qntsvizinhos)
        return 0;
    for(int i=0;i<g->v[v1].qntsvizinhos;i++)
    {
        for(int j=0;j<g->v[v2].qntsvizinhos;j++)
        {
            if(g->v[v2].vizinho[j]==g->v[v1].vizinho[i]){
                contem++;
            }
        }  

    }
    if(contem==g->v[v1].qntsvizinhos)
        return 1;
    return 0;

}





/*







int contem_vizinhanca(Grafo* g,int v1)
{
    int contem=0;
    k=0;
for(int i=k;i<g->v[v1].qntsvizinhos;i++)
    {
        for(int j=k;j<g->v[v2].qntsvizinhos;j++)
        {
        for(int p=0; )[
            for[
                if(g->v[g->v[v1].vizinho[i]].qntsvizinhos > g->v[g->v[v1].vizinho[j]].qntsvizinhos  g->v[g->v[v1].vizinho[i]].qntsvizinhos < g->v[g->v[v1].vizinho[j]].qntsvizinhos)
                g->v[g->v[v1].vizinho[i]].vizinho[p] = g->v[g->v[v1].vizinho[j]].vizinho[Q]
            ]
            ]


            }
        }  

    }
}



*/