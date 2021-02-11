#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "envios.h"


int parser_enviosFromText(FILE* pFile , LinkedList* pListaEnvios)
{
    Envios* auxEnvios = envios_new();
    int r;
    int i = 0;
    char idAux[50];
    char anioNacimientoAux[50];
    char nombreAux[50];
    char puntaje[50];

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",idAux,anioNacimientoAux,nombreAux,puntaje);
    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",idAux,anioNacimientoAux,nombreAux,puntaje);
        if(r==7)
        {
            auxEnvios = envios_newParametros(idAux,anioNacimientoAux,nombreAux, puntaje);
            ll_add(pListaEnvios,auxEnvios);
            i++;
        }
    }
    printf("Se cargaron %d envios a la lista en modo texto\n",i);
    return i;

}
