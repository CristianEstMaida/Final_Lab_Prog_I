#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "envios.h"
#include "LinkedList.h"
#include "gets.h"
#include "Controller.h"
Envios* envios_new()
{
    Envios* pEnvios;
    pEnvios = (Envios*) calloc(sizeof(Envios),1);
    return pEnvios;
}
Envios* envios_newParametros(char* idStr,char* anioNacimiento,char* nombre,char* puntaje)
{
    Envios* auxiliarEnvios = envios_new();

    if(auxiliarEnvios != NULL)
    {
        int id = atoi(idStr);
        envios_setId(auxiliarEnvios,id);

        int anio_Nacimiento = atoi(anioNacimiento);
        envios_setAnioNacimiento(auxiliarEnvios,anio_Nacimiento);

        int nombre = atoi(nombre);
        envios_setNombre(auxiliarEnvios,nombre);

        int puntaje_int = atoi(puntaje);
        envios_setPuntaje(auxiliarEnvios,puntaje_int);
    }
    return auxiliarEnvios;


    return 0;
}
int envios_setId(Envios* this,int id)
{
    int set = 0;
    if(this !=NULL && id>0)
    {
        this->idEnvios = id;
        set = 1;
    }
    return set;
}
int envios_getId(Envios* this,int* id)
{
    int estado = 0;
    if(this !=NULL && id != NULL)
    {
        *id = this ->idEnvios;
        estado = 1;
    }

    return estado;
}
int envios_setNombre(Envios* this,char* nombre)
{
    int estado = 0;
    if(this != NULL && nombre != NULL)
    {
        if(strlen(nombre)!=0)
        {
            strcpy(this->nombre,nombre);
            estado = 1;
        }
    }
    return estado = 0;
}
int envios_getNombre(Envios* this,char* nombre)
{
    int estado = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        estado = 1;
    }
    return estado;
}
int envios_setAnioNacimiento(Envios* this,int anioNacimiento)
{
    int estado = 0;
    if(this != NULL && anioNacimiento > 0)
    {
        this ->anioNacimiento = anioNacimiento;
        estado = 1;
    }
    return estado;
}
int envios_getAnioNacimiento(Envios* this,int* anioNacimiento)
{
    int estado = 0;
    if(this != NULL)
    {
        *anioNacimiento = this ->anioNacimiento;
        estado = 1;
    }
    return estado;
}

int envios_setPuntaje(Envios* this,int puntaje)
{
    int estado = 0;
    if(this != NULL && puntaje > 0)
    {
        this ->puntaje = puntaje;
        estado = 1;
    }
    return estado;
}
int envios_getPuntaje(Envios* this,int* puntaje)
{
    int estado = 0;
    if(this != NULL)
    {
        *puntaje = this ->puntaje;
        estado = 1;
    }
    return estado;
}

