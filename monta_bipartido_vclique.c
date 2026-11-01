#include "grafo.h"
Grafo* monta_bipartido_vclique(Grafo* G)
{
    int V[G->vertices];
    Grafo* B=criar_grafo(G->vertices*2);
    nao_passou(G);
    // essa primeira parte define o primeiro vertice clique, pegando a primeira clique maximal.

    for(int i=0; i<G->vertices;i++)
    {
        if(!G->v[G->oep[i]].japassou)
        {
            for(int j=0; j<G->vertices; j++)
            {
                B->mat[G->vertices][j]=G->mat[G->oep[i]][j];
            }
            B->mat[G->vertices][G->oep[i]]=1;
        }
    }
    simetrizar_matriz_transposto(G->vertices*2,B->mat);
    //já separar todos os vertices que fazem parte do grafo G
    //ir olhando a ordem de eliminação perfeita e
        // pra cada vertice la, olha se já não há um vertice clique com ele dentro.
            // monta o vertice clique ( aumenta o grafo e adiciona ligações onde tem o vertice que usamos e os vizinhos dele)( isso sempre pelo triangulo superior)
            // simetriza a matriz.
        // se não
            // vai pro próximo vertice
        return B;
}