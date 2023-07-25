#ifndef AAB_H
#define ABB_H
#include <string.h>
#include <stdio.h>

typedef int elemento;

typedef struct Nodo{
    struct Nodo *pizq;
    struct Nodo *pder;
    elemento dato;
    //int cont;
}TNodo;

typedef TNodo* TArbol;

// Crea un �rbol binario de b�squeda con un �nico nodo (ra�z) cuyo elemento es el par�metro dato. Hijos izquierdo y derecho son �rboles vac�os (NULL).
TArbol crearArbol(elemento x);

// Inserta el elemento x al �rbol binario de b�squeda pasado como par�metro. Pre condici�n: el par�metro arbol es un ABB. Post condici�n: luego de la operaci�n arbol debe ser un ABB.
int insertarElemento(TArbol *arbol, elemento x);

// Realiza el recorrido InOrder imprimiendo sus elementos.
void inOrder(TArbol arbol);

/// @brief Recorre el arbol en busca de un elemento
/// @param arbol arbol sobre el que se realiza la busqued
/// @param buscado elemento que se busca
/// @return retorna TRUE si el elemento se encuentra en el arbol
int existeElemento(TArbol arbol, elemento buscado);

//void buscarMaxOcurrencias(TArbol arbol, char* palabra, int* cont);
//void buscarMinOcurrencias(TArbol arbol, char* palabra, int* cont);

//retorna la cantidad de ocurrencias de la palabra recibida
//int buscarPalabra(TArbol arbol, char* dato);

//borra el arbol
void borrarArbol(TArbol arbol);

/// @brief Elimina el elemento que contiene el dato indicado
/// @param arbol arbol en el que se realiza la eliminacion
/// @param dato dato a eliminar
/// @return 
int eliminarElemento(TArbol *arbol, elemento dato);


#endif