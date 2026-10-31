#include "grafo.h"

int verifica_ocorrencia(Grafo* G,int x,int y,int vizinhos[G->v[x].qntsvizinhos+G->v[y].qntsvizinhos],int ocorrido)
{
    for(int i=0;i<G->v[x].qntsvizinhos+G->v[y].qntsvizinhos;i++)
    {
        if(vizinhos[i]==ocorrido)
        {
            return ;
        }
    }
    return 0;
}

int eh_bissimplicial(Grafo* G, int x,int y)
{
    // for que fvoer a linha do simplicial e toda vez que for 1 verifica:
    //se o tal vertice tem PELOMENOS os vizinhos que o simplicial tem (descontando ele mesmo)
    // fazer isso pra todos os vertices da linha do simplicial que tem numero 1.
    int vizinhos[G->v[x].qntsvizinhos+G->v[y].qntsvizinhos];
    int i;
    int qtdvizinhos=0;
    for(i=0;i<G->vertices;i++)
    {
        if(G->mat[x][i])
        {
            vizinhos[i]=1;
            qtdvizinhos++;
        }
    }
    for(int j=i;j<G->vertices;j++)
    {
        if(!verifica_ocorrencia(G,x,y,vizinhos,j))
        {
            vizinhos[j]=1;
            qtdvizinhos++;
        }
    }
    
    Grafo *temp=criar_grafo(qtdvizinhos); 
    if (G == NULL || G->v[x].japassou == 1||G->v[y].japassou == 1) 
    {
        return 0; 
    }
    for(int i=0;i<G->vertices;i++)
    {
        for(int j=i+1;j<G->vertices;j++)
        {
            if(G->mat[x][j]||G->mat[i][y])
            {
                temp->mat[i][j]=1;
            }
        }
    }   
    return 1;
}

/*
0 0 0 1 1 1 
0 0 0 1 1 1 
0 0 0 1 1 1 
1 1 1 0 0 0 
1 1 1 0 0 0 
1 1 1 0 0 0 
*/