#include "grafo.h"
int eh_vizinhanca_aninhada(Grafo* g,int v1, int v2)
{
    if(v1==v2)
    {
        return 1;
    }
    //verificar se v1 contem a vizinhança de v2
    int excedente=0;
    // se, pra todo vertice j que ainda não passou, de 0 até o maximo de vertices, j não nem for v1 nem v2 (soma) e, se v2 é vizinho de j, então v1 também é (subtrai), a vizinhança é aninhada, se o excedente de vizinhos for 0.
    for(int j=0;j<g->vertices;j++)// pra todo j referente a 0 até ao máximo de vertices
    {
        if(j!=v1&&j!=v2&&g->v[j].japassou==0)//se ele não é v1, nem v2 e não passou
        {
            excedente++;//( aqui eu to fazendo um tipo de confirmação, eu somando quando é vizinho de v2 e
            //                   tirando se ele for vizinho de v1, pq se sobrarem mais doq 0, então tem algum que é vizinho de v2 mas não é de v1)
            if((!g->mat[v2][j]||g->mat[v1][j]))// se ele é vizinho de v2 então ele é vizinho de v1 (não, ou)
            {
                excedente--;
            }
        /*
            excedente+=g->mat[v2][j]; // tem essa opção que eu pensei tbm, soma a vizinhança de v2, ( se não for vizinho vai somar 0)
            if((g->mat[v2][j]&&g->mat[v1][j])) // se for vizinho dos 2 então tira
            {
                excedente--;
        }*/
        }
    }
    if(excedente==0)
    {
        return 1;
    }
    return 0;

}
/*
3-Sol
0 1 1 1 0 1
1 0 1 1 1 0
1 1 0 0 1 1
1 1 0 0 0 0
0 1 1 0 0 0 
1 0 1 0 0 0

K3, todos se veem(1, 2 e 3)
0 1 1  1 0 1 o primeiro ve 2 pontas (3 e 5)
1 0 1  1 1 0 o segundo ve 2 (3 e 4)
1 1 0  0 1 1 o terceiro ve 2 (4 e 5)

1 1 0  0 0 0 nenhum dos 3 se ve (3, 4 e 5)
0 1 1  0 0 0 
1 0 1  0 0 0
o 3 ve 2,(0 e 1)
o 4 ve 2, (1 e 2)
o 5 ve 2, (0 e 2)
*/