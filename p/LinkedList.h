#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct Node
{
    void* pElement;//Direccion de memoria de cualquier cosa ej mascota,int,motos, etc
    struct Node* pNextNode;//Direccion de memoria del nodo que viene atras(Al que se engancha)
}typedef Node;//VAGON

struct LinkedList
{
    Node* pFirstNode;//Primer nodo ->Apunta al primer vagon
    int size;//Cantidad de elementos
}typedef LinkedList;//LOCOMOTORA



#endif // LINKEDLIST_H_INCLUDED

//Publicas
LinkedList* ll_newLinkedList(void);

int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
/////////////////////////////////AGREGADO
int ll_map(LinkedList* lista,int (*pFunc)(void*));
void opciones_principales_linkedList(LinkedList* listaEnvios);

int ll_count(LinkedList* this,int(*fn)(void* element));
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element,void* criterio),void* criterio);

LinkedList* ll_filterV2(LinkedList* this, int (*fn)(void* element,int criterio));
