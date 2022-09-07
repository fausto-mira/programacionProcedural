/*Ejercicio 6
Realice una función que busque el mayor valor de un arreglo, de modo tal que al llegar al caso base ya haya
encontrado este valor; y en la etapa de volver al punto de invocación vaya mostrando los valores iguales al mayor.*/

#include <stdio.h>
#define N 6

int busqueda(int xarre[N], int n, int &mayor, int igualesMayor)
{
    if (n < N)
    {
        if (xarre[n] > mayor)
            mayor = xarre[n];

        igualesMayor += busqueda(xarre, n + 1, mayor, igualesMayor);

        if (xarre[n] == mayor)
            return igualesMayor += 1;
        else
            return igualesMayor;
    }
    return 0;
}

void busquedaDos(int xarre[N], int n, int &mayor)
{
    if (n < N)
    {
        if (xarre[n] > mayor)
            mayor = xarre[n];

        busquedaDos(xarre, n + 1, mayor);

        if (xarre[n] == mayor)
            printf("pos: %d es igual al mayor \n", n);
    }
}

int main()
{
    int arre[N] = {1, 2, 6, 4, 5, 6};
    int mayor = 0, igualesMayor;
    igualesMayor = busqueda(arre, 0, mayor, 0);
    printf("\n\nMayor: %d. Cant de n iguales al mayor: %d \n\n", mayor, igualesMayor);
    mayor = 0;
    busquedaDos(arre, 0, mayor);
    return 0;
}