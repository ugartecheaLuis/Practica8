#ifndef __LISTAC_H__
#define __LISTAC_H__
#include "Nodo.h"
#include <stdbool.h>

struct _listac{
    nodo *tail;
    nodo *head;
    int len;
};

typedef struct _listac listac;

listac *lista_vacia ();
bool es_vacia (listac *);
void agregar (listac *, int, int);
void eliminar (listac *, int);
void eliminar1 (listac *, int);
int buscar (listac *, int);
int localizar (listac *, int);
void vaciar (listac *);
void destruir (listac *);
void imprimir(listac*);

#endif