#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "envios.h"
#include "menus.h"
int main()
{
    LinkedList* listaEnvios = ll_newLinkedList();
    if(listaEnvios!=NULL)
    {
        opciones_principales_linkedList(listaEnvios);
    }
    else
    {
        printf("No hay espacio en memoria para crear la lista\n");
    }
    printf("Hello world!\n");
    return 0;
}

