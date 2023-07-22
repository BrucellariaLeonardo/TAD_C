#ifndef listaEnlazada_h
#define listaEnlazada_h
#include <stdlib.h>
#include "nodo.h"

typedef struct  ListaEnlazada ListaEnlazadaT;

ListaEnlazadaT crearLista(); //retorna una lista 
int insertarPrimero(ListaEnlazadaT lista, NodoT *nodoNuevo );


#endif