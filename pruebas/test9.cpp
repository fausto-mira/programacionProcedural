#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;

typedef nodo *puntero;

void cargarPorCabeza(puntero &cabeza) // insercion por cabeza
{
    int x;
    printf("Ingrese numero a cargar. termina con 0 \n");
    scanf("%d", &x);
    while (x != 0)
    {
        puntero nuevo, aux, anterior;
        nuevo = (puntero)malloc(sizeof(struct nodo)); // creo un nuevo nodo
        nuevo->dato = x;                              // guardo el dato en el nuevo nodo
        nuevo->sig = cabeza;                          // le asigno la cabeza al nuevo nodo
        cabeza = nuevo;                               // la cabeza sera ahora el nuevo nodo
        printf("Ingrese numero a cargar. termina con 0 \n");
        scanf("%d", &x);
    }
}

void cargaPorCola(puntero &cabeza)
{
    puntero nuevo, p;
    int x;
    printf("Ingrese numero a cargar. termina con 0 \n");
    scanf("%d", &x);
    while (x != 0)
    {
        nuevo = (puntero)malloc(sizeof(nodo));
        nuevo->dato = x;
        nuevo->sig = NULL;
        if (cabeza == NULL)
        {
            cabeza = nuevo;
        }
        else
        {
            p = cabeza;
            while (p->sig != NULL)
                p = p->sig;
            p->sig = nuevo;
        }
        printf("Ingrese numero a cargar. termina con 0 \n");
        scanf("%d", &x);
    }
}

void busqueda(puntero &cabeza, puntero nuevo)
{
    if (cabeza == NULL)
        cabeza = nuevo;
    else
        busqueda(cabeza->sig, nuevo);
}

void cargaPorColaRecursivo(puntero &cabeza, int x)
{
    puts("Ingrese numero a cargar. termina con 0");
    scanf("%d", &x);
    if (x != 0)
    {
        puntero nuevo, p;
        nuevo = (puntero)malloc(sizeof(nodo));
        nuevo->dato = x;
        nuevo->sig = NULL;
        busqueda(cabeza, nuevo);
        cargaPorColaRecursivo(cabeza, x);
    }
}

void mostrar(puntero cabeza)
{
    if (cabeza != NULL)
    {
        printf("%d", cabeza->dato);
        mostrar(cabeza->sig);
    }
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

/*
void liberar(puntero &cabeza, puntero p)
{
    if (cabeza != NULL)
    {
        liberar(cabeza->sig, NULL);
        free(cabeza);
    }
}
*/

int main()
{
    puntero cabeza, p;
    cabeza = NULL;
    int opcion;
    // cargarPorCabeza(cabeza);
    // cargaPorCola(cabeza);
    cargaPorColaRecursivo(cabeza, 0);
    mostrar(cabeza);
    liberar(cabeza, p);
    mostrar(cabeza);
    printf("\n\n");
    return 0;
}