/*Ejercicio 8
Un supermercado ingresa las ventas de los últimos 6 meses, realizadas en los 8 departamentos de venta que
posee. Por cada venta se ingresa mes (1..12), número de departamento (1..8) e importe. Las ventas no traen
ningún orden particular. Realizar un programa en C, que a través de funciones permita:
a) Almacenar la información en una tabla que posea por cada mes, el importe total de ventas de cada
departamento. La carga finaliza con mes igual a cero.
b) Dado un mes, mostrar en el programa principal el departamento que menos vendió (suponer único).
c) Mostrar importe promedio de venta del supermercado.
d) Dado un mes y un departamento, indicar si supera el importe promedio del ítem anterior
*/

#include <stdio.h>
#define M 6
#define N 8

void inicializacion(int xventas[N][M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            xventas[i][j] = 0;
    }
    return;
}

int busqueda(int xventas2[12][N])
{
    int maximo = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (xventas2[i][j] != 0)
                maximo = i;
        }
    }
    return (maximo);
}

void carga(int xventas[N][M])
{
    int mes, dpto, xventas2[12][N];
    float importe;
    puts("Ingrese mes de venta (termina con 0)");
    scanf("%d", &mes);
    while (mes != 0)
    {
        puts("Ingrese departamento");
        scanf("%d", &dpto);
        puts("Ingrese importe de venta");
        scanf("%f", &importe);
        xventas2[mes - 1][dpto - 1] += importe;
        puts("Ingrese mes de venta");
        scanf("%d", &mes);
    }
    int max = busqueda(xventas2);
    for (int i = max; i > 0; i--)
    {
    }
    return;
}

void menosVentas(int xventas[M][N])
{
    int mes, min = 9999999, pos = 0;
    puts("Ingrese mes para ver el que menos vendio");
    scanf("%d", &mes);
    for (int i = 0; i < N; i++)
    {
        if
    }
}
int main()
{
    int ventas[M][N];
    inicializacion(ventas);
    return 0;
}