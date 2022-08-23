/*Ejercicio 2
Un local comercial de ventas de repuestos de automotores desea obtener cierta información sobre todas las ventas
registradas en un periodo de tiempo dado. El comercio cuenta con 250 artículos, almacenados en una estructura y
de los cuales se conocen los siguientes datos: Código, Nombre, Precio Unitario y Stock.
Se procesan las ventas y los datos ingresados de cada una son: Nombre del artículo, Cantidad de unidades vendidas.
(con esta información actualizar el stock de cada artículo). El ingreso de ventas termina con nombre igual “FIN”.
Se pide realizar un programa en C, que utilizando subprogramas óptimos y estructuras adecuadas permita:
1. Procesar las ventas registradas en ese periodo de tiempo.
2. Mostrar en el main la cantidad de artículos que quedaron con stock nulo y cuantos tienen un precio mayor a
$7000.
3. Imprimir los nombres de los 20 artículos que quedaron con mayor stock.
4. Indicar para cada artículo el monto total obtenido por ventas.*/

#include <stdio.h>
#include <string.h>
#define n 3

typedef struct articulo
{
    int stock, vendidos;
    char nombre[20];
    float precio;
} articulo;

void inicializar(articulo xventas[n])
{
    char nombre[20];

    puts("INICIALIZACION PRODUCTOS");

    for (int i = 0; i < n; i++)
    {
        printf("Ingrese nombre del producto n %d \n", i + 1);
        scanf("%s", nombre);
        strcpy(xventas[i].nombre, nombre);
        puts("Ingrese precio del producto");
        scanf("%d", &xventas[i].precio);
        puts("Ingrse stock");
        scanf("%d", &xventas[i].stock);
        xventas[i].vendidos = 0;
    }
    return;
}

int busqueda(articulo xventas[n], char xnombre[20])
{
    int resultado = -1, i;

    i = 0;
    while ((i < n) && (resultado == -1))
    {
        if (strcmp(xventas[i].nombre, xnombre) == 0)
            resultado = i;
        else
            i++;
    }
    return (resultado);
}

void cargaVentas(articulo xventas[n])
{

    char nombre[20];
    int unidadesVendidas, resultado;
    puts("CARGA DE VENTAS");

    puts("Ingrese nombre del articulo (termina con 'FIN')");
    // fgets(nombre, 20, stdin);
    fflush(stdin);
    scanf("%s", nombre);

    while (strcmp(nombre, "FIN") != 0)
    {

        resultado = busqueda(xventas, nombre);

        if (resultado != -1)
        {
            puts("Ingrese cantidad de unidades vendidas");
            scanf("%d", &unidadesVendidas);

            if (unidadesVendidas <= xventas[resultado].stock)
            {
                xventas[resultado].stock -= unidadesVendidas;
                xventas[resultado].vendidos += unidadesVendidas;
            }
            else
                puts("Stock insuficiente");
        }
        else
            puts("Producto no encontrado");

        puts("Ingrese nombre del articulo (termina con 'FIN')");
        // fgets(nombre, 20, stdin);
        fflush(stdin);
        scanf("%s", nombre);
    }

    return;
}

// Mostrar en el main la cantidad de artículos que quedaron con stock nulo y cuantos tienen un precio mayor a $7000.

int stockNulo(articulo xventas[n], int &xMayor7000)
{
    int nulos = 0;
    for (int i = 0; i < n; i++)
    {
        if (xventas[i].stock == 0)
            nulos++;

        if (xventas[i].precio > 7000)
            xMayor7000++;
    }
    return (nulos);
}

// Imprimir los nombres de los 20 artículos que quedaron con mayor stock.

void ordenar(articulo xventas[n])
{
    int i, j, bandera;
    articulo aux;

    for (i = 1; i < n; i++)
    {
        bandera = 0;
        for (j = 0; j < n - 1; j++)
        {
            if (xventas[j - 1].stock < xventas[j].stock)
            {
                aux = xventas[j - 1];
                xventas[j - 1] = xventas[j];
                xventas[j] = aux;
                bandera = 1;
            }
        }
        if (bandera == 0)
            break;
    }
    return;
}

void mayorStock(articulo xventas[n])
{
    puts("Nombre de los 20 articulos con mayor stock");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%s, ", xventas[i].nombre);
    }
    printf("%s. \n", xventas[n - 1].nombre);
    return;
}

// Indicar para cada artículo el monto total obtenido por ventas.

void totalVentas(articulo xventas[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("Monto obtenido prod %d: %.2f \n", i + 1, xventas[i].vendidos * xventas[i].precio);
    }
    return;
}

int main()
{
    articulo ventas[n];
    int mayor7000 = 0, nulos;

    inicializar(ventas);
    cargaVentas(ventas);

    nulos = stockNulo(ventas, mayor7000);
    printf("Cantidad de productos con stock nulos: %d \n", nulos);
    printf("Cantidad de productos con precio superior a 7000: %d \n", mayor7000);

    ordenar(ventas);
    mayorStock(ventas);
    totalVentas(ventas);

    return 0;
}