#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "gets.h"
void get_String(char string[],int len,char message[],char errorMessage[])
{
    printf("%s",message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    /*while(!isOnlyLetters(string))
    {
        printf("%s",errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }*/
}

int getInt(char mensaje[])
{
    char auxiliarChar[10];
    int enteroADevolver;

    printf("%s", mensaje);
    scanf("%s", auxiliarChar);
    fflush(stdin);
    enteroADevolver = atoi(auxiliarChar);

    while(enteroADevolver == 0)
    {
        printf("%s", "Valor invalido. Ingrese un numero \n");
        scanf("%s", auxiliarChar);
        fflush(stdin);
        enteroADevolver = atoi(auxiliarChar);
    }

    return enteroADevolver;

}


char getChar(char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}


float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}


void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);

  //  gets(input);
}

//////////////////////////////////////////////////////////////////
int new_get_Int(char mensaje[])
{
    char auxiliarChar[10];
    int enteroADevolver;

    printf("%s", mensaje);
    scanf("%s", auxiliarChar);
    fflush(stdin);
    enteroADevolver = atoi(auxiliarChar);

    while(enteroADevolver == 0)
    {
        printf("%s", "Valor invalido. Ingrese un numero \n");
        scanf("%s", auxiliarChar);
        fflush(stdin);
        enteroADevolver = atoi(auxiliarChar);
    }

    return enteroADevolver;

}
///////////////////////////////////
int getNumeroAleatorio(int desde , int hasta)
{
    int numero;
    numero = rand() % (desde-hasta+1) + desde;
    printf("%d\n",numero);
    return numero;
}
/*int numeroRandom()
{
    int numero[10];
    for(int i=0;i<10;i++)
    {
        numero[i] = rand() % 11;
        printf("El numero aleatorio es %d\n",numero[i]);
    }
    //printf("El numero aleatorio es %d",numero);
}
*/
int isOnlyLetters(char str[])
{
    int returnValue=1;

    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}
