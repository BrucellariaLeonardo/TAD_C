#include "listaEnlazada.h"

struct ListaEnlazada
{
int len;
NodoT *pPrimero;
NodoT *pUtimo;
};


ListaEnlazadaT crearLista() //retorna una lista 
{
    ListaEnlazadaT listaNueva;
    listaNueva.len = 0;
    listaNueva.pPrimero = listaNueva.pUtimo = NULL;
    return listaNueva;
}

int insertarPrimero(ListaEnlazadaT lista, NodoT *nodoNuevo )
{
    lista.pPrimero = nodoNuevo;
    NodoT *nodito = crearNodo(3);
}