#ifndef listaEnlazada_h
#define listaEnlazada_h
#include <stdlib.h>
#include "nodo.h"

typedef struct  ListaEnlazada* ListaEnlazadaT;



/*crea una lista Vacia
@return lista creada*/
ListaEnlazadaT crearLista();

/*Retorna el largo de la lista
@param lista*/
int getLen (const ListaEnlazadaT lista);

/*Inserta un nodo al principio de una lista
@param lista lista en la que se va a insertar el nodo
@param nodoNuevo nodo a insertar
@return 1 operacion exitosa,
@return 0 operacion fallida*/
int insertarPrimero(ListaEnlazadaT lista, NodoT *nodoNuevo );

/*Inserta un nodo al final de una lista
@param lista lista en la que se va a insertar el nodo
@param nodoNuevo nodo a insertar
@return 1 operacion exitosa,
@return 0 operacion fallida*/
int insertarUltimo(ListaEnlazadaT lista, NodoT *nodoNuevo );

/*Inserta un nodo en la posicion indicada
@param lista lista en la que se va a insertar el nodo
@param nodoNuevo nodo a insertar
@param pos posicion en la que se desea insertar el nodo
@return 1 operacion exitosa,
@return 0 operacion fallida*/
int insertarPos(ListaEnlazadaT lista, NodoT *nodoNuevo, int pos );

/*Imprime el nodo de la posicion indicada
@param lista lista de la que se desea imprimir
@param pos posicion que desea imprimir
@return 1 operacion exitosa,
@return 0 operacion fallida*/
int printPos(const ListaEnlazadaT const lista, int pos);


/* Busca el nodo correspondiente a una posicion
@param lista lista en la que se debe buscar
@param pos posicion buscada de la lista
@return puntero al nodo de la posicion especificada, 
@retrun en caso de que el nodo no exista, se retrona un puntero a NULL
*/
NodoT* getPos(const ListaEnlazadaT lista, int pos);

/*Busca el nodo correspondiente a una posicion y sobreescribe su informacion
@param lista lista en la que se debe buscar
@param pos posicion buscada de la lista
@param dato dato que se quiere escribir
@return 1 en caso de exito,
@retrun 0 en caso de falla*/
int setPos(const ListaEnlazadaT lista, int pos, DatoT dato);

/*Inserta un nodo de forma ordenada
@param lista lista en la que se va a insertar el nodo
@param nodoNuevo nodo a insertar
@return 1 operacion exitosa,
@return 0 operacion fallida*/
int insertarOrdenado(ListaEnlazadaT lista, NodoT *nodoNuevo);

#endif