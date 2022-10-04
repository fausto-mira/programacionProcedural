/*
//  Mira Faustino
//  44406373
//  21801
//  LCC
*/

/*
Ejercicio 2
Un comercio almacena información de productos nuevos para la venta, por cada uno se conoce: código y precio de
venta.
Se pide que usando funciones para cada ítem resuelva:
Generar una lista enlazada con punteros para almacenar esta información.
Mostrar en forma recursiva la información de la lista.
Indicar en el programa principal cuál es el código del producto más caro (suponer único)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int codigo;
    float precio;
    nodo *sig;
} nodo;

typedef nodo *puntero;

void inicializar(puntero &cabeza)
{
    cabeza = NULL;
}

void cargar(puntero &cabeza)
{
    int x;
    float pr;
    puntero nuevo, aux, anterior;
    puts("Ingrese codigo a cargar. termina con 0");
    scanf("%d", &x);
    while (x != 0)
    {
        puts("Ingrese precio del producto");
        scanf("%f", &pr);
        nuevo = (puntero)malloc(sizeof(struct nodo));
        nuevo->codigo = x;
        nuevo->precio = pr;
        nuevo->sig = cabeza;
        cabeza = nuevo;
        puts("Ingrese numero a cargar. termina con 0");
        scanf("%d", &x);
    }
}

void mostrar(puntero &cabeza)
{
    if (cabeza != NULL)
    {
        printf("Codigo: %d. Precio $%.2f \n", cabeza->codigo, cabeza->precio);
        mostrar(cabeza->sig);
    }
}

float mayorPrecio(puntero &cabeza, float mayor, int cod)
{
    if (cabeza != NULL)
    {
        if (cabeza->precio > mayor)
        {
            mayor = cabeza->precio;
            cod = cabeza->codigo;
        }
        return cod = mayorPrecio(cabeza->sig, mayor, cod);
    }
    else
        return cod;
}

void liberar(puntero &cabeza, puntero p)
{
    if (cabeza != NULL)
    {
        p = cabeza;
        cabeza = cabeza->sig;
        free(p);
        liberar(cabeza, NULL);
    }
}

int main()
{
    puntero productos;
    int resultado;

    inicializar(productos);
    cargar(productos);

    puts("\n\nPRODUCTOS CARGADOS \n");
    mostrar(productos);

    resultado = mayorPrecio(productos, 0, 0);
    printf("\n\nEl codigo del producto con mayor precio es: %d \n\n", resultado);

    liberar(productos, NULL);

    return 0;
}