#include "pilaArray.h"
#define UNDERFLOW 5

pilaArrayT p_crearPila(int  max)
{
    pilaArrayT pilaNueva = (pilaArrayT) malloc(sizeof(struct pilaArray));
    pilaNueva->elementos = (DatoT*) malloc(sizeof(DatoT) * max);
    pilaNueva->max = max;
    pilaNueva->tope = -1;
    return pilaNueva;
}

int p_vacia( pilaArrayT pila)
{
    return (pila->tope == -1);
}

int p_llena( pilaArrayT pila)
{
    return (pila->tope == (pila->max-1));
}

int p_getLen ( pilaArrayT pila)
{
    return pila->tope+1;
}

int p_push(pilaArrayT pila, DatoT datoNuevo )
{
    if(! p_llena(pila))
    {
        pila->tope++;
        pila->elementos[pila->tope] = datoNuevo;
        return 1;
    }else{
        return 0;
    }
}

DatoT p_pop(pilaArrayT pila)
{
    if(! p_vacia(pila))
    {
        DatoT ret = pila->elementos[pila->tope];
        pila->tope--;
        return ret; 
        
    }else{
        exit(UNDERFLOW);
    }
}

DatoT p_top(pilaArrayT pila)
{
    if(! p_vacia(pila))
    {
        DatoT ret = pila->elementos[pila->tope];
        return ret; 
        
    }else{
        exit(UNDERFLOW);
    }
}

void p_vaciarPila( pilaArrayT pila)
{
    pila->tope = -1;
    return;
}

void p_free(pilaArrayT pila)
{
    free(pila->elementos);
    free(pila);
    return;
}




