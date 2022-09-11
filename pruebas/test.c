#include <stdio.h>

int main(){
    int arre[3], arre2[3];
    for(int j=0; j<3; j++)
        arre[j] = j + 3;
    printf("%d \n", *arre);

//usar el arre solo (sin componente) accede a la primer componente del arreglo, por lo tanto, arre
//guarda la direccion del primer componente del arreglo.