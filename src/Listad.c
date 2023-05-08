#include "Nodo.h"
#include "Listad.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

lista *lista_vacia (){
    lista *l;
    l = (lista*)malloc(sizeof(lista));
    l->head = l->tail = NULL;
    l->len = 0;
    return l;
}

bool es_vacia (lista *l){
    bool b;
    if (l->len == 0){
        b = true;
    }else{
        b = false;
    }
    return b;
}

void agregar (lista *l, int p, int e){
    if (es_vacia (l) == 1){
        if (p != 0){
            printf ("No se puede agregar en esa posicion\n");
            return;
        }else{
            nodo *nuevo = crear_nodo (e);
            l->head = l->tail = nuevo;
            l->len++;
            return;
        }
    }else{
        nodo *nuevo = crear_nodo (e);
        if (p == 0){
            nuevo->sig = l->head;
            l->head->ant = nuevo;
            l->head = nuevo;
            l->len++;
            return;
        }
        if (p == l->len){
            nuevo->ant = l->tail;
            l->tail->sig = nuevo;
            l->tail = nuevo;
            l->len ++;
            return;
        }
        if (p > 0 && p < l->len){
            nodo *temp = l->head;
            for (int i = 0; i < p; i++){
                temp = temp->sig;
            }
            nuevo->ant = temp->ant;
            temp->ant = nuevo;
            nuevo->sig = temp;
            nuevo->ant->sig = nuevo;
            l->len++;
            return;
        }
        if (p < 0 || p > l->len){
            printf ("Posicion no valida\n");
            return;
        }
    }
}

void eliminar (lista *l, int p){
    if (es_vacia (l) == 1){
        printf ("La lista esta vacia\n");
        return;
    }else{
        if (p == 0){
            if (l->len == 1){
                free (l->head);
                l->head = l->tail = NULL;
                l->len--;
                return;
            }
            l->head = l->head->sig;
            l->head->ant->sig = NULL;
            free (l->head->ant);
            l->head->ant = NULL;
            l->len--;
            return;
        }
        if (p == (l->len - 1)){
            l->tail = l->tail->ant;
            l->tail->sig->ant = NULL;
            free (l->tail->sig);
            l->tail->sig = NULL;
            l->len--;
            return;
        }
        if (p > 0 && p < (l->len - 1)){
            nodo *temp = l->head;
            for (int i = 0; i < p; i++){
                temp = temp->sig;
            }
            temp->ant->sig = temp->sig;
            temp->sig->ant = temp->ant;
            temp->sig = temp->ant = NULL;
            free (temp);
            temp = NULL;
            l->len--;
            return;
        }
        if (p < 0 || p > l->len){
            printf ("Posicion no valida\n");
            return;
        }
    }
}

void eliminar1 (lista *l, int e){
    int lt = l->len;
    if (es_vacia(l) == 1){
        printf ("La lista esta vacia\n");
    }else{
        for (int p = (lt - 1); p >= 0; p--){
            if (localizar (l, p) == e){
                eliminar (l, p);
            }
        }
        if(l->len == lt){
            printf ("No existe el elemento %d en la lista\n", e);
            return;
        }
    }
    return;
}

int buscar (lista *l, int e){
    if (es_vacia (l) == 1){
        printf ("La lista esta vacia\n");
        return -1;
    }else{
        nodo *temp = l->head;
        for (int i = 0; i < l->len; i++){
            if (temp->dato == e){
                return i;
            }
            temp = temp->sig;
        }
        printf ("El elemento no existe\n");
        return -1;
    }
}

int localizar (lista *l, int p){
    if (es_vacia (l) == 1){
        printf ("La lista esta vacia\n");
        return -1;
    }else{
        if (p < 0 || p > (l->len - 1)){
            printf ("Posicion no valida\n");
            return -1;
        }else{
            nodo *temp = l->head;
            for (int i = 0; i < p; i++){
                temp = temp->sig;
            }
            return temp->dato;
        }
    }
}

void vaciar (lista *l){
    int tp = l->len;
    if (es_vacia(l) == 1){
        printf ("La lista ya estaba vacia\n");
    }else{
        while (es_vacia (l) != 1){
            eliminar (l, 0);
        }
        printf ("La lista fue vaciada\n");
    }
    return;
}

void destruir (lista *l){
    vaciar (l);
    free (l);
    l = NULL;
    printf ("La lista ya no existe\n");
    return;
}

void imprimir(lista* l){
    if(es_vacia(l) == 0){
        nodo* temp=l->head;
        printf("[  ");
        for(int i = 0; i<l->len; i++){
            printf("%i  ",temp->dato);
            temp = temp->sig;
        }
        printf("]\n");
    }else{
        printf("La lista esta vacia\n");
        return;
    }
}