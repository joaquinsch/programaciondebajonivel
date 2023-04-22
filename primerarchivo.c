#include <stdio.h>


int main(){
    int numero;
    printf("Ingrese un número ");
    scanf("%d",&numero);
    if (numero % 2 == 0){
        printf("Es par");
    }else{
        printf("Es impar");
    }


    return 0;
}