#include "grafo.h"
    
void printar_resultado(Grafo*g)
    {
        int ordem[g->vertices];
        if(g==NULL||g->mat==NULL||g->nome==NULL||ordem==NULL)
        {exit(1);}
        
        printf("grafo: %s\n\nmatriz de adjacencia:\n",g->nome);
        for(int i=0;i<g->vertices;i++)
        {
            for(int j = 0; j<g->vertices; j++)
            {
                printf(" %d ",g->mat[i][j]);
            }
            printf("\n");
        }

        if(eepf(g,g->vertices,ordem,0,0))
        {
            printf("o grafo %s eh fortemente cordal!!\n a sua ordem de eliminacao perfeita eh:\n\n",g->nome);
            for(int j = 0; j<g->vertices; j++)
            {
                printf("%d ",(ordem[j]+1));
            }
        }
        else
        {
            printf("o grafo %s nao eh fortemente cordal.",g->nome);
        }
        printf("\n\n");
    }