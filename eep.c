#include "grafo.h"

int eep(Grafo *G,int vertices_restante, int* ordem, int posicao,int falhas) 
{
    if (G == NULL||falhas==(vertices_restante-1)) 
    { 
        return 0; 
    }
    if (vertices_restante <= 3)//se tiver menos de 4 vertices
    {
        for (int i = 0; i < G->vertices; i++)// passa pelos 3 vertices ou menos e bota eles no eep
            {
                if (G->v[i].japassou == 0)
                    {
                        ordem[posicao++] = i; 
                    } 
            } 
        return 1;// e retorna que é cordal
    }

    int i=0;
    for(i=0;i<G->vertices;i++)// ve a linha toda
    {
        if(G->v[i].japassou==0)
        {
            if(eh_simplicial(G,i))
            {// aqui é a verificação de olhar se os vizinhos do vertice que é vizinho do simplicial tem a mesma vizinhança do simplicial - esse vizinho que está sendo verificado
                G->v[i].japassou=1;
                ordem[posicao]=i;
                return eep(G, vertices_restante - 1, ordem, posicao + 1,0);
            }
            else
            {
                falhas++;
                if (falhas == (vertices_restante - 1)) 
                {
                    return 0;
                }
            }
        }
    }
    return 0;
        
}
    

    /* G é o ponteiro pro grafo.
    vertices_restantes é o tamanho/ ordemda matriz atual( do subgrafo atual) e me mostra quantos vertices ainda tenho que olhar
    ordem: vetor que vai receber a ordem de eliminação perfeita, vamos gravar nele os vertice eliminados ordem[posição]=i
    posicao: é em q posição esse vertice ta, então se botou algum vertice na ordem tem q atualizar posicao
    
    */

    // essa função tem que retornar 1 se for simplicial.

    /* retornar 1 se chegar um grafo com 3 vertices

    ver quantas vezes falhou pra mandar essa informação pro próximo ( se falhou n-1 vezes já não é cordal, pq n tem como ter só um simplicial)

    ve de 0 a G->vertices-1

    verifica se japassou==1 ( é um vertice eliminado pelo eep)

    se japassou!=0 ( não verificou ele ainda)
        japassou=1
        ordem[pos]=i

        return eep(G,vertice_restante-1,ordem,pos+1);

    */
