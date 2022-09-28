/*
Ejercicio 6
El Proyecto Internacional de Código de Barras de la Vida (iBOL, del inglés International Barcode of Life Project) tiene
como objetivo la obtención de las “huellas genéticas” de las especies en peligro de extinción. Para ello se registra
toda la fauna y flora con el fin de constituir una base de datos global que pueda ser consultada por la comunidad
científica de todo el mundo. En particular se registrará información de los países de Argentina, Brasil y Estados
Unidos, conociendo de los mismos: país, continente y especies. De cada especie en peligro de extinción se registra:
nombre, nombre científico, reino (animal/fauna o vegetal/flora) y cantidad de ejemplares.
Realizar un programa en C que a través de funciones óptimas permita:

a) Generar un arreglo de lista a través de punteros con los datos de las especies en extinción para los países
indicados. El ingreso de información se encuentra ordenada por país. Para cada país el ingreso de información
finaliza con el nombre de la especie igual a FIN.

b) Para un nombre de país ingresado por teclado, realizar una función que devuelva al programa principal la
cantidad de especies de la flora y cantidad de especies de la fauna en peligro de extinción. Realizar una función
recursiva que devuelva un dato por parámetro y el otro que lo calcule la función.

c) Incrementar en 200 ejemplares la cantidad de la especie con nombre Petiribí (árbol) en Brasil.

d) Indicar en el programa principal cantidad de ejemplares de Petiribí (árbol presente en Argentina y Brasil)
considerar solamente los ejemplares de los países indicados.

Nota: Para los distintos países se registra una sola vez las distintas especies
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define P 3

typedef struct nodo
{
    char nombre[10];
    char nc[20];
    char reino[10];
    int cant;
    nodo *sig;
} nodo;

typedef struct pais
{
    char pais[10];
    char continente[10];
    nodo *cabeza;
} pais;

typedef nodo *puntero;

void inicializacionPaises(pais xpaises[P])
{
    strcpy(xpaises[0].pais, "Argentina");
    strcpy(xpaises[1].pais, "Brasil");
    strcpy(xpaises[2].pais, "EEUU");
    strcpy(xpaises[0].continente, "America");
    strcpy(xpaises[1].continente, "America");
    strcpy(xpaises[2].continente, "America");
    xpaises[0].cabeza = NULL;
    xpaises[1].cabeza = NULL;
    xpaises[2].cabeza = NULL;
}

void mostrar(pais xpaises[P], int i)
{
    if (i < P)
    {
        printf("Pais: %s Continente: %s \n", xpaises[i].pais, xpaises[i].continente);
        mostrar(xpaises, i + 1);
    }
}

void carga(pais xpaises[P], puntero xespecies)
{
    int i = 0;
    char palabra[20];
    char nombre[20];
    do
    {
        printf("Carga pais %s \n", xpaises[i].pais);
        do
        {
            puts("Ingrese nombre (finaliza con \"FIN\")");
            gets(nombre);

        } while (strcmp(nombre, "FIN") != 0);
        i++;
    } while (i < P);
}

int main()
{
    pais paises[P];
    puntero especies;
    inicializacionPaises(paises);
    mostrar(paises, 0);
    getchar();
    return 0;
}