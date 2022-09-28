/*
Ejercicio 3
El Instituto Provincial de la Vivienda ha implementado un sistema que consta de 5 planes de pago distintos, con el fin
de que los adjudicatarios de sus viviendas puedan cancelar sus deudas. Por cada uno de los 5 planes, se ingresa en
forma ordenada la cantidad de adjudicatarios adheridos y por cada uno de ellos el DNI y monto adeudado.
Se pide:
a) Cargar en una estructura de datos adecuada la información que se posee.
b) Para un adjudicatario cuyo DNI se ingresa por teclado, indicar el número de plan al cual se adhirió y el monto
adeudado.
c) Mostrar el mapa de memoria, después de ejecutar la función que carga los datos.
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct adjadicatario
{
    long int dni;
    float monto;
} adjudicatario;

typedef struct planes
{
    int cant;
    adjudicatario *array;
} plan;

void carga(plan xplanes[N])
{
    int n;
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese cantidad de cantidad de ajudicatarios plan N°%d \n", i + 1);
        scanf("%d", &n);
        xplanes[i].array = (adjudicatario *)malloc(sizeof(adjudicatario) * n);
        xplanes[i].cant = n;
        for (int j = 0; j < n; j++)
        {
            printf("Ingrese DNI y monto adeudado adjudicatario N°%d \n", j + 1);
            scanf("%ld", xplanes[i].array->dni + j);
            scanf("%f", xplanes[i].array->monto + j);
        }
    }
    return;
}

void mostrar(plan xplanes[N], int i, int j)
{
    if (i < N)
    {
        printf("Plan N°%d:      \n", i + 1);
        if (j < xplanes[i].cant)
        {
            printf("Adjudicatario N°%d  DNI: %ld  Monto: %f \n", j + 1, xplanes[i].array->dni + j, xplanes[i].array->monto + j);
            mostrar(xplanes, i, j + 1);
        }
        mostrar(xplanes, i + 1, 0);
    }
}

int busqueda;

int main()
{
    plan planes[N];
    carga(planes);
    mostrar(planes, 0, 0);
    return 0;
}