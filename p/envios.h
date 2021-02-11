#ifndef ENVIOS_H_INCLUDED
#define ENVIOS_H_INCLUDED

typedef struct
{
    int idEnvios;
    int anioNacimiento;
    char nombre[51];
    int puntaje;
}Envios;

#endif // ENVIOS_H_INCLUDED

Envios* envios_new();
Envios* envios_newParametros(char* idStr,char* anioNacimiento,char* nombre/*,char* dni,char* fechaPresentacion,char* tema*/,char* puntaje);
int envios_setId(Envios* this,int id);
int envios_getId(Envios* this,int* id);
int envios_setNombre(Envios* this,char* nombre);
int envios_getNombre(Envios* this,char* nombre);
int envios_setAnioNacimiento(Envios* this,int anioNacimiento);
int envios_getAnioNacimiento(Envios* this,int* anioNacimiento);
int envios_setPuntaje(Envios* this,int puntaje);
int envios_getPuntaje(Envios* this,int* puntaje);
/////
///////
int controller_enviosSaveAsText(char* path,Envios* dato);
