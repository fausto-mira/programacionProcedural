/*Ejercicio 1
Crear un arreglo de 50 números enteros y cargarlo generando cada numero de manera aleatoria.
Codificar un programa en C que permita:
a) Indicar en el main si cantidad de números mayores a cero es mayor o igual a la cantidad de números
menores a cero.
b) Indicar en el main, la sumatoria de las componentes que se encuentren en las posiciones pares y la
sumatoria de las que está en posiciones impares.
c) Leer un número e indicar si se encuentra en el arreglo indicar su posición (puede estar repetido). */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 50

void cargaAleatoria(int xarre[N])
{
    srand(time(NULL));
    int max = 10, min = -11;

    for (int i = 0; i < N; i++)
    {
        xarre[i] = rand() % (max - min + 1) + min;
    }
    return;
}

void mostrar(int xarre[N])
{
    for (int i = 0; i < N; i++)
    {
        printf("%d \n", xarre[i]);
    }
}

void maximoMinimo(int xarre[N])
{
    for (int i = 0; i < N; i++)
    {
        if (xarre[i] > 0)
            contMax++;

        if (xarre[i] < 0)
            contMin++;
    }
    return;
}

int main()
{
    int arre[N], *contMin = 0, *contMax = 0;
    cargaAleatoria(arre);
    mostrar(arre);
    maximoMinimo(xarre, &) return 0;
}