#include "listaEnlazada.h"
#define POS_INEXISTENTE 5
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

int insertarPrimero(ListaEnlazadaT lista, DatoT datoNuevo )
{
    NodoT *nodoNuevo = newNodo(datoNuevo);
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

int insertarUltimo(ListaEnlazadaT lista, DatoT datoNuevo )
{
    int exito = 1; //flag para indicar fallo al insertar el nodo
    NodoT *nodoNuevo = newNodo(datoNuevo);
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

int insertarPos(ListaEnlazadaT lista, DatoT datoNuevo, int pos )
{
    int exito = 1;
    if((pos > lista->len )) //compruebo que sea una posicion valida
    {
        exito = 0;
    }else{
        if(pos == 0) //si se lo va insertar primero
        {
            exito = insertarPrimero(lista, datoNuevo);
        }else{
            NodoT* nodoAnterior = lista->pPrimero;
            int posActual = 1;
            while (posActual != pos) //busco la direccion del nodo anterior a la posicion que se quiere insertar
            {
                nodoAnterior = getNext(nodoAnterior);
                posActual++;
            }
            NodoT *nodoNuevo = newNodo(datoNuevo);
            if(nodoNuevo == NULL)
            {
                exito = 0;
            }else{
                insertarNodo(nodoAnterior,nodoNuevo);   //inserto el nodo
                lista->len++;
            }
        }  
    }
    return exito;
}

int insertarOrdenado(ListaEnlazadaT lista, DatoT datoNuevo)
{
    int exito = 1;
    if(lista->len == 0 ) //si la lista esta vacia, no se pueden hacer comparaciones y el dato va al principio
    {
        exito = insertarPrimero(lista, datoNuevo);
    }else{
        NodoT *nodoNuevo = newNodo(datoNuevo);
        if(nodoNuevo == NULL)
        {
            exito = 0;
        }else{
            if(compNodo(nodoNuevo, lista->pPrimero) <= 0) //si el elemento a insertar es menor que el primer elmento de la lista
            {
                setNext(nodoNuevo, lista->pPrimero);
                lista->pPrimero = nodoNuevo;
                lista->len++;
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
    }
    return exito;
}

int insertarOrdenadoR(ListaEnlazadaT lista, DatoT datoNuevo)
{
    int exito = 1;
    if(lista->len == 0 ) //si la lista esta vacia, no se pueden hacer comparaciones y el dato va al principio
    {
        exito = insertarPrimero(lista, datoNuevo);
    }else{
        NodoT *nodoNuevo = newNodo(datoNuevo);
        if(nodoNuevo == NULL)
        {
            exito = 0;
        }else{
            if(compNodo(nodoNuevo, lista->pPrimero) > 0) //si el elemento a insertar es menor que el primer elmento de la lista
            {
                setNext(nodoNuevo, lista->pPrimero);
                lista->pPrimero = nodoNuevo;
                lista->len++;
            }else{
                NodoT* nodoAnterior = lista->pPrimero;
                NodoT* nodoSiguente = getNext(nodoAnterior);
                while ( (nodoSiguente != NULL ) && (compNodo(nodoNuevo, nodoSiguente) <= 0)) //busco la direccion del nodo anterior a la posicion que se quiere insertar
                {
                    nodoAnterior = nodoSiguente;
                    nodoSiguente = getNext(nodoSiguente);
                }
                insertarNodo(nodoAnterior,nodoNuevo);   //inserto el nodo
                lista->len++;
            }  
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

DatoT getPos(const ListaEnlazadaT lista, int pos)
{
    DatoT dato;
    if((pos < lista->len )) //compruebo que sea una posicion valida
    {
        NodoT *nodo = NULL;
        nodo = lista->pPrimero;
        int posActual = 0;
        while (posActual != pos) //busco la direccion del nodo anterior a la posicion que se quiere insertar
        {
            nodo = getNext(nodo);
            posActual++;
        }
        dato = getDato(nodo);
    }else{
        exit(POS_INEXISTENTE);
    }
    return dato;
}

int setPos(const ListaEnlazadaT lista, int pos, DatoT dato)
{
    int res = 1; //flag de exito
    if((pos < lista->len )) //compruebo que sea una posicion valida
    {
        NodoT *nodo = NULL;
        nodo = lista->pPrimero;
        int posActual = 0;
        while (posActual != pos) //busco la direccion del nodo anterior a la posicion que se quiere insertar
        {
            nodo = getNext(nodo);
            posActual++;
        }
        setDato(nodo, dato); //sobreescribo el dato
    }else{
        exit(POS_INEXISTENTE);
    }
    return res;
}

int buscarDato(const ListaEnlazadaT lista, DatoT dato)
{
    NodoT* nodo = NULL;
    int pos = -1; //asumo que el elemento no se encuentra en la lista
    if(lista->len) // comprebo que no se este buscando en una lista vacia
    {
        nodo = lista->pPrimero;
        int posActual = 0;
        while (nodo != NULL) //recorro toda la lista
        {
            if(dato == getDato(nodo)) //si encuentro el dato, guardo la posicion y paro
            {
                pos = posActual;
                break;
            }
            nodo = getNext(nodo);
            posActual++;
        }
    }
    return pos;
}

int eliminarDato(const ListaEnlazadaT lista, DatoT dato)
{
    NodoT* nodo = NULL, *anterior = NULL;
    int ret = 0; //asumo que el elemento no se encuentra en la lista
    if(lista->len) // comprebo que no se este buscando en una lista vacia
    {
        nodo = lista->pPrimero;
        if(dato == getDato(nodo)) //si mi dato buscado es mi cabeza de la lista
        {
         lista->pPrimero = getNext(nodo);
         freeNodo(nodo);
         lista->len--;
         ret = 1;   
        }else{
            while (getNext(nodo) != NULL) //recorro toda la lista
            {
                anterior = nodo;
                nodo = getNext(nodo);
                if(dato == getDato(nodo)) //si encuentro el dato, guardo la posicion y paro
                {
                    setNext(anterior, getNext(nodo)); //desconecto el nodo
                    freeNodo(nodo);
                    ret = 1;
                    lista->len--;
                    break;
                }
            }
        }
    }
    return ret;
}

int eliminarPos(const ListaEnlazadaT lista, int pos)
{
    NodoT* nodo = NULL, *anterior = NULL;
    int ret = 0; //asumo que no se puede hacer la operacion
    if(((pos < lista->len) && (pos>=0) )) //compruebo que sea una posicion valida
    {
        nodo = lista->pPrimero;
        int posActual = 0;
        while (posActual != pos) //busco la direccion del nodo anterior a la posicion que se quiere insertar
        {
            anterior = nodo;
            nodo = getNext(nodo);
            posActual++;
        }
        if(posActual == 0) //si estoy trabajando con el primero o el ultimo, actualizo los punteros de cabecera y cola
        {
            lista->pPrimero = getNext(nodo);
        }else if(posActual == (lista->len)-1)
        {
            setNext(lista->pUtimo, anterior);
            setNext(anterior, NULL);
        }else{
            setNext(anterior, getNext(nodo));
        }
        free(nodo);
        ret = 1;
        lista->len--;

    }
    return ret;
}

void vaciarLista(const ListaEnlazadaT lista)
{
    NodoT *nodo;
    while(lista->pPrimero != NULL)
    {
        nodo = lista->pPrimero;
        lista->pPrimero = getNext(lista->pPrimero);
        freeNodo(nodo);
        lista->len--;
    }
    lista->pUtimo = NULL;
    return;
}
