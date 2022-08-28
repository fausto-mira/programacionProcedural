/*Ejercicio 4
Una industria comercializa 70 productos codificados entre 100 y 169. De cada producto se conoce el código de
producto y precio unitario. Además, se cuenta con la información de las ventas realizadas durante el fin de semana.
Por cada venta se ingresa código de producto y cantidad de unidades, finalizando el ingreso con código de producto
igual a cero.
Se pide realizar un programa en C, que utilizando funciones óptimas y estructuras adecuadas permita:
a) Total de unidades vendidas de cada uno de los productos.
b) Indicar en el main el código del producto que recaudó mayor importe, el mayor importe y la cantidad de
unidades vendidas.
c) En función del total de unidades vendidas, decir de cuantos productos se vendieron 20, 21, 22.. 50
unidades*/

#include <stdio.h>
#define N 70

typedef struct ventas
{
    float precio;
    int cant, codigo;
} ventas;

void inicializacion(ventas xarre[N])
{
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese precio del producto %d:", i + 1);
        scanf("%f", &xarre[i].precio);
        xarre[i].cant = 0;
        xarre[i].codigo = i + 100;
    }
    return;
}

void carga(ventas xarre[N])
{
    int codigo, cantidad;
    puts("Ingrese codigo del producto (termina con '0')");
    scanf("%d", &codigo);

    while (codigo != 0)
    {
        puts("Ingrese cantidad de unidades vendidas");
        scanf("%d", &cantidad);
        xarre[N - 100].cant += cantidad;

        puts("Ingrese codigo del producto (termina con '0')");
        scanf("%d", &codigo);
    }
    return;
}

// Total de unidades vendidas de cada uno de los productos.

void mostrarTotal(ventas xarre[N])
{
    puts("TOTAL DE UNIDADES VENDIDAS");
    for (int i = 0; i < N; i++)
    {
        printf("Producto %d: %d", i + 100, xarre[i].cant);
    }
    return;
}

// Indicar en el main el código del producto que recaudó mayor importe, el mayor importe y la cantidad de
// unidades vendidas.

int mayorImporte(ventas xarre[N], float &importeMayor)
{
    float mayor = 0, resultado;
    int posMayor;

    for (int i = 0; i < N; i++)
    {
        resultado = xarre[i].cant * xarre[i].precio;
        if (resultado > mayor)
        {
            posMayor = i;
            importeMayor = resultado;
        }
    }
    return (posMayor);
}

// En función del total de unidades vendidas, decir de cuantos productos se vendieron 20, 21, 22.. 50
// unidades

void ordenar(ventas xarre[N])
{
    ventas aux;
    int bandera = 1;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (arre[j].cant > arre[j + 1].cant)
            {
                bandera = 1;
                aux = xarre[j];
                xarre[j] = xarre[j + 1];
                xarre[j + 1] = aux;
            }
        }
        if (bandera)
            break;
    }
    return;
}

void totalUnidades(ventas xarre[N])
{
    ordenar(xarre);

    for (int i = 20; i <= 50; i++)
    {
        printf("Producto")
    }
}

int main()
{
    float importeMayor;
    int posicion;
    ventas arre[N];
    inicializacion(arre);
    carga(arre);

    posicion = mayorImporte(arre, importeMayor);
    puts("PRODUCTO QUE RECAUDO MAYOR IMPORTE");
    printf("Codigo: %d \n", posicion);
    printf("Importe recaudado: %f", importeMayor);
    printf("Cantidad de unidades vendidas: %d", arre[posicion]);

    return 0;
}