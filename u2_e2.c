/*Ejercicio 2
Dada la frase “Programación Procedural 2022”, leerla desde teclado en una cadena de caracteres y:
a) Reemplazar el 2 por un 0 (Solo cambiar ese carácter)
b) Copiar la palabra “Programación” a una nueva cadena de caracteres.
c) Contar la cantidad de vocales de la frase.*/

#include <stdio.h>
#include <string.h>
#define N 30

int carga(char xfrase[N]) {
    printf("Ingrese la frase \n");
    fgets(xfrase, N, stdin);
    return(strlen(xfrase));
}

void reemplazo(char xfrase[N], int xcota) {
    int i = 0;
    while((i<xcota) && (xfrase[i] != '2')){
        i++;
    }
    (i<xcota) ? xfrase[i] = '0' : puts("No se encontro ningun 2");
    puts(xfrase);
    return;
}

void copiar(char xfrase[N], char xfrase2[N]) {
    puts(strncpy(xfrase2,xfrase,12));
    return;
}

void contar(char frase[N]) {
    int i, cont = 0;
    for(i=0; i<N; i++){
        if(frase[i]=='a' || frase[i]=='e' || frase[i]=='i' || frase[i]=='o' || frase[i]=='u'){
            cont++;
        }
    }
    printf("Cantidad de vocales %d \n", cont);
}


int main() {
    char frase[N], frase2[N];
    int cota;
    cota = carga(frase);
    reemplazo(frase, cota);
    copiar(frase, frase2 );
    contar(frase);
    return 0;
}
