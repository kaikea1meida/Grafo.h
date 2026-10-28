#include "../../Grafo.h/grafo.h"

Grafo* cria_ciclo(int n)
{
    if(n<3)
    {
        return NULL;
    }
        Grafo* g=criar_grafo(n);
        if(g==NULL)
        {
            return NULL;
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0; j<n; j++)
            {
                if((i!=j)&& ((i==j+1)||(i+1==j)||((i==0||j==0)&&(i==(n-1)||j==(n-1)))))
                // muitas condições:
                // se o i for diferente de j ( não é a diagonal principal)
                // se o i for igual a j+1 ou se o j for igual ao i+1 (elementos k,k+1 e k+1,k), que são as diagonais coladas na principaç
                // a condição de i ou j ser 0 e i ou j ser n-1, que significa as pontas, suiperior direita e inferior esquerda.
                g->mat[i][j]=1;
            }
        }
        g->vertices=n;
        g->arestas=n;// mesma quant de aresta doq de vertices pq é um ciclo
        for(int i = 0;i<n;i++)
        {
            g->v[i].grau=2;// cada vertice só ve 2 vizinhos ent tem grau 2
            g->v[i].qntsvizinhos=2;
                if(g->v[i].vizinho==NULL)
                {
                    g->v[i].vizinho=(int*)calloc(2,sizeof(int));// cada vertice tem 2 vizinhos no ciclo, ent vou botar 2 no calloc
                }
                if(i==0)// se fo o primeiro vertice ele tem que se conectar com o ultimo
                {
                    g->v[i].vizinho[0]=n-1;
                    g->v[i].vizinho[1]=1;
                }
                else if(i==(n-1))// se for o ultimo vertice ele tem q se conectar com o primeiro
                {
                    g->v[i].vizinho[0]=0;
                    g->v[i].vizinho[1]=n-2;
                }
                else// qualquer um do meio conecta com o antes e o depois dele
                {
                    g->v[i].vizinho[0]=i-1;
                    g->v[i].vizinho[1]=i+1;
                }
        }
    return g;
}

