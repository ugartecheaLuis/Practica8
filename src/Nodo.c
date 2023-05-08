#include <stdlib.h>
#include "Nodo.h"

nodo* crear_nodo(int dato){
    nodo* n;
    n = (nodo*)malloc(sizeof(nodo));
    n->dato = dato;
    n->sig = n->ant = NULL;

    return n;
}

void borrar_nodo(nodo* n){
    if(n->sig==NULL && n->ant==NULL){
        free(n);
        n=NULL;
    }
}


