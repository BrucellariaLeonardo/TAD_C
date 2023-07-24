#ifndef colaEnlazada_h
#define colaEnlazada_h
#include <stdlib.h>
#include "nodo.h"

typedef struct  colaEnlazada* colaEnlazadaT;



/*crea una cola Vacia
@return cola creada*/
colaEnlazadaT c_crearCola();

/*
@return 1 en caso de que este vacia y 0 en caso contrario*/
int c_vacia(const colaEnlazadaT cola);

/*Retorna el largo de la cola
@param cola */
int c_getLen (const colaEnlazadaT cola);

/*Inserta un nodo al tope de una cola
@param cola cola en la que se va a insertar el nodo
@param datoNuevo dato a insertar
@return 1 operacion exitosa,
@return 0 operacion fallida*/
int c_push(colaEnlazadaT cola, DatoT datoNuevo );

/*saca un nodo del tope de una cola
@param cola cola de la que se va a obtener el dato
@return dato en el tope de la cola*/
DatoT c_pop(colaEnlazadaT cola);

/*obtiene el nodo del tope de una cola, pero no lo saca de la cola
@param cola cola de la que se va a obtener el dato
@return dato en el tope de la cola*/
DatoT c_top(colaEnlazadaT cola);

/*Vacia la cola
@param cola cola a ser vaciada
@return 1 en caso de exito y 0 en caso de fallo*/
void c_vaciarCola(const colaEnlazadaT cola);
#endif