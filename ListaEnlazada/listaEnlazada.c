#include "listaEnlazada.h"

struct ListaEnlazada
{
int len;
NodoT *pPrimero;
NodoT *pUtimo;
};
int getLen (const ListaEnlazadaT lista)
{
    return lista->len;
}

void insertarNodo(NodoT *nodoAnterior, NodoT *nodoInsertado)
{
    setNext(nodoInsertado, getNext(nodoAnterior)); //se setea primero la direccion del nodo nuevo
    setNext(nodoAnterior, nodoInsertado); //se actualiza la direccion del nodo anterior
    return;
}

ListaEnlazadaT crearLista() //retorna una lista 
{
    ListaEnlazadaT listaNueva = (ListaEnlazadaT) malloc(sizeof(struct ListaEnlazada));
    listaNueva->len = 0;
    listaNueva->pPrimero = listaNueva->pUtimo = NULL;
    return listaNueva;
}

int insertarPrimero(ListaEnlazadaT lista, NodoT *nodoNuevo )
{
    int exito = 1; //flag para indicar fallo al insertar el nodo
    if(nodoNuevo != NULL) //si el nodo es valido
    {
        setNext(nodoNuevo, lista->pPrimero);
        lista->pPrimero = nodoNuevo;
        if(lista->len == 0) //si la lista estaba vacia, el primer elemento tambien es el ultimo
        {
            lista->pUtimo = nodoNuevo;   
        }
        lista->len++;
    }else exito = 0;
    return exito;
}

int insertarUltimo(ListaEnlazadaT lista, NodoT *nodoNuevo )
{
    int exito = 1; //flag para indicar fallo al insertar el nodo
    if(nodoNuevo != NULL) //si el nodo es valido
    {
        if(lista->len == 0) //si la lista estaba vacia, el primer elemento tambien es el ultimo
        {
            lista->pPrimero = nodoNuevo;   
        }else{              //si no estaba vacia tengo que enlazar el ultimo elemento
        setNext(lista->pUtimo, nodoNuevo);
        }
        lista->pUtimo = nodoNuevo; //el final de la lista apunta al nodo nuevo
        lista->len++;
    }else exito = 0;
    return exito;
}

int insertarPos(ListaEnlazadaT lista, NodoT *nodoNuevo, int pos )
{
    int exito = 1;
    if((pos > lista->len )|| (nodoNuevo == NULL)) //compruebo que sea una posicion valida y un nodo no nulo
    {
        exito = 0;
    }else{
        if(pos == 0) //si se lo va insertar primero
        {
            insertarPrimero(lista, nodoNuevo);
        }else{
        NodoT* nodoAnterior = lista->pPrimero;
        int posActual = 1;
        while (posActual != pos) //busco la direccion del nodo anterior a la posicion que se quiere insertar
        {
            nodoAnterior = getNext(nodoAnterior);
            posActual++;
        }
        insertarNodo(nodoAnterior,nodoNuevo);   //inserto el nodo
        lista->len++;
        }  
    }
    return exito;
}

int insertarOrdenado(ListaEnlazadaT lista, NodoT *nodoNuevo)
{
    int exito = 1;
    if(lista->len == 0 ) //si la lista esta vacia, no se pueden hacer comparaciones y el dato va al principio
    {
        exito = insertarPrimero(lista, nodoNuevo);
    }else{
        if(compNodo(nodoNuevo, lista->pPrimero) <= 0) //si el elemento a insertar es menor que el primer elmento de la lista
        {
            exito = insertarPrimero(lista, nodoNuevo);
        }else{
            NodoT* nodoAnterior = lista->pPrimero;
            NodoT* nodoSiguente = getNext(nodoAnterior);
            while ( (nodoSiguente != NULL ) && (compNodo(nodoNuevo, nodoSiguente) > 0)) //busco la direccion del nodo anterior a la posicion que se quiere insertar
            {
                nodoAnterior = nodoSiguente;
                nodoSiguente = getNext(nodoSiguente);
            }
            insertarNodo(nodoAnterior,nodoNuevo);   //inserto el nodo
            lista->len++;
        }  
    }
    return exito;
}

int printPos(const ListaEnlazadaT lista, int pos)
{
    int exito = 1;
    if((pos >= lista->len )) //compruebo que sea una posicion valida
    {
        exito = 0;
        printf("Posicion inexistente\n");
    }else{
    NodoT* nodo = lista->pPrimero;
    int posActual = 0;
    while (posActual != pos) //busco la direccion del nodo anterior a la posicion que se quiere insertar
    {
        nodo = getNext(nodo);
        posActual++;
    }
    printNodo(nodo);
    }
    return exito;
}

NodoT* getPos(const ListaEnlazadaT lista, int pos)
{
    NodoT* nodo = NULL;
    if((pos < lista->len )) //compruebo que sea una posicion valida
    {
        nodo = lista->pPrimero;
        int posActual = 0;
        while (posActual != pos) //busco la direccion del nodo anterior a la posicion que se quiere insertar
        {
            nodo = getNext(nodo);
            posActual++;
        }
    }
    return nodo;
}

int setPos(const ListaEnlazadaT lista, int pos, DatoT dato)
{
    int res = 1; //flag de exito
    NodoT* nodo = getPos(lista, pos); //busco la posicio
    if(nodo != NULL)    //compruebo que si se encontro el nodo
    {
        setDato(nodo, dato); //sobreescribo el dato
    }else{
        res = 0;
    }
    return res;
}
