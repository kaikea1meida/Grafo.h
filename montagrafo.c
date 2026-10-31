#include "grafo.h"
void montagrafo(Grafo* G, char matriz[4098])
{ 
    int ordem;
    for(int i=0;matriz[i]!='\0'||matriz[i]!='\n';i++)
    {
        if(matriz[i]=='0'||matriz[i]==1)
        {
            ordem++;
        }
    }

    for(int i=0;matriz[i]!='\0'||matriz[i]!='\n';i++)
    {
        for(int j=0;matriz[j]!='\0'||matriz[j]!='\n';j++)
        {
            //G->mat=
        }
    }
}