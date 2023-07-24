#include "colaEnlazada.h"

//constantes para finalizacion inesperada
#define COL_VACIA 3
struct colaEnlazada
{
int len;
NodoT *pPrimero;
NodoT *pUtimo;
};

colaEnlazadaT c_crearCola()  
{
    colaEnlazadaT colaNueva = (colaEnlazadaT) malloc(sizeof(struct colaEnlazada));
    colaNueva->len = 0;
    colaNueva->pPrimero = NULL;
    colaNueva->pUtimo = NULL;
    return colaNueva;
}

int c_getLen (const colaEnlazadaT cola)
{
    return cola->len;
}
int c_vacia(const colaEnlazadaT cola)
{
    if(cola->len == 0)
    {
        return 1;
    }else{
        return 0;
    }
}


int c_push(colaEnlazadaT cola, DatoT datoNuevo )
{
    int exito = 1; //flag para indicar fallo al insertar el nodo
    NodoT *nodoNuevo = newNodo(datoNuevo);
    if(nodoNuevo != NULL) //si el nodo es valido
    {
        if(cola->len == 0) //si la cola esta vacia, el ultimo tambien es el primero
        {
            cola->pPrimero = nodoNuevo;
        }else{
        setNext(cola->pUtimo, nodoNuevo);

        }
        cola->pUtimo = nodoNuevo;
        cola->len++;
        
    }else exito = 0;
    return exito;
}

DatoT c_pop(colaEnlazadaT cola)
{
    NodoT* elemento = NULL;
    DatoT res;
    if(cola->pPrimero == NULL) //me fijo que la cola no este vacia
    {
        exit(COL_VACIA);
    }else{
        elemento = cola->pPrimero;
        cola->pPrimero = getNext(cola->pPrimero);
        cola->len--;
        res = getDato(elemento);
        free(elemento);
        if(cola->len == 0) //Si vacie la cola, me aseguro que el ultimo este apuntando a null;
        {
            cola->pUtimo = NULL;
        }
    }
    return res;

}

DatoT c_top(colaEnlazadaT cola)
{
    DatoT dato;
    if(cola->pPrimero == NULL) //me fijo que la cola no este vacia
    {
        exit(COL_VACIA);
    }else
    {
    dato = getDato(cola->pPrimero);

    }
    return dato;
}

void c_vaciarCola(const colaEnlazadaT cola)
{
    NodoT *nodo;
    while(cola->pPrimero != NULL)
    {
        nodo = cola->pPrimero;
        cola->pPrimero = getNext(cola->pPrimero);
        freeNodo(nodo);
        cola->len--;
    }
    cola->pUtimo = NULL;
    return;
}
