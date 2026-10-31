#include <stdlib.h>
#include "grafo.h"

void verifica_vizinhos(Grafo *G, int vertice)
{
    int i = vertice, j = 0, k = 0;
    if (G == NULL||G->v[i].vizinho != NULL) 
    {
        return;
    }

    for (j = 0; j < G->vertices; j++)
    {
        if (G->mat[i][j] && G->v[j].japassou == 0)// se eu já n eliminei ele no eep e se ele
        {// não é o simplicial que eu to olhando agora
            int* temp = (int*)realloc(G->v[i].vizinho,(k+1) * sizeof(int));// tem q ser um temp
            // pq se não, se n der pra fazer o realloc ele faz o ponteiro que recebe ele receber NULL e ai a
            // gente perde o ponteiro pra memória original, oq da vazamento de memória, no inicio eu n entendi
            // o pq de precisar ser temp tbm n
            if (temp == NULL)// ai verifica se só o temp é NULL, mesmo se ele for, oq eu tinha antes continua la
            {
                exit(1);// exit com 1 que significa falha
            }

            G->v[i].vizinho = temp; // faz uma mudança com temp pra se deu certo ele ficar alterado
            G->v[i].vizinho[k] = j;// adiciona o valor de j que é o tal vizinho no valor alocado

            k++;// vai pro próximo k, pra fazer um novo malloc
            G->v[i].qntsvizinhos = k;// aumenta a quant de vizinhos
            G->v[i].grau = k;// aumenta o grau pq ele conecta com mais um na vdd
            // grau!= quantidade de vizinhos (pensando nos multigrafos)
        }
    }
}
/*
grafo

v1 vizinho1, vizinho2, vizinho3, vizinho4,
temp = vizinho1, vizinho2, vizinho3, vizinho4 + , vizinho
v1 = temp = vizinho1, vizinho2, vizinho3, vizinho4, vizinho
v1 vizinho= j
v1 vizinho1, vizinho2, vizinho3, vizinho4, vizinhoj

v2 vizinho1, vizinho2, vizinho3,
v3
v4
v5
v6
*/