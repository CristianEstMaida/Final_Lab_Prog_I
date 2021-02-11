#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "LinkedList.h"
#include "Controller.h"
#include "gets.h"
#include "envios.h"

int menuPrincipal()
{
    int opcion;
    printf("FINAL LAB NUMERO:\n\n");
    printf("1-Cargar los datos de los envios desde el archivo data.csv (modo texto)\n");
    printf("2-Listar envios\n");
    printf("3-Generar un archivo por cada elemento que cumpla la funcion anterior\n");
    printf("4-Salir\n");
    printf("Ingrese una opcion:");
    scanf("%d",&opcion);
    return opcion;
}

int menuModificar()
{
    int opcion;
    system("cls");
    printf("MODIFICAR EMPLEADO:\n\n");
    printf("1-Normal\n");
    printf("2-Express\n");
    printf("3-Segun disponibilidad\n");
    printf("4-Salir\n");
    opcion = new_get_Int("Ingrese una opcion:");

    return opcion;
}
void opciones_principales_linkedList(LinkedList* listaEnvios)
{
    char path[25];
    //char newPath[] = "resultado ";
    int flag = 0;
    int option;
    do{
        option = menuPrincipal();
        switch(option)
        {
            case 1:
                if(flag == 0)
                {
                    get_String(path,25,"Ingrese el nombre del archivo csv desde el cual leera los datos:","Ese nombre es incorrecto,reingrese nombre:");
                    controller_loadFromText(path,listaEnvios);
                    //controller_loadFromText("MOCK_DATA_final.csv",listaEnvios);
                    flag = 1;
                    system("pause");
                }
                else{
                    printf("Ya se cargaron datos\n");
                    system("pause");
                }
                break;
            case 2:
                if(flag == 1)
                {
                    controller_ListEnvios(listaEnvios);
                    system("pause");
                }
                else{
                    printf("Primero cargue los datos\n");
                    system("pause");
                }
                break;
            case 3:
                if(flag == 1)
                {
                    controller_enviosSaveAsText(path, listaEnvios);
                    printf("MEJORADO...\n");
                    system("pause");
                }
                else{

                    system("pause");
                }
                break;
            case 4:
                printf("Gracias por usar el programa\n");
                break;
        }
        system("cls");
    }while(option != 12);
}

