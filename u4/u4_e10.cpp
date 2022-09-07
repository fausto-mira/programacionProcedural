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
        scanf("%ld", &xsucursales[s].tel);
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

void ventasPorSucursal(int xtabla[S][P], int s, int p, int acum)
{
    if (s < S)
    {
        if (p < P)
        {
            acum += xtabla[s][p];
            ventasPorSucursal(xtabla, s, p + 1, acum);
        }
        printf("cant de unidades vendidas sucursal %d: %d", s + 1, acum);
        ventasPorSucursal(xtabla, s + 1, 0, 0);
    }
}

// Importe total de productos vendidos por sucursal.

void importeVendidoPorSucursal(producto xcatalogo[P], int xtabla[S][P], int s, int p, float acum)
{
    if (s < S)
    {
        if (p < P)
        {
            acum += xtabla[s][p] * xcatalogo[p].precio;
            importeVendidoPorSucursal(xcatalogo, xtabla, s, p + 1, acum);
        }
        printf("Importe vendido sucursal %d: $%f", s + 1, acum);
        importeVendidoPorSucursal(xcatalogo, xtabla, s + 1, 0, 0);
    }
}

// Obtener la sucursal (nombre) y el producto (nombre y precio), que registró el mayor importe de venta.
int mayorImporteVenta(producto catalogo[P], int xtabla[S][P], int s, int p, float mayor, int posS, int &posP)
{
    if (s < S)
    {
        if (p < P)
        {
            if ((xtabla[s][p] * catalogo[p].precio) > mayor)
            {
                mayor = xtabla[s][p] * catalogo[p].precio;
                posS = s;
                posP = p;
            }
            mayorImporteVenta(catalogo, xtabla, s, p + 1, mayor, posS, posP);
        }
        return mayorImporteVenta(catalogo, xtabla, s + 1, 0, mayor, posS, posP);
    }
    else
        return posS;
}

// Dado un número de sucursal, indicar el producto (todos los datos) que registró el mayor consumo de calorías
//(suponer único).

int mayorConsumoCalorias(int xtabla[S][P], producto catalogo[P], int numSucursal, int mayor, int p, int posP)
{
    if (p < P)
    {
        if ((xtabla[numSucursal - 1][p] * catalogo[p].calorias) > mayor)
        {
            mayor = xtabla[numSucursal - 1][p] * catalogo[p].calorias;
            posP = p;
        }
        return mayorConsumoCalorias(xtabla, catalogo, numSucursal, mayor, p + 1, posP);
    }
    else
        return posP;
}

// Dado un número de producto, indicar la sucursal (nombre y teléfono) donde se registró el menor importe
// vendido.

int menorImporteVendido(int xtabla[S][P], tienda xsucursal[S], producto xcatalogo[P],
                        int numProducto, int s, float menor, int posS)
{
    if (s < S)
    {
        if ((xtabla[s][numProducto - 1] * xcatalogo[numProducto - 1].precio) < menor)
        {
            menor = xtabla[s][numProducto - 1] * xcatalogo[numProducto - 1].precio;
            posS = s;
        }
        return menorImporteVendido(xtabla, xsucursal, xcatalogo, numProducto, s + 1, menor, posS);
    }
    else
        return posS;
}

int main()
{
    tienda sucursales[S];
    producto catalogo[P];
    int tabla[S][P];
    int posP = 0, posS, numSucursal, numProducto;
    inicializacionCatalogo(catalogo, 0);
    inicializacionSucursales(sucursales, 0);
    inicializacionTabla(tabla, 0, 0);
    mostrarTabla(tabla, 0, 0);
    cargaTabla(tabla, -1, -1, 0);
    mostrarTabla(tabla, 0, 0);
    ventasPorSucursal(tabla, 0, 0, 0);
    importeVendidoPorSucursal(catalogo, tabla, 0, 0, 0);
    posS = mayorImporteVenta(catalogo, tabla, 0, 0, 0, 0, posP);
    printf("El mayor importe de ventas fue registrado por la sucursal %s con el prod %s precio: $%f", sucursales[posS], catalogo[posP].precio);
    printf("Ingrese numero de sucursal para calcular mayor consumo calorias \n");
    scanf("%d", &numSucursal);
    mayorConsumoCalorias(tabla, catalogo, numSucursal, 0, 0, 0);
    printf("Ingrese numero de producto para calcular menor importe \n");
    scanf("%d", &numProducto);
    menorImporteVendido(tabla, sucursales, catalogo, numProducto, 0, 9999999, 0);
    return 0;
}
