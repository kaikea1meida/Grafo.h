#include "grafo.h"
void nao_passou(Grafo* g)
{// desativa o parametro "japassou" dos vertices do grafo, é ideal usar depois de cada eep ou eepf,
 //  também algumas outras funções que serao adicionadas.
 
    for(int i=0;i<g->vertices;i++)
    {
        g->v->japassou=0;
    }
}