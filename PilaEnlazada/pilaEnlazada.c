#include "pilaEnlazada.h"

//constantes para finalizacion inesperada
#define PIL_VACIA 2
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


int p_push(pilaEnlazadaT pila, DatoT datoNuevo )
{
    int exito = 1; //flag para indicar fallo al insertar el nodo
    NodoT *nodoNuevo = newNodo(datoNuevo);
    if(nodoNuevo != NULL) //si el nodo es valido
    {
        setNext(nodoNuevo, pila->pPrimero);
        pila->pPrimero = nodoNuevo;
        pila->len++;
    }else exito = 0;
    return exito;
}

DatoT p_pop(pilaEnlazadaT pila)
{
    NodoT* elemento = NULL;
    DatoT res;
    if(pila->pPrimero == NULL) //me fijo que la pila no este vacia
    {
        exit(PIL_VACIA);
    }else{
        elemento = pila->pPrimero;
        pila->pPrimero = getNext(pila->pPrimero);
        pila->len--;
        res = getDato(elemento);
        free(elemento);
    }
    return res;

}

DatoT p_top(pilaEnlazadaT pila)
{
    NodoT* elemento = NULL;
    if(pila->pPrimero != NULL) //me fijo que la pila no este vacia
    {
        elemento = pila->pPrimero;
    }
    return getDato(elemento);
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
