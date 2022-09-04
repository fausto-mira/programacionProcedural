/*Ejercicio 10
Una cadena de comidas rápidas necesita información estratégica que permita apoyar la toma de decisiones en
relación a las ventas realizadas en cada una de las 4 sucursales que dispone en la ciudad. De cada sucursal se
conoce: número, nombre, dirección y teléfono. En cuanto a los 10 productos distintos que comercializa, se conoce:
código de producto, nombre, calorías y precio. Por cada venta realizada, se ingresa el número de sucursal, código de
producto y cantidad. Esta información no tiene ningún orden en particular, y el ingreso termina con número de
sucursal 0. Concretamente necesita conocer:
a) Cantidad de productos vendidos por sucursal.
b) Importe total de productos vendidos por sucursal.
c) Obtener la sucursal (nombre) y el producto (nombre y precio), que registró el mayor importe de venta.
d) Dado un número de sucursal, indicar el producto (todos los datos) que registró el mayor consumo de calorías
(suponer único).
e) Dado un número de producto, indicar la sucursal (nombre y teléfono) donde se registró el menor importe
vendido.
NOTA: Es importante optimizar el código, por lo tanto, cuando deba trabajar sobre una fila de la tabla, pasar sólo la
fila. Realice un menú de opciones y validar los datos de entrada.
*/

#include <stdio.h>
#define S 4  // sucursales
#define P 10 // productos

typedef struct tienda
{
    int num;
    long tel;
    char nombre[20], direccion[30];

} tienda;

typedef struct producto
{
    long cod;
    int calorias;
    char nombre[20];
    float precio;
} producto;

void inicializacionCatalogo(producto xcatalogo[P], int p)
{

    if (p < P)
    {
        printf("Ingrese para el prod %d: calorias, nombre y precio\n", p + 1);
        xcatalogo[p].cod = p + 1;
        scanf("%d", &xcatalogo[p].calorias);
        scanf("%s", xcatalogo[p].nombre);
        scanf("%f", &xcatalogo[p].precio);

        inicializacionCatalogo(xcatalogo, p + 1);
    }
}
void inicializacionSucursales(tienda xsucursales[S], int s)
{
    if (s < S)
    {
        printf("Ingrese para la sucursal %d: telefono, nombre, direccion\n", s + 1);
        xsucursales[s].num = s + 1;
        scanf("%d", &xsucursales[s].tel);
        scanf("%s", xsucursales[s].nombre);
        scanf("%s", xsucursales[s].direccion);

        inicializacionSucursales(xsucursales, s + 1);
    }
}

void inicializacionTabla(int xtabla[S][P], int s, int p)
{
    if (s < S)
    {
        if (p < P)
        {
            xtabla[s][p] = 0;
            inicializacionTabla(xtabla, s, p + 1);
        }
        inicializacionTabla(xtabla, s + 1, 0);
    }
}

void cargaTabla(int xtabla[S][P], int num, int cod, int cant)
{
    printf("Ingrese codigo del producto(termina con'0') \n");
    scanf("%d", &cod);

    if (cod != 0)
    {
        printf("ingrese numero de sucursal\n");
        scanf("%d", &num);
        printf("Ingrese cantidad de unidades vendidas\n");
        scanf("%d", &cant);
        xtabla[num - 1][cod - 1] += cant;
        cargaTabla(xtabla, -1, -1, 0);
    }
}

void mostrarTabla(int xtabla[S][P], int i, int j)
{
    if (i < S)
    {
        if (j < P)
        {
            printf("%5d ", xtabla[i][j]);
            mostrarTabla(xtabla, i, j + 1);
        }
        else
        {
            printf("\n");
            mostrarTabla(xtabla, i + 1, 0);
        }
    }
}

// Cantidad de productos vendidos por sucursal.

void ventasPorSucursal;

int main()
{
    tienda sucursales[S];
    producto catalogo[P];
    int tabla[S][P];
    inicializacionCatalogo(catalogo, 0);
    inicializacionSucursales(sucursales, 0);
    inicializacionTabla(tabla, 0, 0);
    mostrarTabla(tabla, 0, 0);
    cargaTabla(tabla, -1, -1, 0);
    mostrarTabla(tabla, 0, 0);
    return 0;
}
