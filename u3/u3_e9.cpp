/*Ejercicio 9

Una empresa de seguros procesa la información de las ventas que han realizado sus 10 promotores. De cada uno de
los 10 promotores se conoce el código de sector donde trabaja (número entre 30 y 37) codificado: 30: Moto - 31:
Auto - 32: Camioneta - 33: Camión - 34: Ómnibus de Corta distancia - 35: Ómnibus de larga distancia - 36: Combis de
pasajeros - 37: taxis.
De cada seguro (son 3 tipos de seguros distintos) se conoce el tipo (una letra entre “A” y
“C”), el nombre y su precio. Los tipos de seguro se codifican: “A”: Seguro contra terceros, “B”: Seguro de Incendio y
“C”: Seguro Total.

Nota: Leer la información que se pide, y de acuerdo a eso, ¿Qué estructura es la más adecuada para el
almacenamiento de los datos?

Se pide realizar un programa que permita (utilizando Menú de opciones):
a) Ingresar las ventas de seguros realizadas. Por cada venta se ingresa número de promotor (de 1...10) y tipo de
seguro(“A”…“C”). Las ventas no traen ningún orden específico y termina el ingreso con número de promotor
igual a 0.
b) Ingresar un tipo de seguro e indicar en qué sector se lo vende más y cuantos promotores tiene ese sector.
c) Dado un número de sector, indicar cuál es el seguro que más se consume.
d) Indicar para cada tipo de seguro, el nombre y el importe total de venta.*/

#include <stdio.h>
#include <string.h>
#define M 7
#define N 3
#define PROM 10

typedef struct seguro
{
    char tipo, nombre[20];
    float precio;
} seguro;

void inicializacionPromotor(int xpromotores[PROM])
{
    for (int i = 0; i < PROM; i++)
    {
        printf("Ingrese sector de promotor %d", i + 1);
        scanf("%d", &xpromotores[i]);
    }
    return;
}

void inicializacionSeguros(seguro xseg[N])
{
    char nombre[20];
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese nombre del seguro %d", i + 1);
        scanf("%s", nombre);
        strcpy(xseg[i].nombre, nombre);
        printf("Ingrese tipo");
        scanf("%c", &xseg[i].tipo);
        printf("Ingrese precio del seguro");
        scanf("%f", &xseg[i].precio);
    }
    return;
}

int busquedaSector(char xtipo)
{
    int xtipoNum;
    switch (xtipo)
    {
    case 'A':
        xtipoNum = 0;
        break;
    case 'B':
        xtipoNum = 1;
        break;
    case 'C':
        xtipoNum = 2;
        break;
    default:
        xtipoNum = -1;
    }
    return (xtipoNum);
}

void carga(int xpromotores[PROM], int xtabla[M][N])
{
    int numProm, numSector;
    char tipo, tipoNum;
    printf("Ingrese numero de promotor(termina con 0)");
    scanf("%d", &numProm);
    while (numProm)
    {
        numSector = xpromotores[numProm] - 30;

        printf("Ingrese tipo de seguro(caracter 'A', 'B', 'C')");
        scanf("%c", &tipo);

        tipoNum = busquedaSector(tipo);
        if (tipoNum != -1)
            xtabla[numSector][tipoNum];
        else
            printf("Tipo no encontrado");

        printf("Ingrese numero de promotor(termina con 0)");
        scanf("%d", &numProm);
    }
    return;
}

// Ingresar un tipo de seguro e indicar en qué sector se lo vende más y cuantos promotores tiene ese sector.

void seguroMasVendido(int xtabla[M][N], int xpromotores[PROM])
{
    int masVendido = 0, tipoNum, sector, cont = 0;
    char tipo;
    printf("Ingrese un tipo de seguro(caracter 'A', 'B', 'C')");
    scanf("%c", &tipo);
    tipoNum = busquedaSector(tipo);

    for (int i = 0; i < M; i++)
    {
        if (xtabla[i][tipoNum] > masVendido)
        {
            masVendido = xtabla[i][tipoNum];
            sector = i;
        }
    }
    for (int i = 0; i < PROM; i++)
        if (xpromotores[i] == sector + 30)
            cont++;
    printf("El sector en el que se vende mas es en el %d. Promotores en este sector: %d", sector + 30, cont);

    return;
}

int main()
{
    int promotores[PROM];
    seguro seguros[N];
    int tabla[M][N];

    return 0;
}