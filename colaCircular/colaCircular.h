#ifndef colaArray_h
#define colaArray_h
#include <stdlib.h>

typedef int DatoT;
struct colaCircular
{
    DatoT *elementos;
    int frente;
    int final;
    int max;
};
typedef struct  colaCircular* colaCircularT;


/*crea una cola Vacia
@return cola creada*/
colaCircularT qc_crear(int  max);

/*
@return 1 en caso de que este vacia y 0 en caso contrario*/
int qc_vacia( colaCircularT cola);

/*
@return 1 en caso de que este vacia y 0 en caso contrario*/
int qc_llena( colaCircularT cola);

/// @brief consulta el largo de la cola
/// @param cola cola a consultar
/// @return Retorna la cantidad de elementos almacenados en la cola
int qc_getLen ( colaCircularT cola);

/*Inserta un nodo al tope de una cola
@param cola cola en la que se va a insertar el nodo
@param nodoNuevo nodo a insertar
@return 1 operacion exitosa,
@return 0 operacion fallida*/
int qc_push(colaCircularT cola, DatoT datoNuevo );

/// @brief saca y retorna el elemento superior de la cola
/// @param cola sobre la que operar
/// @return elemento superior de la cola, en caso underflow se corta la ejecucion del programa
DatoT qc_pop(colaCircularT cola);

/*obtiene el nodo del tope de una cola, pero no lo saca de la cola
@param cola cola en la que se va a insertar el nodo
@return la direccion del nodo obtenido,
@return NULL en caso de no haber podido obtener ningunn nodo*/
DatoT qc_top(colaCircularT cola);

/*Vacia la cola
@param cola cola a ser vaciada
@return 1 en caso de exito y 0 en caso de fallo*/
void qc_vaciar( colaCircularT cola);

void qc_free(colaCircularT cola);
#endif