#include "grafo.h"
#include <stdio.h>
#define ORDEM 10
int main()
{
    int ordem[ORDEM];
    int matriz[ORDEM][ORDEM] = 
    {
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

    Grafo* g = criar_grafo(ORDEM);
    
    // Corrigido j<0 para j<ORDEM
    for(int i = 0; i < ORDEM; i++)
    {
        for(int j = 0; j < ORDEM; j++)
        {
            g->mat[i][j] = matriz[i][j];
        }
    }
    
    int cordal = eep(g, ORDEM, ordem, 0, 0);

    if(cordal)
    {
        printf("o grafo eh cordal hahahahhaha\n");
        for(int i=0;i<ORDEM;i++)
        {
            printf("%d",ordem[i]);
        }
    }
    else 
    {
        printf("num eh nao\n");
    }

    // Libertar a memória alocada antes de fechar o programa
    libera_grafo(g);

    return 0;
}
/*    
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}*/