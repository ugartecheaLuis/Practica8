#ifndef __LISTA_H__
#define __LISTA_H__
#include "Nodo.h"
#include <stdbool.h>

struct _lista{
    nodo *tail;
    nodo *head;
    int len;
};

typedef struct _lista lista;

lista *lista_vacia ();
bool es_vacia (lista *);
void agregar (lista *, int, int);
void eliminar (lista *, int);
void eliminar1 (lista *, int);
int buscar (lista *, int); //posicion
int localizar (lista *, int); //elemento
void vaciar (lista *);
void destruir (lista *);
void imprimir(lista*);

#endif