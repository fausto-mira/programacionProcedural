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

typedef struct adjudicatario
{
    double dni;
    float monto;
} adjudicatario;

int main()
{
    adjudicatario array[N];

    return 0;
}