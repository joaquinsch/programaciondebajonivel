#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct structNodo{
    int valor;
    struct structNodo *proximo;

}Nodo;

// Crea un nodo con puntero al proximo en NULL
Nodo* crearNodo(int valor) {
    Nodo* nuevo = malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->proximo = NULL;
    return nuevo;
}

//Agregar al principio
void prepend(Nodo** head,int valor){
    Nodo* nuevo = crearNodo(valor);
    nuevo->proximo = *head;
    *head = nuevo;


}
// Agregar al final
void append(Nodo** head, int val){
    Nodo* nuevoNodo = crearNodo(val);
    if(*head == NULL){
       *head = nuevoNodo;
    }else{
        Nodo* actual = *head;
        while (actual->proximo != NULL){
            actual = actual->proximo;
        }
        actual->proximo = nuevoNodo;
    }

}
// Cantidad de elementos en la lista
int tamanio(Nodo* head){
    int contador = 0;
    while(head != NULL){
        contador++;
        head = head->proximo;
    }
    return contador;
}
/* Devuelve el indice del primer nodo que tiene el valor dado,
 y devuelve -1  si no se encontró*/
int buscar(Nodo* head,int valor){
    if(head == NULL){
        return -1;
    }
    Nodo* actual = head;
    int pos = 0;
    while(actual != NULL){
        if(actual->valor == valor){
            return pos;
        }
        pos++;
        actual = actual->proximo;
    }
    return -1;
}
/* Elimina el primer nodo que tenga el valor dado.*/
// falta lo de free()
void eliminar(Nodo** head,int valor){
    if(*head == NULL){
        exit(0);
    }
    if((*head)->valor == valor){
        *head =(*head)->proximo;
    }
    Nodo* actual = *head;
    while(actual->proximo != NULL){
        if(actual->proximo->valor == valor){
            actual->proximo = actual->proximo->proximo;
            return;
        }
        actual = actual->proximo;
    }


}

void imprimirLista(Nodo* head){
    while(head != NULL){
        printf("%d - ", head->valor);
        head = head->proximo;
    }
    printf("\n");
}

int main(){
    Nodo* lista = NULL;

    prepend(&lista,5);
    append(&lista, 3);
    append(&lista,10);
    prepend(&lista,8);

    eliminar(&lista,5);
    eliminar(&lista,3);
    eliminar(&lista,8);

    imprimirLista(lista);

    printf("La cantidad de nodos de la lista es: %d\n", tamanio(lista));

    printf("Se encontro el valor en la posicion: %d\n" ,buscar(lista, 5));

    return 0;

    // Prueba
    /* Nodo* lista = NULL;
     Nodo n1, n2, n3;
     n1.valor = 13;
     n2.valor = 2;
     n3.valor = 1;

     lista = &n1;
     n1.proximo = &n2;
     n2.proximo = &n3;
     n3.proximo = NULL;
     */

}