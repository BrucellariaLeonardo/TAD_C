#include "nodo.h"

struct NodoTest
{
    int dato;
    struct NodoTest *pNext;
};


NodoT* crearNodo(int dato)  //recibe el dato a almacenar y devuelve la direccion al nodo donde se almaceno el dato, si se falla creando el nodo se retorna NULL
{
    NodoT *nuevo = (NodoT*) malloc(sizeof(NodoT));
    if( nuevo != NULL)
    {
    nuevo->dato = dato;
    nuevo->pNext = NULL;
    }
    return nuevo;
}

int compararNodo(NodoT nodo1, NodoT nodo2)
{
    int ret = 0;
    if(nodo1.dato > nodo2.dato)
    {
        ret = 1;
    }else if (nodo1.dato < nodo2.dato)
    {
        ret = -1;
    }
    return ret;
}
