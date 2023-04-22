#include <stdio.h>
// promedio
int main(){
    int ar[] = {1,4,5,3,2};
    int suma = 0;
    for (int i = 0; i < sizeof(ar)/sizeof(int); i++) {
        suma += ar[i];
    }
    float prom = (float) suma / (sizeof(ar) / sizeof(int));

    printf("El promedio es %f",prom);


    return 0;
}