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

typedef struct
{
    float importe;
    int cant;

} supermercado;

void inicializacion(supermercado xventas[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            xventas[i][j].cant = 0;
            xventas[i][j].importe = 0;
        }
    }
    return;
}

int busqueda(supermercado xventas2[12][N])
{
    int maximo = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (xventas2[i][j].cant != 0)
                maximo = i;
        }
    }
    return (maximo);
}

void carga(supermercado xventas[M][N])
{
    int mes, dpto;
    supermercado xventas2[12][N];
    float importe;
    puts("Ingrese mes de venta (termina con 0)");
    scanf("%d", &mes);
    while (mes != 0)
    {
        puts("Ingrese departamento");
        scanf("%d", &dpto);
        puts("Ingrese importe de venta");
        scanf("%f", &importe);
        xventas2[mes - 1][dpto - 1].importe += importe;
        xventas2[mes - 1][dpto - 1].cant++;
        puts("Ingrese mes de venta");
        scanf("%d", &mes);
    }
    int max = busqueda(xventas2);
    max = -6;
    int x = 0;
    for (int i = max; i <= max; i++)
    {
        for (int j = 0; j < N; j++)
            xventas[x][j] = xventas2[i][j];
        i++;
    }
    return;
}

void menosVentas(supermercado xventas[M][N])
{
    int mes, pos = 0;
    long int min = 9999999;
    puts("Ingrese mes para ver el que menos vendio");
    scanf("%d", &mes);
    for (int j = 0; j < N; j++)
    {
        if (xventas[mes][j].cant < min)
        {
            min = xventas[mes][j].cant;
            pos = j + 1;
        }
    }
    printf("EL departamento que menos vendió fue el %d", pos);
    return;
}

float calculoPromedio(supermercado xventas[M][N])
{
    float acum = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            acum = xventas[i][j].importe / xventas[i][j].cant;
        }
    }
    float promedio = acum / (M * N);
    printf("El importe promedio de ventas del super es %.2f \n", promedio);
    return (promedio);
}

void promedioSuper(supermercado xventas[M][N], float xpromedio)
{
    int mes, dpto;
    puts("Ingrese el mes y el departamento para ver si supera el promedio de venta");
    scanf("%d", &mes);
    scanf("%d", &dpto);
    float promedioDpto = xventas[mes - 1][dpto - 1].importe / xventas[mes - 1][dpto - 1].cant;

    if (promedioDpto > xpromedio)
        puts("Supera el promedio");
    else
        puts("No supera el promedio");

    return;
}

int main()
{
    supermercado ventas[M][N];
    inicializacion(ventas);
    carga(ventas);
    menosVentas(ventas);
    float promedio = calculoPromedio(ventas);
    promedioSuper(ventas, promedio);
    return 0;
}