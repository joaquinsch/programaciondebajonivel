#include <stdio.h>
#include <stdlib.h>
/*
 * Parte 2:
Implementar una lista de enteros ordenada. Cada elemento que agrego queda ordenado en la lista,
 de manera que al imprimirla se imprime automáticamente ordenada.

 */
typedef struct structNodo{
    int valor;
    struct structNodo* proximo;
}Nodo;

Nodo* crearNodo(int valor){
    Nodo* nuevo = malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->proximo = NULL;
    return nuevo;
}

void agregar(Nodo** lista, int valor){
    Nodo* nuevo = crearNodo(valor);
    if(*lista == NULL){
        *lista = nuevo;
    }else if((*lista)->valor >= valor){
        nuevo->proximo = *lista;
        *lista = nuevo;
    }else{
        Nodo* actual = *lista;
    while(actual->proximo!= NULL && actual->proximo->valor < valor){
        actual = actual->proximo;
    }
    nuevo->proximo = actual->proximo;
    actual->proximo = nuevo;

    }

}
void imprimirLista(Nodo* lista){
    while (lista != NULL){
        printf("%d - ",lista->valor);
        lista = lista->proximo;
    }
}
int main(){
    Nodo* lista = NULL;
    agregar(&lista,5);
    agregar(&lista,6);
    agregar(&lista,3);
    agregar(&lista,4);
    imprimirLista(lista);
    return 0;
}