#include "grafo.h"

int verifica_ocorrencia(Grafo* G,int x,int y,int vizinhos[G->v[x].qntsvizinhos+G->v[y].qntsvizinhos],int ocorrido);

int eh_bissimplicial(Grafo* G, int x,int y)
{
    int vizinhos[G->v[x].qntsvizinhos+G->v[y].qntsvizinhos];// forma um vetor com o tamanho dos vizinhos de x e de y
    // pra formar o SUPOSTO bipartido completo
    int i;
    int qtdvizinhos=0;
    for(i=0;i<G->vertices;i++)// pra uma linha inteira da matriz
    {
        if(G->mat[x][i])// se o vertice x ve alguem do y
        {
            vizinhos[i]=1;//esse indice almenta no vetor? ( não entendi o pq desse, me explica pfv)
            qtdvizinhos++;// aumenta os vizinhos
        }
    }
    for(int j=i;j<G->vertices;j++)//CARACA ENTENDI! É DAONDE VC CONTINUOU ANTES? kasdka vc podia ter feito um if.
                                  // Olha as linhas 4 6 e 14 do eh_bipartido_completo
    {
        if(!verifica_ocorrencia(G,x,y,vizinhos,j))// se não tiver ocorrência de j vc adiciona o jota??
        {
            vizinhos[j]=1; // define ele como vizinho
            qtdvizinhos++;//  e aumenta os vizinhos???w Não entendi nada agr vc adiciona ele como vizinho se ele não ta no vetor?
        }
    }
    // pra esses 2 fors de cima, voce bota os vizinhos deles num vetor ( do x é só ver os vizinhos dele mesmo e do y é)

    Grafo *temp=criar_grafo(qtdvizinhos);
    if (G == NULL || G->v[x].japassou == 1||G->v[y].japassou == 1) 
    {
        return 0; 
    }

    for(int i=0;i<G->vertices;i++)
    {
        for(int j=i+1;j<G->vertices;j++)// pro triangulo superior todo
        {
            if(G->mat[x][j]||G->mat[i][y]) // se um for 1 ou se o outro for 1 a matriz é 1? acho que eu entendi,
            // mas vou precisar que desenhe pra eu compreender. Eu vi q tem algum sentido, mas n entendi pq faz sentido
            {
                temp->mat[i][j]=1;
            }
        }
    }   
    return 1;
}

/*
0 0 0 1 1 1 
0 0 0 1 1 1 
0 0 0 1 1 1 
1 1 1 0 0 0 
1 1 1 0 0 0 
1 1 1 0 0 0 
*/
int verifica_ocorrencia(Grafo* G,int x,int y,int vizinhos[G->v[x].qntsvizinhos+G->v[y].qntsvizinhos],int ocorrido)
{
    for(int i=0;i<G->v[x].qntsvizinhos+G->v[y].qntsvizinhos;i++)
    {
        if(vizinhos[i]==ocorrido)// oqq é ocorrido?
        {
            return 1;
        }
    }
    return 0;
}