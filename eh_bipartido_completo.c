#include "grafo.h"
int eh_bipartido_completo(Grafo*b)
{
    for(int i=0;i<b->vertices;i++)// for que vai do inicio ao fim
    {
        if(i<(b->vertices+1)/2)// if que só conta a primeira metade ( arredondando pra cima)
        {
            for(int j=(b->vertices+1)/2;j<b->vertices;j++)
            {
                if(b->mat[i][j]==0)
                {return 0;}
            }
        }
        if(i>(b->vertices+1)/2)// if que so conta a segunda metade ( arredondando pra cima)
        {
            for(int j=0;j<(b->vertices+1)/2;j++)
            {   
                if(b->mat[i][j]==0)
                {return 0;}
            }
        }
    }
    return 1;
}