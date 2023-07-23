#ifndef NODO_H
#define NODO_H
#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo NodoT; //alias para el nombre del nodo, en caso de querer implementar otro nodo sse cambia NodoTest por el nombre del nodo nuevo
typedef int DatoT; //alias para los campos de datos del nodo

/*Crea un nodo y retorna su direccion de memoria
@param dato dato a guardar en el nodo
@return direccion del nodo creado, en caso de no haber creado el nodo retorna NULL*/
NodoT* newNodo(DatoT dato);  

/*Muestra la informacion de un nodo
@param *nodo direccion del nodo que se desea mostrar*/
void printNodo(NodoT *nodo);

/*Cambia la direccion a la que apunta el nodo
@param *nodo direccion del nodo que se quiere editar
@param *next direccion del nodo al que se quiere apuntar*/
void setNext(NodoT *nodo, NodoT *next);

/*obtine la direccion a la que apunta el nodo recibido
@param *nodo direccion del nodo que se quiere consultar
@return nodo al que apunta el nodo consultado*/
NodoT* getNext(NodoT *nodo);

/*Cambia el dato almacenado por el nodo
@param *nodo direccion del nodo que se quiere editar
@param dato dato a guardar*/
void setDato(NodoT *nodo, DatoT dato);

/*obtine el dato almacenado por un nodo
@param *nodo direccion del nodo que se quiere consultar
@return dato del nodo*/
DatoT getDato(NodoT *nodo);

/*compara dos nodos
@param nodo1 direccion del primer nodo a comparar
@param nodo2 direccion del segundo nodo a comprar
@return 1 en caso de que nodo1 sea mayor
@return 0 en caso de que los nodos sean iguales
@return -1 en caso de que nodo2 sea mayor*/
int compNodo(NodoT *nodo1, NodoT *nodo2);

/*libera le memoria utilizada por un nodo
@param *nodo direccion del nodo a eliminar*/
void freeNodo(NodoT *nodo);
#endif