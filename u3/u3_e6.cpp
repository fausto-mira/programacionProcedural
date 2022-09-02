/*Ejercicio 6
Un supermercado ingresa las ventas de los últimos 6 meses, realizadas en los 8 departamentos de venta que posee.
Por cada venta se ingresa mes, departamento e importe. Las ventas no traen ningún orden particular. Realizar un
programa en C, que a través de funciones permita:
a) Almacenar la información en una tabla que posea por cada mes, el importe total de ventas de cada
departamento.
b) Mostrar en el programa principal el departamento que tuvo menor importe de venta (suponer único).
c) Mostrar importe promedio de venta del supermercado.
d) Mostrar el/los departamento/s que supera/n la venta promedio, indicando el importe total vendido a lo
largo del semestre. */

#include <stdio.h>
#define M 6
#define N 8

void inicializacion(float xventas[][N], int xmes)
{
    for (int i = 0; i < xmes; i++)
    {
        for (int j = 0; j < N; j++)
        {
            xventas[i][j] = 0;
        }
    }
    return;
}

int carga(float xventas2[12][N])
{
    int mes, departamento, maximo = 0;
    float monto;

    puts("Ingrese mes de venta (finaliza con '0')");
    scanf("%d", &mes);

    while (mes != 0)
    {
        puts("Ingrese el numero de departamento");
        scanf("%d", &departamento);
        puts("Ingrese monto de la venta");
        scanf("%f", &monto);

        xventas2[mes - 1][departamento - 1] += monto;

        if (mes > maximo)
            maximo = mes;
        printf("%d \n", maximo);

        puts("Ingrese mes de venta (finaliza con '0')");
        scanf("%d", &mes);
    }
    return (maximo);
}

void copia(float xventas[M][N], float xventas2[][N], int xmaximo)
{
    int k = 0;
    for (int i = xmaximo - 6; i < xmaximo; i++)
    {
        for (int j = 0; j < N; j++)
        {
            xventas[k][j] = xventas2[i][j];
        }
        k += 1;
    }
    return;
}

void mostrar(float xventas[M][N])
{
    puts("\n\n::::::: TABLA :::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("Depto ");
    for (int i = 0; i < N; i++)
        printf("%7d", i + 1);
    printf("\n\n");
    for (int i = 0; i < M; i++)
    {
        printf("MES %d:  ", i + 1);
        for (int j = 0; j < N; j++)
        {
            printf("%7.2f", xventas[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

// Mostrar en el programa principal el departamento que tuvo menor importe de venta (suponer único)

float menorImporte(float xventas[M][N], int &posDpto)
{
    float acum, menor = 9999999;
    int j;
    for (int i = 0; i < M; i++)
    {
        acum = 0;
        for (j = 0; j < N; j++)
            acum += xventas[j][i];

        if (acum < menor)
        {
            menor = acum;
            posDpto = j;
        }
    }
    return (menor);
}

// Mostrar importe promedio de venta del supermercado.

void promedio(float xventas[M][N], float &promedio)
{
    float acumulador = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            acumulador += xventas[i][j];
    }
    promedio = acumulador / (M * N);
    printf("El monto promedio del supermercado es: %f", promedio);
    return;
}

// Mostrar el/los departamento/s que supera/n la venta promedio, indicando el importe total vendido a lo
// largo del semestre.

void subArreglo(float xventas[M][N], float arre[N])
{
    float acum = 0;
    int k = 0;
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            acum += xventas[i][j];
        }
        arre[k] = acum / M;
        k++;
    }
    return;
}

void superaPromedio(float arre[N], float promedio)
{
    for (int i = 0; i < N; i++)
    {
        if (arre[i] > promedio)
            printf("El dpto %d supera el promedio con: $%f", i + 1, arre[i]);
    }
    return;
}

int main()
{
    float ventas[M][N], ventas2[12][N], resultado;
    int maximo, posDpto;

    inicializacion(ventas, M);
    inicializacion(ventas2, 12);
    mostrar(ventas);

    maximo = carga(ventas2);
    copia(ventas, ventas2, maximo);
    mostrar(ventas);

    resultado = menorImporte(ventas, posDpto);
    printf("El dpto que menos vendio es el %d, con importe %f \n", posDpto, resultado);

    float prom;
    promedio(ventas, prom);

    float subarre[N];
    subArreglo(ventas, subarre);
    superaPromedio(subarre, prom);

    return 0;
}