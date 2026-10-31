#include "grafo.h"
#include<stdio.h>
int eh_fortemente_cordal(Grafo* g){
    //JUNTA AS FUNCOES MONTA VERTICE CLIQUE E EH BISIMPLICIAL, NO GERAL ERA SO PRA UNIR TUDO E VER SE IA RETORNAR O VALOR CERTO PRA SABER A FORTE CORDALIDADE
    Grafo* bvc=monta_bipartido_vclique(g);
    int ordem[bvc->vertices];
    int k=0;
  
    
    for(int i=0;i<bvc->vertices;i++){
        if(bvc->v[i].japassou==1)
            continue;
        for(int j=i+1;j<bvc->vertices;j++){
            if(bvc->v[j].japassou==1)
                continue;
            if(eh_bisimplicial(bvc,i,j)){
                ordem[k++]=i;
                ordem[k++]=j;
                bvc->v[i].japassou=1;
                bvc->v[j].japassou=1;
                i=-1;
                break;
            }
        }   
    }
    if(k<bvc->vertices){
        libera_grafo(bvc);
        return 0;
    }
    libera_grafo(bvc);
    return 1;

}