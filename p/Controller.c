#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
//#include "get.h"
#include "menus.h"
#include "Controller.h"
#include "envios.h"
//#include "gets.h"

int controller_loadFromText(char* path ,LinkedList* pEnvios)
{
    int estado = 0;
    FILE *pArchivo;
    if((pArchivo = fopen(path,"r"))==NULL)
    {
        printf("Error de lectura...\n");
    }
    else{
        parser_enviosFromText(pArchivo,pEnvios);
        estado = 1;
    }
    return estado;
}

int controller_ListEnvios(LinkedList* pArrayListEnvios)
{
    system("cls");
    printf("Listado de concursantes:\n\n");
    Envios* pEnviosAux;
    int estado = 0;
    int idAux,anioNacimientoAux,dniAux,puntajeAux;
    char nombreAux[50];
    char fechaPresentacionAux[50];
    char temaAux[50];
    int len = ll_len(pArrayListEnvios);
    if(pArrayListEnvios !=NULL && len >0)
    {
        printf("Id------AnioNacimiento-----Nombre-----Puntaje\n");
        for(int i =0;i<len;i++)
        {
            pEnviosAux = ll_get(pArrayListEnvios,i);
            envios_getId(pEnviosAux,&idAux);
            envios_getAnioNacimiento(pEnviosAux,&anioNacimientoAux);
            envios_getNombre(pEnviosAux,nombreAux);
            envios_getPuntaje(pEnviosAux,&puntajeAux);
            printf("%d  %15d  %15s  %15d\n",idAux,anioNacimientoAux,nombreAux,puntajeAux);
        }
        estado = 1;
    }
    else{
        printf("No se puede mostrar la lista, primero cargue algun empleado\n");
    }
    return estado;
}


int controller_enviosSaveAsText(char* path,Envios* dato)
{
    int estado = 0;
    FILE* pArchivo;
    pArchivo = fopen(path,"w");
    int id,anioNacimiento,puntaje;
    char nombre[50];


    if(pArchivo !=NULL)
    {
        envios_getId(dato,&id);
        envios_getAnioNacimiento(dato,&anioNacimiento);
        envios_getNombre(dato,nombre);
        envios_getPuntaje(dato,&puntaje);
        fprintf(pArchivo,"%d,%d,%s,%d\n",id,anioNacimiento,nombre,puntaje);
        fclose(pArchivo);
        estado = 1;
    }
    return estado;
}
