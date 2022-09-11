#include <stdio.h>

int main(){
    char cadena[30];
    scanf("%s", cadena);
    puts(cadena);
    getchar();
    return 0;
}

//el scanf solo toma la cadena hasta el espacio, lo que sigue despues no se guarda