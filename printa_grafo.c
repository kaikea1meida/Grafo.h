#include "grafo.h"
#include <stdio.h>
void printa_grafo(Grafo* g)
{
    printf("\n");
for(int i=0;i<g->vertices;i++){
    for(int j=0;j<g->vertices;j++){
        printf("%d  ",g->mat[i][j]);
    }
    printf("\n");
}
}