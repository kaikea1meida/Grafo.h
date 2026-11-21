#include "grafo.h"

int vertice_no_clique(int* clique,int tamanho,int vertice)
{
    //verifica se o vertice ja esta na clique candidata
    for(int i=0;i<tamanho;i++)
    {
        if(clique[i]==vertice)
        {
            return 1;
        }
    }
    return 0;
}

int eh_clique(Grafo* G,int* clique,int tamanho)
{
    //verifica se todos os vertices candidatos se veem
    for(int i=0;i<tamanho;i++)
    {
        for(int j=i+1;j<tamanho;j++)
        {
            if(G->mat[clique[i]][clique[j]]==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int eh_clique_maximal(Grafo* G,int* clique,int tamanho)
{
    //uma clique maximal nao pode receber mais nenhum vertice
    for(int i=0;i<G->vertices;i++)
    {
        if(vertice_no_clique(clique,tamanho,i))
        {
            continue;
        }
        int liga_com_todos=1;
        for(int j=0;j<tamanho;j++)
        {
            if(G->mat[i][clique[j]]==0)
            {
                liga_com_todos=0;
                break;
            }
        }
        if(liga_com_todos)
        {
            return 0;
        }
    }
    return 1;
}

void percorre_cliques(Grafo* G,int* clique,int tamanho,int inicio,Grafo* B,int* quantidade)
{
    //forma todas as cliques possiveis e guarda as maximais no grafo bipartido
    for(int i=inicio;i<G->vertices;i++)
    {
        clique[tamanho]=i;
        int novo_tamanho=tamanho+1;
        if(eh_clique(G,clique,novo_tamanho))
        {
            if(eh_clique_maximal(G,clique,novo_tamanho))
            {
                if(B!=NULL)
                {
                    int clique_bipartido=G->vertices+*quantidade;//indice do vertice-clique no bipartido
                    for(int j=0;j<novo_tamanho;j++)
                    {
                        int vertice=clique[j];
                        B->mat[vertice][clique_bipartido]=1;//liga vertice a sua clique
                        B->mat[clique_bipartido][vertice]=1;//mantem a matriz simetrica
                    }
                }
                (*quantidade)++;
            }
            percorre_cliques(G,clique,novo_tamanho,i+1,B,quantidade);
        }
    }
}

Grafo* monta_bipartido_vclique(Grafo* G)
{
    if(G==NULL)
    {
        return NULL;
    }

    int clique[G->vertices];
    int quantidade=0;
    percorre_cliques(G,clique,0,0,NULL,&quantidade);

    Grafo* B=criar_grafo(G->vertices+quantidade);
    if(B==NULL)
    {
        return 0;
    }

    quantidade=0;
    percorre_cliques(G,clique,0,0,B,&quantidade);
    return B;
}