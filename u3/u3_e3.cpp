/*Ejercicio 3
Un laboratorio abastece a 30 farmacias de la provincia. Dicho laboratorio comercializa 80 medicamentos (1..80) de
los que se debe registrar: Código de medicamento, nombre y precio unitario.
Se ingresan las ventas realizadas ordenada por farmacia. Por cada venta a una farmacia se ingresa: código de
medicamento y cantidad de unidades, finalizando con código de medicamento igual a 0 (cero), como lo muestra el
siguiente ejemplo:
                Código Medicamento      Cant. Unidades
Farmacia 1              23                  12
                        32                  20
                        41                  6
                        0
Farmacia 2              43                  10
                        25                  24
                        0

Codificar un programa en C, que utilizando funciones permita:

a) Calcular y mostrar total de unidades vendidas de cada uno de los medicamentos.
b) Escribir el/los códigos/s del/los medicamento/s por el que se recaudó mayor importe.
c) Indicar la cantidad de unidades vendidas para un código de medicamento ingresado por teclado.
d) Dado el nombre de un medicamento indicar el importe total recaudado y la cantidad de unidades vendidas.
e) Indicar la cantidad de unidades vendida a cada farmacia y el importe total que pagó cada una.*/

#include <stdio.h>
#include <stdbool.h>

#define M 30
#define N 80

typedef struct ventas
{
    int cod, cant;
    float precio;
    char nombre[20];
} ventas;

void inicializacion(ventas xarre[M][N])
{
    char nombre[20];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            puts("Ingrese nombre del medicamento");
            scanf("%s", nombre);
            puts("Ingrese precio por unidad");
            scanf("%f", &xarre[i][j].precio);
            xarre[i][j].cant = 0;
            xarre[i][j].cod = j + 1;
        }
    }
    return;
}

void carga(ventas xarre[M][N])
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
            xarre[i][cod - 1].cant += unidades;
            // printf("%d", xarre[farmacia][i][cod - 100]);
            puts("Ingrese codigo de medicamento");
            scanf("%d", &cod);
        }
    }
    return;
}

void totalProductosVendidos(ventas xarre[M][N])
{
    int arre[M];
    for (int a = 0; a < M; a++)
        arre[a] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arre[j] += xarre[i][j].cant;
        }
    }

    puts("Cantidad de productos vendidos");
    for (int j = 0; j < M; j++)
        printf("Producto %d: %d \n", j + 1, arre[j]);

    return;
}

// Escribir el/los códigos/s del/los medicamento/s por el que se recaudó mayor importe.

void ordenar(ventas xarre[M][N])
{
    int farmacia, i, j;
    ventas aux;
    bool band = false;

    for (farmacia = 0; farmacia < M; farmacia++)
    {
        for (i = 1; i < N; i++)
        {
            band = 0;
            for (j = 0; j < N - 1; j++)
            {
                if (xarre[farmacia][j].cant < xarre[farmacia][j + 1].cant)
                {
                    aux = xarre[farmacia][j - 1];
                    xarre[farmacia][j - 1] = xarre[farmacia][j];
                    xarre[farmacia][j] = aux;
                    band = 1;
                }
            }
            if (band == false)
                break;
        }
    }
    return;
}

void mayorImporte(int xarre[M][N])
{
}

int main()
{
    ventas arre[M][N];

    inicializacion(arre);
    carga(arre);
    totalProductosVendidos(arre);
    ordenar(arre);

    return 0;
}