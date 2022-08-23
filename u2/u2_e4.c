/*Ejercicio 4
Una tienda de ropa comercializa 50 productos diferentes. Por cada producto se conoce: código (número
entero que varía entre 1 y 50), precio de costo y stock.
La tienda hace compras a 22 proveedores, de los cuales se conoce: Nombre y Número de Proveedor (es un
numero entre 1000 y 1022).
Se pide redactar un algoritmo en C que, usando estructuras de datos óptimas y subprogramas eficientes,
permita:

    a) Almacenar en estructuras de datos adecuadas la información de los Producto y de los Proveedores.
    b) Procesar las compras realizadas a los Proveedores, sabiendo que por cada compra se conoce el Número
de Proveedor, Código de Producto y Cantidad de unidades compradas. Con la información de cada
compra se debe actualizar el stock del producto y contar para cada proveedor la compra realizada.
    c) Informar cuánto dinero hay invertido en cada producto.
    d) Generar una nueva estructura de datos que contenga todos los datos de aquellos Proveedores a quienes se
les haya realizado más de 10 compras.
    e) Mostrar la estructura de datos generada en el inciso d) ordenada alfabéticamente por Nombre de
proveedor.
    f) Ingresar por teclado un Nombre de proveedor e informar su Número y cantidad de compras realizadas.
Nota: Utilizar la estructura de datos generada en el inciso d). */

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 5
#define M 2

typedef struct
{
    int cod, stk;
    float prc;
} productos;

typedef struct
{
    int numProv, ventas;
    char nom[M];
} proveedores;

void cargaProductos(productos xprod[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        puts("Ingrese codigo del producto");
        scanf("%d", &xprod[i].cod);
        puts("Ingrese precio del producto");
        scanf("%f", &xprod[i].prc);
        puts("Ingrese stock del producto");
        scanf("%d", &xprod[i].stk);
    }
    return;
}

void cargaProveedores(proveedores xprove[M])
{
    for (int i = 0; i < M; i++)
    {
        puts("Ingrese nombre del proveedor");
        scanf("%s", xprove[i].nom);
        puts("Ingrese numero de proveedor");
        scanf("%d", &xprove[i].numProv);
        puts("Ingrese la cantidad de ventas del proveedor");
        scanf("%d", &xprove[i].ventas);
    }
    return;
}

void compras(productos xprod[N], proveedores xprove[M])
{
    int numProv, codProd, cantUni;
    puts("Ingrese numero de proveedor(termina con '0'");
    scanf("%d", &numProv);
    while (numProv != 0)
    {
        puts("Ingrese codigo del producto");
        scanf("%d", &codProd);
        puts("Ingrese cantidad de unidades compradas");
        scanf("%d", &cantUni);
        xprod[codProd - 1].stk += cantUni;
        xprove[numProv - 1000].ventas++;
        puts("Ingrese numero de proveedor(termina con '0'");
        scanf("%d", &numProv);
    }
    return;
}

void dineroInvertido(productos xprod[N])
{
    int i;
    puts("DINERO INVERTIDO EN CADA PRODUCTO");
    for (i = 0; i < N; i++)
    {
        printf("Productos %d: %.2f \n", i + 1, (xprod[i].prc * xprod[i].stk));
    }
    return;
}

int prove10(proveedores xprove[M], proveedores xprove2[M])
{
    int i, cont = 0;
    for (i = 0; i < M; i++)
    {
        if (xprove[i].ventas > 10)
        {
            xprove2[cont] = xprove[i];
            cont++;
        }
    }
    return (cont);
}

void ordenar(proveedores xprove2[M], int xcota)
{
    proveedores temporal;
    for (int i = 0; i < xcota; i++)
    {
        for (int j = 0; i < xcota - i - 1; i++)
        {
            if (strcmp(xprove2[j].nom, xprove2[j + 1].nom) > 0)
            {
                temporal = xprove2[j];
                xprove2[j] = xprove2[j + 1];
                xprove2[j + 1] = temporal;
            }
        }
    }
    return;
}

void mostrar(proveedores xprove2[M], int xcota)
{
    for (int i = 0; i < xcota; i++)
    {
        puts(xprove2[i].nom);
    }
    return;
}

int busqueda(proveedores xprove2[M], int xcota)
{
    char busqueda[M];
    //puts("Ingrese nombre del prove a buscar");
    printf("Ingrese nombre del prove a buscar \n");
    fflush(stdin);
    //fgets(busqueda,M,stdin);
    scanf("%s", busqueda);
    int izquierda = 0, derecha = xcota - 1;
    while (izquierda <= derecha)
    {
        int indiceDeLaMitad = floor((izquierda + derecha) / 2);
        char *elementoDeLaMitad = xprove2[indiceDeLaMitad].nom;

        int resultado = strcmp(busqueda, elementoDeLaMitad);
        if (resultado == 0)
            return indiceDeLaMitad;

        if (resultado < 0)
        {
            derecha = indiceDeLaMitad - 1;
        }
        else
        {
            izquierda = indiceDeLaMitad + 1;
        }
    }
    return -1;
}

int main()
{
    productos prod[N];
    proveedores prove[M], prove2[M];
    int cota, resultadoBusqueda;
    cargaProductos(prod);
    cargaProveedores(prove);
    compras(prod, prove);
    dineroInvertido(prod);
    cota = prove10(prove, prove2);
    ordenar(prove2, cota);
    mostrar(prove2, cota);
    resultadoBusqueda = busqueda(prove2, cota);
    if (resultadoBusqueda != -1)
    {
        printf("El elemento se encontro en la posicion %d", resultadoBusqueda);
    }
    else
    {
        puts("No se encontro el prove ingresado");
    }
    return 0;
}