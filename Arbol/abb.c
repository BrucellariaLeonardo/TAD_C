#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

//////////////////////////////////////////Funciones intertas///////////////////////////////////////////
TNodo *crearNodo(elemento dato)
{ //crea un nodo, inicializa el contador en 1
    TNodo *nodoNuevo;
    nodoNuevo = (TNodo *)malloc(sizeof(TNodo));   //se asigna memoria para el nodo nuevo
    //nodoNuevo->dato = malloc(sizeof(elemento)*strlen(dato));
    //strcpy(nodoNuevo->dato, dato);
    nodoNuevo->dato = dato;
    //nodoNuevo->cont = 1;                                //se setea el conteo inicial
    nodoNuevo->pder = NULL;              
    nodoNuevo->pizq = NULL;
    return nodoNuevo;
}

/// @brief compara dos nodos
/// @param n1 nodo 1
/// @param n2 nodo 2
/// @return 1 en caso de que n1 sea mayor, -1 en caso de que n2 sea mayor y 0 si son iguales
int compararElemento(elemento a, elemento b)
{
    if(a > b)
    {
        return 1;
    }else if(a < b)
    {
        return -1;
    }else{
        return 0;
    }   
}
void printNodo(TNodo nodo)
{
    printf("Bit: %d\n", nodo.dato);
}

void freeNodo(TNodo *nodo)
{
    free(nodo);
    return;
}

void setNodo(TNodo *nodo, elemento dato)
{
    nodo->dato = dato;
}

//recibe un arbol, un contador y un puntero donde guardar un string.//Retorna en palabra la palabra que aparece mas veces y en cont cuantas veces aparece
/*void MaxOcurrencias(TArbol arbol, char* palabra, int* cont)
{
    if (arbol == NULL)  //si el arbol no tiene nada
    {
        printf("Sin palabras."); 
    }
    if (arbol->pizq != NULL)
    {                         //si tengo elementos anteriores (sub arbol izquierdo)
        MaxOcurrencias(arbol->pizq, palabra, cont); //reviso el sub arbol izquierdo
    }
    if(arbol->cont > *cont) //si la palabra actual, aparecio mas veces que la que tengo registrada
    {
        //actualizo la palabra con mas ocurrenicas
        strcpy(palabra, arbol->dato);
        *cont = arbol->cont;
    }
    if (arbol->pder != NULL)
    {                         //si tengo elementos posteriores (sub arbol derecho)
        MaxOcurrencias(arbol->pder, palabra, cont);  //reviso el subarbol derecho
    }
    return;
}*/

//recibe un arbol, un contador y un puntero donde guardar un string.//Retorna en palabra la palabra que aparece menos veces y en cont cuantas veces aparece
/*void MinOcurrencias(TArbol arbol, char* palabra, int* cont) 
{
    if (arbol == NULL)
    {
        printf("Sin palabras.");
    }
    if (arbol->pizq != NULL)
    {                         //si tengo elementos anteriores (sub arbol izquierdo)
        MinOcurrencias(arbol->pizq, palabra, cont); 
    }
    if(arbol->cont < *cont) //si la palabra actual, aparecio menos veces que la que tengo registrada
    {
        //actualizo la palabra con mas ocurrenicas
        strcpy(palabra, arbol->dato);
        *cont = arbol->cont;
    }
    if (arbol->pder != NULL)
    {                         //si tengo elementos posteriores (sub arbol derecho)
        MinOcurrencias(arbol->pder, palabra, cont); 
    }
    return;
}*/

/////////////////////////////////////////Funciones de usuario//////////////////////////////////////////

//crea el arbol y retona la raiz
TArbol crearArbol(elemento x)
{ 
    return crearNodo(x);
}

int insertarElemento(TArbol *arbol, elemento dato)
{
    if (*arbol == NULL){ //Si el arbol/subarbol esta vacio inserto el elemnto
        *arbol = crearNodo(dato);
        if (*arbol == NULL){ //compruebo si se aloco correctamente el nodo.
            printf("fallo al insertar el nodo.");
            return 0;
        }
    }else if (compararElemento(dato, (*arbol)->dato) <= 0){      //si el dato es menor que el elemento de la raiz
        insertarElemento(&(*arbol)->pizq, dato);
    }else{      //si el dato es mayor que el elemento de la raiz
        insertarElemento(&(*arbol)->pder, dato);
    }
    return 1;
}

void inOrder(TArbol arbol)
{
    if (arbol == NULL)
    {
        printf("Sin palabras.");
    }
    if (arbol->pizq != NULL)
    {                         //si tengo elementos anteriores (sub arbol izquierdo)
        inOrder(arbol->pizq); //los imprimo
    }
    printNodo(*arbol);
    if (arbol->pder != NULL)
    {                         //si tengo elementos posteriores (sub arbol derecho)
        inOrder(arbol->pder); //los imprimo
    }
    return;
}

int existeElemento(TArbol arbol, elemento buscado)
{
    if (arbol == NULL) //condicion base
    {
        return 0;
    }else if(compararElemento(arbol->dato, buscado) == 0)
    {
        return 1;
    }else if (compararElemento(arbol->dato, buscado) > 0)
    {
        return existeElemento(arbol->pizq, buscado); //los imprimo

    }else
    {
        return existeElemento(arbol->pder, buscado); //los imprimo
    }
}

int eliminarElemento(TArbol *arbol, elemento dato)
{
    if (*arbol == NULL) //condicion base
    {
        return 0;
    }else if(compararElemento((*arbol)->dato, dato) > 0)
    {
        return eliminarElemento(&(*arbol)->pizq, dato); 
    }else if (compararElemento((*arbol)->dato, dato) < 0)
    {
        return eliminarElemento(&(*arbol)->pder, dato); 
    }else{
        TArbol victima;
        victima = *arbol;
        if(victima->pizq == NULL){
            *arbol = victima->pder;
        }else if (victima->pder == NULL){
            *arbol = victima->pizq;
        }else{
            TArbol anterior, mayorDeMenores;
            anterior = victima;
            mayorDeMenores = victima->pizq;
            while (mayorDeMenores->pder != NULL) //me posiciono en el mayor de los hijos menores de la victima y en padre de el mayor de los menores
            {
                anterior = mayorDeMenores;
                mayorDeMenores = mayorDeMenores->pder;
            }
            setNodo(victima, mayorDeMenores->dato); //si no itere el while, estoy borrando ell nodo de la izquierda
            if(anterior = victima)
            {
                anterior->pizq = mayorDeMenores->pizq;
            }else{  //si itere borro el nodo de la derecha
                anterior->pder = mayorDeMenores->pizq;
            }
            victima = mayorDeMenores;
        }
        freeNodo(victima);
        return 1;
    }
}


void borrarArbol(TArbol arbol)
{
    if (arbol->pizq != NULL)
    {                         //si tengo elementos anteriores (sub arbol izquierdo)
        borrarArbol(arbol->pizq); //lo borro
    }
    if (arbol->pder != NULL)
    {                         //si tengo elementos posteriores (sub arbol derecho)
        borrarArbol(arbol->pder); //los borro
    }
    freeNodo(arbol); //despues de borrar los hijos, borro el arbol actual
    return;
}
/*
void buscarMaxOcurrencias(TArbol arbol, char* palabra, int* cont){
    *cont = arbol->cont;    //seteo valores iniciales de la busqueda
    strcpy(palabra, arbol->dato);
    MaxOcurrencias( arbol, palabra, cont);
    return;
}

void buscarMinOcurrencias(TArbol arbol, char* palabra, int* cont){
    *cont = arbol->cont;    //seteo valores iniciales de la busqueda
    strcpy(palabra, arbol->dato);
    MinOcurrencias( arbol, palabra, cont);
    return;
}*/
/*
int buscarPalabra(TArbol arbol, char* buscado)
{
    int ocurrencias;
    if (arbol == NULL)
    {
        printf("Sin palabras.\n");
    }else if( 0 == strcmp(arbol->dato, buscado) ) //si encontramos la plabra
    {
        ocurrencias = arbol->cont;  //retornamos el numero de ocurrencias
    }else if(strcmp(buscado, arbol->dato) < 0)  //si la palabra es menor que el nodo actual
    {
        if(arbol->pizq == NULL) //si no hay hijo menor
        {
            ocurrencias = 0;    // no hay ocurrencias
        }else{                  //si hay hijo menor
            ocurrencias = buscarPalabra(arbol->pizq, buscado); //revisamos las palabras menores a la actual
        }
    }else if(strcmp(buscado, arbol->dato ) > 0)
    {
        if(arbol->pder == NULL) //si no hay hijo mayor
        {
            ocurrencias = 0;    // no hay ocurrencias
        }else{                  //si hay hijo mayor
            ocurrencias = buscarPalabra(arbol->pder, buscado); //revisamos las palabras mayores a la actual
        }
    }
    return ocurrencias;
}
*/