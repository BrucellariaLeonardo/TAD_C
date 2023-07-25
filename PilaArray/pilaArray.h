#ifndef pilaArray_h
#define pilaArray_h
#include <stdlib.h>

typedef int DatoT;
struct pilaArray
{
    DatoT *elementos;
    int tope;
    int max;
};
typedef struct  pilaArray* pilaArrayT;


/*crea una pila Vacia
@return pila creada*/
pilaArrayT p_crearPila(int  max);

/*
@return 1 en caso de que este vacia y 0 en caso contrario*/
int p_vacia( pilaArrayT pila);

/*
@return 1 en caso de que este vacia y 0 en caso contrario*/
int p_llena( pilaArrayT pila);

/// @brief consulta el largo de la pila
/// @param pila pila a consultar
/// @return Retorna la cantidad de elementos almacenados en la pila
int p_getLen ( pilaArrayT pila);

/*Inserta un nodo al tope de una pila
@param pila pila en la que se va a insertar el nodo
@param nodoNuevo nodo a insertar
@return 1 operacion exitosa,
@return 0 operacion fallida*/
int p_push(pilaArrayT pila, DatoT datoNuevo );

/// @brief saca y retorna el elemento superior de la pila
/// @param pila sobre la que operar
/// @return elemento superior de la pila, en caso underflow se corta la ejecucion del programa
DatoT p_pop(pilaArrayT pila);

/*obtiene el nodo del tope de una pila, pero no lo saca de la pila
@param pila pila en la que se va a insertar el nodo
@return la direccion del nodo obtenido,
@return NULL en caso de no haber podido obtener ningunn nodo*/
DatoT p_top(pilaArrayT pila);

/*Vacia la pila
@param pila pila a ser vaciada
@return 1 en caso de exito y 0 en caso de fallo*/
void p_vaciarPila( pilaArrayT pila);

void p_free(pilaArrayT pila);
#endif