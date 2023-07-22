#ifndef NODO_H
#define NODO_H
#include <stdlib.h>
#include <stdio.h>

typedef struct NodoTest NodoT; //alias para el nombre del nodo, en caso de querer implementar otro nodo sse cambia NodoTest por el nombre del nodo nuevo

NodoT* crearNodo(int dato);  //recibe el dato a almacenar y devuelve la direccion al nodo donde se almaceno el dato, si se falla creando el nodo se retorna NULL
int compararNodo(NodoT nodo1, NodoT nodo2);
/*Retorna 1 en caso de que nodo1 sea mayor
  Retorna 0 en caso de que los nodos sean iguales
  Retorna -1 en caso de que nodo2 sea mayor
*/

#endif