#ifndef GRAFO_H
#define GRAFO_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct vert
{
        int* vizinho;// vetor com os vizinhos que já checamos até agora e botamos la
        int qntsvizinhos;
        int grau;
        int japassou;
}Vertice;

typedef struct graph 
{
        char nome[50];
        int** mat;// matriz de adjacência
        int vertices;// quant de vertice
        int arestas;// quant de aresta
        Vertice* v;// vetor que tem os vertices do grafo.

}Grafo;

/* o que precisa ter

função pra verificar se é fortemente cordal

###função pra adicionar vertices a um grafo e definir as ligações que ele faz###

funções pra fazer grafos como:
Completos
nulos
ciclos

função pra fazer união, join e conexão de grafos

função pra citar os vertices e botar do lado quem ele faz conexão



interfaçe visual pra isso*/
Grafo* criar_grafo(int n);
Grafo* altera_tamanho_grafo(Grafo* g, int Nnovo);
Grafo* nulificar_grafo(Grafo* g);
Grafo* criar_grafo_completo(int n);
Grafo* criar_ciclo(int n);
Grafo* ligar_vertice(Grafo* g, int v1, int v2);
void libera_grafo(Grafo* g);
void imprime_grafo(Grafo* g);
int eh_fortemente_cordal(Grafo* g);
int eh_simplicial(Grafo* g,int simplicial);
int eh_simples(Grafo* G,int simples);
void verifica_vizinhos(Grafo *G, int vertice);
int eep(Grafo *G,int vertices_restante, int* ordem, int posicao,int falhas);
void copiar_matriz(Grafo* g,int matriz[g->vertices][g->vertices]);
void printar_resultado(Grafo* g);
int eh_simetrica(int ordem, int mat[ordem][ordem]);
void simetrizar_matriz(int ordem, int mat[ordem][ordem]);
void printa_grafo(Grafo* g);
void nao_passou(Grafo* g);
int main2(void);
#endif


/*

        { 0, 1, 1, 0, 1, 0, 1, 1}
        { 1, 0, 1, 1, 0, 1, 0, 1}
        { 1, 1, 0, 1, 1, 0, 1, 0}
        { 0, 1, 1, 0, 1, 1, 0, 1}
        { 1, 0, 1, 1, 0, 1, 1, 0}
        { 0, 1, 0, 1, 1, 0, 1, 1}
        { 1, 0, 1, 0, 1, 1, 0, 1}  
        { 1, 1, 0, 1, 1, 1, 1, 0}


4-sol      1  2  3  4  5  6  7  8
        1{ 0, 1, 1, 1, 1, 0, 0, 1 } 
        2{ 1, 0, 1, 1, 1, 1, 0, 0 }
        3{ 1, 1, 0, 1, 0, 1, 1, 0 }
        4{ 1, 1, 1, 0, 0, 0, 1, 1 }
        5{ 1, 1, 0, 0, 0, 0, 0, 0 }
        6{ 0, 1, 1, 0, 0, 0, 0, 0 }
        7{ 0, 0, 1, 1, 0, 0, 0, 0 }
        8{ 1, 0, 0, 1, 0, 0, 0, 0 }

        { 0, 1, 0, 0, 0, 1 }
        { 1, 0, 1, 0, 0, 0 }
        { 0, 1, 0, 1, 0, 0 }
        { 0, 0, 1, 0, 1, 0 }
        { 0, 0, 0, 1, 0, 1 }
        { 1, 0, 0, 0, 1, 0 }
*/