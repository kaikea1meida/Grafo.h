#include "grafo.h"
    
void printar_resultado(Grafo* g)
    {
        int ordem[g->vertices];
        if(g==NULL||g->mat==NULL||g->nome==NULL||ordem==NULL)
        {exit(1);}
                printf("##################################################################################################");
                printf("\n");
        printf("grafo: %s\n\nmatriz de adjacencia:\n",g->nome);
        for(int i=0;i<g->vertices;i++)
        {
            for(int j = 0; j<g->vertices; j++)
            {
                printf(" %d ",g->mat[i][j]);
            }
            printf("\n");
        }
        int eh_cordal = eep(g,g->vertices,ordem,0,0); // trocado da linha 28
        if(eh_cordal && eh_fortemente_cordal(g)) // trocado da linha 19
        {
            printf("o grafo %s eh fortemente cordal!!\n a sua ordem de eliminacao perfeita forte eh:\n\n",g->nome);
            for(int j = 0; j<g->vertices; j++)
            {
                printf("%d ",(ordem[j]+1));
            }
            printf("\n");
        }
        else if(eh_cordal) // trocado da linha 28
        {
            printf("o grafo %s nao eh fortemente cordal, mas eh cordal e a sua ordem de eliminacao perfeita eh:\n\n",g->nome);
            for(int j = 0; j<g->vertices; j++)
            {
                printf("%d ",(ordem[j]+1));
            }
            printf("\n");
        }
        else
        {
            printf("o grafo %s nao eh nem cordal e muito menos fortemente cordal...\n",g->nome);
        }
        printf("##################################################################################################");
        printf("\n\n");
    }