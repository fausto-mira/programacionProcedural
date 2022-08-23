/*Ejercicio 7

Un laboratorio abastece a 30 farmacias de la provincia (las farmacias están codificadas con número entre 1 y
30). Dicho laboratorio comercializa 80 medicamentos (con código desde 100 hasta 179).
En forma ordenada por las farmacias se ingresan las ventas realizadas. Por cada venta se ingresa: código de
medicamento y cantidad de unidades, finalizando con código de medicamento igual a 0 (cero), como lo
muestra el siguiente ejemplo:

            Código Medicamento      Cantidad Unidades
Farmacia 1          23                      12
                    32                      20
                    41                      6
                    0
Farmacia 2          43                      10
                    25                      24
                    0

Codificar un programa en C, que utilizando funciones permita:
a) Realizar la carga de la tabla.
b) Calcular y mostrar total de unidades vendidas de cada uno de los medicamentos.
c) Dado el código de una farmacia, indicar código de medicamento más vendido.*/

#include <stdio.h>
#define N 2
#define M 4

void inicializacion(int xventas[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            xventas[i][j] = 0;
    }
    return;
}

void carga(int xventas[N][M])
{
    int cod = 0, unidades = 0;
    for (int i = 0; i < N; i++)
    {
        printf("FARMACIA %d \n", i + 1);
        puts("Ingrese codigo de medicamento");
        scanf("%d", &cod);
        while (cod != 0)
        {
            puts("Ingrese cantidad de unidades vendidas");
            scanf("%d", &unidades);
            xventas[i][cod - 100] += unidades;
            // printf("%d", xventas[i][cod - 100]);
            puts("Ingrese codigo de medicamento");
            scanf("%d", &cod);
        }
    }
    return;
}

void mostrar(int xventas[N][M])
{
    int arre[M];
    for (int a = 0; a < M; a++)
        arre[a] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arre[j] += xventas[i][j];
        }
    }

    puts("Cantidad de productos vendidos");
    for (int j = 0; j < M; j++)
        printf("Producto %d: %d \n", j + 1, arre[j]);

    return;
}

void calcular(int xventas[N][M])
{
    int i, j, total;
    for (j = 0; j < M; j++)
    {
        total = 0;
        for (i = 0; i < N; i++)
        {
            total += xventas[i][j];
        }
        printf("Total medicamento %d: %d", j + 1, total);
    }
}

void masVendido(int xventas[N][M])
{
    int farmacia, max = 0, pos;
    puts("Ingrese la farmacia para buscar el prod mas vendido");
    scanf("%d", &farmacia);
    for (int j = 0; j < M; j++)
    {
        if (xventas[farmacia - 1][j] > max)
        {
            max = xventas[farmacia - 1][j];
            pos = j;
        }
    }
    printf("El producto mas vendido es %d", pos + 100);
    return;
}

int main()
{
    int ventas[N][M];
    inicializacion(ventas);
    carga(ventas);
    /*for (int i = 0; i < M; i++)
    {
        printf("%d", ventas[0][i]);
    }*/
    mostrar(ventas);
    masVendido(ventas);
    return 0;
}