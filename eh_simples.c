#include "grafo.h"
int eh_simples(Grafo* G, int simples)
{   
    /* o simples precisa que um vizinho contenha o outro na vizinhança fechada*/

    // pra cada vizinho do suposto simples, tem que ver se esse vizinho contem 
    // a vizinhança dos outros vizinhos ou tem a vizinhança contida por outros vizinhos
    int res=0;
    
    if (G == NULL || G->v[simples].japassou == 1) 
    {
        return 0; 
    }
    
    for(int i=0;i<G->vertices;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(G->mat[simples][j] && G->mat[i][simples]&&G->v[i].japassou==0&&G->v[j].japassou==0)
            {//verifica se o simples conecta com i e j
                if(G->mat[i][j]==0)
                {//verifica se i e j tem conexao(se nao tem, entao ja nao eh simples)
                    return 0;
                }
                if(!(contem_vizinhanca(G,i,j)||contem_vizinhanca(G,j,i))){
                    return 0;
                }
            }

        }
    }   
    return 1;//retorna 1 caso ele seja simples(os vizinhos se veem)

}