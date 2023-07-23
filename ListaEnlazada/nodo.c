#include "nodo.h"

struct NodoTest
{
    DatoT dato;
    struct NodoTest *pNext;
};


NodoT* newNodo(DatoT dato)  //recibe el dato a almacenar y devuelve la direccion al nodo donde se almaceno el dato, si se falla creando el nodo se retorna NULL
{
    NodoT *nuevo = (NodoT*) malloc(sizeof(NodoT));
    if( nuevo != NULL)
    {
    nuevo->dato = dato;
    nuevo->pNext = NULL;
    }
    return nuevo;
}

void printNodo(NodoT *nodo)
{
    printf("Dato:\t%d\n", nodo->dato);
    return;
}

void setNext(NodoT *nodo, NodoT *next)
{
    nodo->pNext = next;
    return;
}

NodoT* getNext(NodoT *nodo)
{
    return nodo->pNext;
}

void setDato(NodoT *nodo, DatoT dato)
{
    nodo->dato = dato;
}

DatoT getDato(NodoT *nodo)
{
    return nodo->dato;
}

int compNodo(NodoT *nodo1, NodoT *nodo2)
{
    int ret = 0;
    if(nodo1->dato > nodo2->dato)
    {
        ret = 1;
    }else if (nodo1->dato < nodo2->dato)
    {
        ret = -1;
    }
    return ret;
}

void freeNodo(NodoT *nodo)
{
    free(nodo);
}

