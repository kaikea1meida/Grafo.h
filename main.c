#include "grafo.h"
#include <stdio.h>
int main()
{
int matriz[10][10] = {
    /*     0  1  2  3  4  5  6  7  8  9 */
    /*0*/ {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    /*1*/ {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    /*2*/ {1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    /*3*/ {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
    /*4*/ {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
    /*5*/ {0, 0, 0, 1, 1, 0, 1, 1, 0, 0},
    /*6*/ {0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
    /*7*/ {0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
    /*8*/ {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    /*9*/ {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}
};

Grafo* g=cria_grafo(10);
for(int i=0;i<10;i++){
    for(int j=0;j<0;j++){
    g->mat[i][j]=matriz[i][j];
}
}
int cordal=eep(g,10,NULL,0,0);


if(cordal){
    printf("o grafo eh cordal hahahahhaha");
}
else 
    printf("num eh nao");
}