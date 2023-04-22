#include <stdio.h>

int main(){
    int ar[] = {1,4,7,10,-2,3};
    int maximo = 0;

    for (int i = 0; i < sizeof(ar)/sizeof(int); i++)
    {
        if(ar[i] > maximo){
            maximo = ar[i];
        }
    }
    printf("EL máximo es: %d", maximo);

    return 0;
}