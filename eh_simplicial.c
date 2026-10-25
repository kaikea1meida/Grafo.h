#include "grafo.h"
int eh_simplicial(Grafo* G, int simplicial)
{
    // for que fvoer a linha do simplicial e toda vez que for 1 verifica:
    //se o tal vertice tem PELOMENOS os vizinhos que o simplicial tem (descontando ele mesmo)
    // fazer isso pra todos os vertices da linha do simplicial que tem numero 1.
    if (G == NULL || G->v[simplicial].japassou == 1) 
    {
        return 0; 
    }
    
    for(int i=0;i<G->vertices;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(G->mat[simplicial][j] && G->mat[i][simplicial]&&G->v[i].japassou==0&&G->v[j].japassou==0)
            {//verifica se o simplicial conecta com i e j
                if(G->mat[i][j]==0)
                {//verifica se i e j tem conexao(se nao tem, entao ja nao eh simplicial)
                    return 0;
                }

            }

        }
    }   
    return 1;//retorna 1 caso ele seja simplicial(os vizinhos se veem)

}