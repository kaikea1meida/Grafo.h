#include "grafo.h"
#include<stdio.h>
int eh_fortemente_cordal(Grafo* g){
    Grafo* bvc=monta_bipartido_vclique(g);//monta o grafo com os vertices originais e as cliques maximais
    if(bvc==NULL)
    {
        return 0;
    }

    nao_passou(bvc);//zera o estado dos vertices, para uma busca limpa
    int eliminou_aresta=1;//controla as passagens pelo grafo bipartido
    while(eliminou_aresta)
    {
        eliminou_aresta=0;
        for(int i=0;i<bvc->vertices;i++)
        {
            for(int j=i+1;j<bvc->vertices;j++)
            {
                if(bvc->mat[i][j]&&eh_bisimplicial(bvc,i,j))//procura pares adjacentes bisimpliciais
                {
                    bvc->mat[i][j]=0;//elimina a aresta bisimplicial
                    bvc->mat[j][i]=0;//elimina a aresta do outro sentido
                    eliminou_aresta=1;
                }
            }
        }
    }

    int resultado=1;
    for(int i=0;i<bvc->vertices;i++)
    {
        for(int j=i+1;j<bvc->vertices;j++)
        {
            if(bvc->mat[i][j])//se sobrou aresta, nao conseguiu eliminar tudo
            {
                resultado=0;
                i=bvc->vertices;
                break;
            }
        }
    }

    libera_grafo(bvc);
    return resultado;
}