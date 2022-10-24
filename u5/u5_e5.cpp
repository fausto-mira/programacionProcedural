/*
Ejercicio 5
Realizar un programa que mediante funciones recursivas permita:
a) Generar una lista enlazada de números enteros positivos, ordenada en forma ascendente. Validar la entrada.
b) Escribir un mensaje indicando si el número del último nodo de la lista es par.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int num;
    struct nodo *sig;
} nodo;

typedef nodo *puntero;

int validar(int num)
{
    if (num > 0)
        return 1;
    else if (num == -1)
        return -1;
    else
        return 0;
}

void insertar(puntero &p, puntero &anterior, puntero &nuevo)
{
    if ((p != NULL) && ((nuevo->num) > (p->num)))
    {
        anterior = p;
        p = p->sig;
        insertar(p, anterior, nuevo);
    }
    else if ((p != NULL) && (nuevo->num) == (p->num))
    {
        puts("Numero ya ingresado");
        return;
    }
    else
    {
        anterior->sig = nuevo;
        nuevo->sig = p;
    }
}

void carga(puntero &cabeza, puntero p, puntero nuevo, puntero anterior, int num, int resultado)
{
    if (cabeza == NULL)
    {
        nuevo = (puntero)malloc(sizeof(nodo));
        puts("Ingrese numero entero positivo(termina con -1)");
        scanf("%d", &num);
        resultado = validar(num);
        if (resultado == 1)
        {
            nuevo->num = num;
            nuevo->sig = NULL;
            cabeza = nuevo;
        }
        else
            puts("Numero no valido");
        carga(cabeza, NULL, NULL, NULL, num, resultado);
    }
    else
    {
        nuevo = (puntero)malloc(sizeof(nodo));
        puts("Ingrese numero entero positivo (termina con -1)");
        scanf("%d", &num);
        int resultado = validar(num);
        if (resultado == 1)
        {
            nuevo->num = num;
            nuevo->sig = NULL;
            p = cabeza;
            insertar(p, anterior, nuevo);
        }
        else if (resultado == -1)
            return;
        else
            puts("Numero no valido");
        carga(cabeza, NULL, NULL, NULL, num, resultado);
    }
}

void mostrar(puntero cabeza)
{
    if (cabeza != NULL)
    {
        printf("%d  ", cabeza->num);
        cabeza = cabeza->sig;
        mostrar(cabeza);
    }
}

void par(puntero cabeza)
{
    if (cabeza != NULL)
    {
        par(cabeza->sig);
        if (((cabeza->num % 2) == 0) && (cabeza->sig == NULL))
            puts("El numero es par\n\n");
        else if ((cabeza->sig == NULL))
            puts("El numero es impar\n\n");
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

int main()
{
    puntero cabeza;
    cabeza = NULL;
    carga(cabeza, NULL, NULL, NULL, 0, 0);

    puts("\n\nARREGLO GENERADO\n");
    mostrar(cabeza);

    printf("\n\nULTIMO ELEMENTO PAR: ");
    par(cabeza);

    liberar(cabeza, NULL);
    cabeza = NULL;
    return 0;
}