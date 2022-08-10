/*Ejercicio 2
Dada la frase “Programación Procedural 2022”, leerla desde teclado en una cadena de caracteres y:
a) Reemplazar el 2 por un 0 (Solo cambiar ese carácter)
b) Copiar la palabra “Programación” a una nueva cadena de caracteres.
c) Contar la cantidad de vocales de la frase.*/

#include <stdio.h>
#include <string.h>
#define N 30

void carga(char xfrase[N]) {
    printf("Ingrese la frase \n");
    fgets(xfrase, N, stdin);
    return;
}

void reemplazo(char xfrase[N], char xfrase2[N]) {
    int i;
    for(i=0; i<N; i++){
        if(xfrase[i] != '2'){
            xfrase2[i] = xfrase[i]; 
        }
        else{
            xfrase2[i] = '0';
        }
    }
    puts(xfrase2);
    return;
}

void copiar(char xfrase[N], char xfrase3[N]) {
    puts(strncpy(xfrase3,xfrase,14));
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
    char frase[N], frase2[N], frase3[N];
    carga(frase);
    reemplazo(frase, frase2);
    copiar(frase, frase3);
    contar(frase);
    return 0;
}
