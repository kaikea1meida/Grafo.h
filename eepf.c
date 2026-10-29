#include "grafo.h"

int eepf(Grafo *G, int vertices_restante, int* ordem, int posicao, int falhas) 
{
    if(G == NULL || falhas == (vertices_restante - 1)) { return 0;}

    if(vertices_restante <= 3) //se tiver menos de 4 vertices
    {
        for(int i = 0; i < G->vertices; i++) // passa pelos 3 vertices ou menos e bota eles no eep
        {
            if(G->v[i].japassou == 0)
            {
                ordem[posicao++] = i; 
            } 
        } 
        return 1; // e retorna que é cordal
    }

    int i = 0;
    for(i = 0; i < G->vertices; i++) // ve a linha toda
    {
        if(G->v[i].japassou == 0)
        {
            if(eh_simples(G, i))
            {// aqui é a verificação de olhar se os vizinhos do vertice que é vizinho do simplicial tem a mesma vizinhança do simplicial - esse vizinho que está sendo verificado
                G->v[i].japassou = 1;
                ordem[posicao] = i;
                return eepf(G, vertices_restante - 1, ordem, posicao + 1, 0);
            }
            else
            {
                // Se não for simples, apenas continuamos procurando na mesma rodada.
                // O controle de falha total é feito se o loop acabar sem achar nenhum simplicial.
            }
        }
    }

    // Se o loop acabou e nenhum vértice da rodada era simples, o grafo travou e não é cordal.
    return 0;
}