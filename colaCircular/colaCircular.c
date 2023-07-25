#include "colaCircular.h"
#define UNDERFLOW 5

colaCircularT qc_crear(int  max)
{
    colaCircularT colaNueva = (colaCircularT) malloc(sizeof(struct colaCircular));
    colaNueva->elementos = (DatoT*) malloc(sizeof(DatoT) * max);
    colaNueva->max = max+1;
    colaNueva->frente = 0;
    colaNueva->final = 0;
    return colaNueva;
}

int qc_vacia( colaCircularT cola)
{
   return (cola->frente == cola->final);
}

int qc_llena( colaCircularT cola)
{
    return (cola->frente == (cola->final+1)%cola->max);
}

int qc_getLen ( colaCircularT cola)
{
    return abs(cola->final - cola->frente);
}

int qc_push(colaCircularT cola, DatoT datoNuevo )
{
    if(! qc_llena(cola))
    {
        cola->elementos[cola->final] = datoNuevo;
        ++(cola->final)%cola->max;
        return 1;
    }else{
        return 0;
    }
}

DatoT qc_pop(colaCircularT cola)
{
    if(! qc_vacia(cola))
    {
        DatoT ret = cola->elementos[cola->frente];
        (++cola->frente)%cola->max;
        return ret; 
        
    }else{
        exit(UNDERFLOW);
    }
}

DatoT qc_top(colaCircularT cola)
{
    if(! qc_vacia(cola))
    {
        DatoT ret = cola->elementos[cola->frente];
        return ret; 
        
    }else{
        exit(UNDERFLOW);
    }
}

void qc_vaciarPila( colaCircularT cola)
{
    cola->frente = 0;
    cola->final = 0;
    return;
}

void qc_free(colaCircularT cola)
{
    free(cola->elementos);
    free(cola);
    return;
}




