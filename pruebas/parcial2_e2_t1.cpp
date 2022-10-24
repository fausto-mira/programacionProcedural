#include <stdio.h>
#include <stdlib.h>

typedef char cadena[30];

typedef struct producto
{
    int cod, tipo, stock;
    float precio;

} producto;

typedef struct nodo
{
    producto prod;
    nodo *sig;
} nodo;

typedef nodo *puntero;

void carga(puntero &cabeza)
{
    int cod;
    puntero nuevo;
    puts("Ingrese codigo de producto(termina con 0)");
    scanf("%d", &cod);
    while (cod)
    {
        nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->prod.cod = cod;
        puts("Ingrese tipo de prod(1,2,3)");
        scanf("%d", &nuevo->prod.tipo);
        puts("Ingrese stock");
        scanf("%d", &nuevo->prod.stock);
        puts("Ingrese precio");
        scanf("%f", &nuevo->prod.precio);
        nuevo->sig = cabeza;
        cabeza = nuevo;
        puts("Ingrese codigo de producto(termina con 0)");
        scanf("%d", &cod);
    }
}

void mostrar3(puntero cabeza)
{
    if (cabeza != NULL)
    {
        if (cabeza->prod.tipo == 3)
            printf("Codigo %d\n", cabeza->prod.cod);
        mostrar3(cabeza->sig);
    }
}

float buscarMayorPrecio(puntero cabeza, float mayor)
{
    if (cabeza != NULL)
    {
        if (cabeza->prod.precio > mayor)
            mayor = cabeza->prod.precio;
        return mayor = buscarMayorPrecio(cabeza->sig, mayor);
    }
    else
        return mayor;
}

void mostrarProdPrecioMayor(puntero cabeza, float mayor)
{
    if (cabeza != NULL)
    {
        if (cabeza->prod.precio == mayor)
            printf("Codigo: %d. Stock: %d\n", cabeza->prod.cod, cabeza->prod.stock);
        mostrarProdPrecioMayor(cabeza->sig, mayor);
    }
}

void liberarLista(puntero &cabeza)
{
    if (cabeza != NULL)
    {
        liberarLista(cabeza->sig);
        free(cabeza);
    }
}

int main()
{
    puntero cabeza = NULL;
    float mayorPrecio;

    carga(cabeza);

    puts("\nCodigos de los productos del tipo 3");
    mostrar3(cabeza);

    mayorPrecio = buscarMayorPrecio(cabeza, 0);
    printf("\nEl mayor precio registrado es: $%.2f \n\n", mayorPrecio);

    puts("Productos con el mayor precio:");
    mostrarProdPrecioMayor(cabeza, mayorPrecio);

    liberarLista(cabeza);
    cabeza = NULL;
    puts("\n\nLista eliminada\n\n");

    return 0;
}