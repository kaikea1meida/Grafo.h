#include "grafo.h"
#include <stdio.h>
#include <string.h>
#define quartoze 14
int main2()
{

    int teste[9][9] =
    {
    {0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0}
    };

    Grafo* g = criar_grafo(9);
    copiar_matriz(g,teste);
    
    
    strcpy(g->nome,"teste");
        if(g==NULL)
        {exit(1);}

        printar_resultado(g);

        if(eh_simetrica(9,teste))
        {
            printf("eh simetrica.");
        }
        else
        {
            printf("nao eh simetrica, vou simetrizar:\n");
            simetrizar_matriz(9,teste);
            copiar_matriz(g,teste);
            printa_grafo(g);
        }
        libera_grafo(g);
        
}