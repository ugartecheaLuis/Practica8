#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Nodo.h"
#include "Listadc.h"

int main (){
    int opt;
    listac *l;
    l = lista_vacia ();
    bool b;
    int e, p;

    printf ("\nPRACTICA 8\n");
    
    while (1){
        printf ("\nOpciones:\n");
        printf ("1 - La lista esta vacia?\n");
        printf ("2 - Agregar\n");
        printf ("3 - Eliminar por posicion\n");
        printf ("4 - Eliminar por elemento\n");
        printf ("5 - Buscar un elemento en la lista\n");
        printf ("6 - Localizar un elemento en una posicion:\n");
        printf ("7 - Vaciar la lista\n");
        printf ("8 - Destruir lista\n");
        printf ("9 - Imprimir la lista\n");
        printf ("10 - Terminar programa\n");
        scanf ("%d", &opt);
        switch (opt){
        case 1:
            b = es_vacia (l);
            if (b == 1){
                printf ("La lista esta vacia\n");
            }else{
                printf ("La lista no esta vacia\n");
            }
            break;
        case 2:
            printf ("Ingrese el elemento que desea agregar:\n");
            scanf ("%d", &e);
            printf ("En que posicion lo quiere agregar?\n");
            scanf ("%d", &p);
            agregar (l, p, e);
            break;
        case 3:
            printf ("En que posicion esta el elemento que quiere eliminar?\n");
            scanf ("%d", &p);
            eliminar (l, p);
            break;
        case 4:
            printf ("Ingrese el elemento que quiere borrar de la lista:\n");
            scanf ("%d", &e);
            eliminar1 (l, e);
            break;
        case 5:
            printf ("Ingrese el elemento que desea encontrar:\n");
            scanf ("%d", &e);
            p = buscar (l, e);
            printf ("El elemento %d se encuentra en la posicion %d\n", e, p);
            break;
        case 6:
            printf ("Ingrese la posicion para encontrar el elemento:\n");
            scanf ("%d", &p);
            e = localizar(l, p);
            if (p > 0 && p < l->len){
                printf ("En la posicion %d se encuentra el elemento %d\n", p, e);
            }
            break;
        case 7:
            vaciar (l);
            break;
        case 8:
            destruir (l);
            break;
        case 9:
            imprimir (l);
            break;
        case 10:
            return 0;
        default:
            break;
        }
    }
    
    
    return 0;
}