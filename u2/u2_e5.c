/*Ejercicio 5
Cargar aleatoriamente una tabla de 5x4 con números enteros y:
a) Mostrar la suma de cada una de las filas.
b) Calcular el promedio de la tercera columna.
c) Decir cuántos números mayores a 100 se ingresaron*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 4

void carga(int xtabla[N][M]){
    srand(time(NULL));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            xtabla[i][j] = rand()%200;
        }
    }
    return;
}

void mostrar(int xtabla[N][M]){
    puts("TABLA ALEATORIA GENERADA:");
    for(int i=0; i<N; i++){
        printf("\n");
        for(int j=0; j<M; j++){
            printf("  %4d  ", xtabla[i][j]);
        }
    }
    printf("\n");
    printf("\n");
    return;
}

void suma(int xtabla[N][M]){
    puts("SUMA DE LAS FILAS");
    printf("\n");
    for(int i=0; i<N; i++){
        int sumador=0;
        for(int j=0; j<M; j++){
            sumador += xtabla[i][j];
        }
        printf("Fila %d: %d \n", i+1, sumador);
    }
    printf("\n");
    return;
}

void promedio(int xtabla[N][M]){
    float promedio;
    for(int i=0; i<N; i++){
        promedio += xtabla[i][2];
    }
    printf("Promedio de la tercer columna: %.1f \n", promedio / N);
    return;
}

void mayoresA100(int xtabla[N][M]){
    int contador = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(xtabla[i][j] > 100) contador++;
        }
    }
    printf("\nCantidad de numeros mayores a 100: %d", contador);
    return;
}

void main(){
    int tabla[N][M];
    carga(tabla);
    mostrar(tabla);
    suma(tabla);
    promedio(tabla);
    mayoresA100(tabla);
}
