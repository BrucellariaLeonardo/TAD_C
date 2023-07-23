#ifndef pilaEnlazada_h
#define pilaEnlazada_h
#include <stdlib.h>
#include "nodo.h"

typedef struct  pilaEnlazada* pilaEnlazadaT;



/*crea una pila Vacia
@return pila creada*/
pilaEnlazadaT p_crearPila();

/*
@return 1 en caso de que este vacia y 0 en caso contrario*/
int p_vacia(const pilaEnlazadaT pila);

/*Retorna el largo de la pila
@param pila*/
int p_getLen (const pilaEnlazadaT pila);

/*Inserta un nodo al tope de una pila
@param pila pila en la que se va a insertar el nodo
@param nodoNuevo nodo a insertar
@return 1 operacion exitosa,
@return 0 operacion fallida*/
int p_push(pilaEnlazadaT pila, DatoT datoNuevo );

/*saca un nodo del tope de una pila
@param pila pila en la que se va a insertar el nodo
@return la direccion del nodo obtenido,
@return NULL en caso de no haber podido obtener ningunn nodo*/
DatoT p_pop(pilaEnlazadaT pila);

/*obtiene el nodo del tope de una pila, pero no lo saca de la pila
@param pila pila en la que se va a insertar el nodo
@return la direccion del nodo obtenido,
@return NULL en caso de no haber podido obtener ningunn nodo*/
DatoT p_top(pilaEnlazadaT pila);

/*Vacia la pila
@param pila pila a ser vaciada
@return 1 en caso de exito y 0 en caso de fallo*/
void p_vaciarPila(const pilaEnlazadaT pila);
#endif