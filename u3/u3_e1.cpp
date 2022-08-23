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
    printf("[ ");
    for (int i = 0; i < N-1; i++)
    {
        printf("%d, ", xarre[i]);
    }
    printf("%d", xarre[N-1] );
    printf("]");
    return;
}

void mayorMenor(int xarre[N], int &xcontMenor, int &xcontMayor)
{
    for (int i = 0; i < N; i++)
    {
        if (xarre[i] > 0)
            xcontMayor++;

        if (xarre[i] < 0)
            xcontMenor++;
    }
    return;
}

//Indicar en el main, la sumatoria de las componentes que se encuentren en las posiciones pares y la
//sumatoria de las que está en posiciones impares.

void sumatoria(int xarre[N], int &xacumPar, int &xacumImp)
{
    for(int i=0; i<N;i++)
    {
        if(i%2 == 0)
            xacumPar += xarre[i];
            else 
            xacumImp += xarre[i];
    }
    return;
}

//Leer un número e indicar si se encuentra en el arreglo indicar su posición (puede estar repetido).

void busqueda(int xarre[N])
{
    int numBuscado, posicion=-1;
    puts("Ingrese numero a buscar");
    scanf("%d", &numBuscado);

    int i=0;
    while(i<N && posicion == -1)
    {
        if(xarre[i] == numBuscado)
            posicion = i;
            else i++;
    }

    if(posicion != -1)
        printf("El arreglo se encontro en la posicion %d del arreglo \n", posicion);
        else
        puts("EL numero no ha sido encontrado");
    
    return;
}

int main()
{
    int arre[N], contMenor = 0, contMayor = 0, acumPar = 0, acumImp=0;
    cargaAleatoria(arre);
    mostrar(arre);

    mayorMenor(arre, contMenor, contMayor);
    if(contMenor > contMayor)
        puts("La cantidad de numeros menores a 0 es mayor a la cantidad de mayores");
        else if(contMayor > contMenor)
            puts("La cantidad de numeros mayores a 0 es mayor a la cantidad de menores");
            else puts("Las cantidades son iguales");

    sumatoria(arre, acumPar, acumImp);
    printf("Sumatoria posiciones pares: %d \n", acumPar);
    printf("Sumatoria posiciones impares: %d \n", acumImp);

    busqueda(arre);

    return 0;
}