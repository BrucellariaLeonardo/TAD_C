#include "pilaEnlazada.h"

struct pilaEnlazada
{
int len;
NodoT *pPrimero;
//NodoT *pUtimo;
};

pilaEnlazadaT p_crearPila()  
{
    pilaEnlazadaT pilaNueva = (pilaEnlazadaT) malloc(sizeof(struct pilaEnlazada));
    pilaNueva->len = 0;
    pilaNueva->pPrimero = NULL;
    return pilaNueva;
}

int p_getLen (const pilaEnlazadaT pila)
{
    return pila->len;
}
int p_vacia(const pilaEnlazadaT pila)
{
    if(pila->len == 0)
    {
        return 1;
    }else{
        return 0;
    }
}


int p_push(pilaEnlazadaT pila, NodoT *nodoNuevo )
{
    int exito = 1; //flag para indicar fallo al insertar el nodo
    if(nodoNuevo != NULL) //si el nodo es valido
    {
        setNext(nodoNuevo, pila->pPrimero);
        pila->pPrimero = nodoNuevo;
        pila->len++;
    }else exito = 0;
    return exito;
}

NodoT* p_pop(pilaEnlazadaT pila)
{
    NodoT* elemento = NULL;
    if(pila->pPrimero != NULL) //me fijo que la pila no este vacia
    {
        elemento = pila->pPrimero;
        pila->pPrimero = getNext(pila->pPrimero);
        pila->len--;
    }
    return elemento;
}

NodoT* p_top(pilaEnlazadaT pila)
{
    NodoT* elemento = NULL;
    if(pila->pPrimero != NULL) //me fijo que la pila no este vacia
    {
        elemento = pila->pPrimero;
    }
    return elemento;
}

void p_vaciarPila(const pilaEnlazadaT pila)
{
    NodoT *nodo;
    while(pila->pPrimero != NULL)
    {
        nodo = pila->pPrimero;
        pila->pPrimero = getNext(pila->pPrimero);
        freeNodo(nodo);
        pila->len--;
    }
    return;
}
