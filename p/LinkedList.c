#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNodae(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));//creo el linkedList en memoria LOCOMOTORA
    if(this!=NULL)
    {
        this->size = 0;//Inicializo en el primer elemento pq no hay ninguno
        this->pFirstNode = NULL; // apunto a null para que pueda engancharse
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(this->size == 0)//Si solo esta la locomotora y no tiene otro vagon el ll_len devuelve 0
        {
           returnAux = 0;
        }
        else{
             returnAux = this->size;//En caso de que no este solo la locomotara, devolvera la cantidad de locomotoras enganchadas
        }
    }
    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;//Creo un nodo en null por si no hay vagones, puedo devolver un null
    int contador = 0;
    if(this !=NULL && (nodeIndex < ll_len(this) && nodeIndex >= 0))//Me fijo con el len de que haya vagones
    {
        pNode = this->pFirstNode;//Como hay vagones apunto el nodo al primer vagon de la locomotora,inicializo
        while(contador < nodeIndex)
        {
            pNode = pNode->pNextNode;//Me muevo por el array hasta que encuentro el nodo que quiere el usuario(nodeIndex)
            contador++;
        } //Y se lo asigno, que se ejecute hasta que encuentra el indice que quiere
    }
    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this,int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    Node* nuevoNodo = NULL;

    if(this!=NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if(nuevoNodo !=NULL)//Me fijo si se pudo construir
        {
            nuevoNodo->pElement = pElement; //Cargo el vagon, con el elemento que me pasaron
            if(nodeIndex == 0)
            {
                nuevoNodo->pNextNode = this->pFirstNode; //Nuevo nodo tiene que enganchar vagon 0, copiar la direccion de memoria del que ya esta enganchado en esa posicion para no perderlo
                this->pFirstNode = nuevoNodo;//Engancho el primer elemento a la locomotora
            }
            else{
                prev = getNode(this,nodeIndex-1);//Le pido a getnode que me de la direccion de memoria del vagon que esta antes del que me quiero meter
                nuevoNodo->pNextNode = prev->pNextNode;//Mi nuevo vagon apunta al anterior
                prev->pNextNode = nuevoNodo;//Enganchar el que estaba antes al nuevo
            }
            this->size++;//Como aumento la cantidad de vagones, aumento el size de la locomotora
            returnAux = 0;
        }
    }
    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this,ll_len(this),pElement);
}

void* ll_get(LinkedList* this, int index)
{
    Node* pNodo = NULL;
    void* returnAux = NULL;
    if(this != NULL && index >=0 && index < ll_len(this))
    {
        pNodo = getNode(this,index);
        if(pNodo != NULL)//importante validar que no devuelva null
        {
            returnAux = pNodo->pElement;//Devuelve la ubicacion de la carga
        }
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;

    if(this != NULL && index >= 0 && index< ll_len(this))
    {
        actual = getNode(this,index);
        if(actual !=NULL)
        {
            actual->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* anterior;
    Node* actual;
    //int indice = 0;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        actual = getNode(this,index);
        if(index == 0)
        {
            if(actual !=NULL)
            {
                this->pFirstNode = actual->pNextNode;//Asigno el siguiente nodo del vagon a la locomotora para no romper la cadena de enganches.
            }
        }
        else{
            anterior = getNode(this,index-1);
            if(anterior !=NULL)
            {
                anterior->pNextNode = actual->pNextNode;//Asigno el pNex node del vagon que voy a eliminar al que esta atras para no romper la cadena de enganches.
            }
        }
        free(actual);//Libero la memoria del vagon que quiero eliminar.
        this->size--;//Como tengo un vagon menos achico el tama�o del size.
        returnAux = 0;
    }
    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        while(ll_len(this) != 0)//Mientras queden elementos remove, siempre elimina el vagon 0.
        {
            ll_remove(this,0);
        }
        returnAux = 0;
    }
    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this !=NULL)
    {
        if(!ll_clear(this))//Si el clear logro eliminar todos los elementos devuelve 0 los niego y entro al if para liberar
        {
            free(this);
            returnAux = 0;
        }
    }
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        int len = ll_len(this);//Lo calculo aca para no estar llamando a la funcion cada vez que itera el for
        for(int i=0;i<len;i++)//Recorro la lista
        {
            if(ll_get(this,i) == pElement)//ll_get me devuelve un PElent con el cual puedo comparar
            {
                returnAux = i;
                break;//Pq se puede repetir el pElement
            }
        }
    }
    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;
        if(ll_len(this) == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this,index,pElement); //Add node devuelve lo mismo asique puedo hacer directamente un return
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >=0)
    {
        returnAux = ll_get(this,index);//Uso ll_get para obtener el pElement
        if(ll_remove(this,index))//si devuelve  -1 fallo
        {
            returnAux = NULL; //Por si falla al remover, hago que tire error.
        }
    }
    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this,pElement) != -1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* aux;
    if(this !=NULL && this2 != NULL)
    {
        returnAux = 0;
        int len = ll_len(this);
        for(int i=0;i<len;i++)
        {
            aux = ll_get(this2,i);
            if(!ll_contains(this,aux))
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement = NULL;
    if(this != NULL && from >=0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        LinkedList* nuevaLista = ll_newLinkedList();
        if(nuevaLista !=NULL)
        {
            for(i=from;i<=to;i++)
            {
                pElement = ll_get(this,i);
                ll_add(nuevaLista,pElement);
            }
        }
        cloneArray = nuevaLista;
    }
    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        cloneArray = ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    if(this !=NULL &&(order == 0 || order == 1)&&pFunc != NULL)
    {
       int len = ll_len(this);
       for(int i=0;i<len-1;i++)
       {
           for(int j=i+1;j<len;j++)
           {
               if(order == 1 && pFunc(ll_get(this,i),ll_get(this,j))>0)
               {
                   pAux = ll_get(this,i);
                   ll_set(this,i,ll_get(this,j));
                   ll_set(this,j,pAux);
               }
               else if(order == 0 &&pFunc(ll_get(this,i),ll_get(this,j))<0)
               {
                   pAux = ll_get(this,i);
                   ll_set(this,i,ll_get(this,j));
                   ll_set(this,j,pAux);
               }
           }
       }
       returnAux = 0;
    }
    return returnAux;
}
//AGREGADO
int ll_map(LinkedList* this,int (*pFunc)(void*))
{
    int estado = -1;
    int len;
    void* aux;
    if(this!=NULL && pFunc !=NULL)
    {
        len = ll_len(this);
        for(int i=0;i<len;i++)
        {
            aux = ll_get(this,i);
            if(pFunc(aux)>-1)
            {
                estado = 0;
            }
        }
    }
    return estado;
}
int ll_count(LinkedList* this,int(*fn)(void* element))
{
    int contador = 0;
    int len;
    void* aux;
    if(this !=NULL)
    {
        len = ll_len(this);
        for(int i=0;i<len;i++)
        {
            aux = ll_get(this,i);
            contador = contador + fn(aux);
        }
    }
    return contador;
}
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element,void* criterio),void* criterio)
{
    LinkedList* newList = ll_newLinkedList();
    void* aux;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        for(int i=0;i<len;i++)
        {
            aux = ll_get(this,i);
            if(fn(aux,criterio))
            {
                ll_add(newList,aux);
            }
        }
    }
    return newList;
}
//LinkedList* ll_filterV2(LinkedList* this, int (*fn)(void* element,void* criterio),void* criterio)
//LinkedList* ll_filterV2(LinkedList* this,int(*fn)(void* element))
LinkedList* ll_filterV2(LinkedList* this, int (*fn)(void* element,int criterio))
{
    LinkedList* newList = ll_newLinkedList();
    void* aux;
    int contador = 0;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        for(int i=0;i<len;i++)
        {
            aux = ll_get(this,i);
            if(fn(aux,contador) && contador !=3)
            {
                ll_add(newList,aux);
                contador++;
            }
        }
    }
    return newList;
}
