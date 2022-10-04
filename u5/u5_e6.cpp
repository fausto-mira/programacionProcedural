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
#include <ctype.h>
#define P 3

typedef struct nodo
{
    char nombre[10];
    char nc[20];
    char reino[10];
    int cant;
    nodo *sig;
} nodo;

typedef nodo *puntero;

typedef struct pais
{
    char pais[10];
    char continente[10];
    puntero cabeza;
} pais;

typedef nodo *puntero;

void inicializacionPaises(pais xpaises[P])
{
    strcpy(xpaises[0].pais, "argentina");
    strcpy(xpaises[1].pais, "brasil");
    strcpy(xpaises[2].pais, "eeuu");
    strcpy(xpaises[0].continente, "america");
    strcpy(xpaises[1].continente, "america");
    strcpy(xpaises[2].continente, "america");
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

void insertar(puntero &cabeza, puntero especie)
{
    if (cabeza == NULL)
        cabeza = especie;
    else
        insertar(cabeza->sig, especie);
}

void carga(pais xpaises[P])
{
    int i = 0, c;
    puntero especie;
    char nombre[30], nomCientifico[30], reino[10];
    int cant;
    do
    {
        printf("INGRESO ESPECIES PAIS %s ==============================\n\n", xpaises[i].pais);
        puts("Ingrese nombre de especie ( finaliza con nombre \"FIN\")");
        fflush(stdin);
        fgets(nombre, 30, stdin);
        while (strncmp(nombre, "FIN", 3) != 0)
        {
            puts("Ingrese nombre cinetifico de la especie");
            fflush(stdin);
            fgets(nomCientifico, 30, stdin);
            fflush(stdin);
            puts("Ingrese reino al que pertenece");
            fgets(reino, 10, stdin);
            puts("Ingrese cantidad de ejemplares");
            scanf("%d", &cant);
            getchar(); // para no crear errores entre scanf y fgets, se coloca un getchar despues de cada scanf
            especie = (puntero)malloc(sizeof(nodo));
            strcpy(especie->nombre, nombre);
            strcpy(especie->nc, nomCientifico);
            strcpy(especie->reino, reino);
            especie->cant = cant;
            insertar(xpaises[i].cabeza, especie);
            puts("Ingrese nombre de especie ( finaliza con nombre \"FIN\")");
            fflush(stdin);
            fgets(nombre, 29, stdin);
            // fflush(stdin);
        }
        i++;
    } while (i < 3);
}

int contador(puntero cabeza, int flora, int &fauna)
{
    if (cabeza != NULL)
    {
        if (strncmp(cabeza->reino, "flora", 5) == 0)
            flora += 1;
        if (strncmp(cabeza->reino, "fauna", 5) == 0)
            fauna += 1;
        return flora = contador(cabeza->sig, flora, fauna);
    }
    else
        return (flora);
}

void contadorFaunaFlora(pais xpaises[P])
{
    char pais[10], pais2[10];
    int resultado = -1, i, flora, fauna = 0;
    do
    {
        puts("Ingrese nombre del pais a buscar");
        fflush(stdin);
        fgets(pais, 10, stdin);
        for (i = 0; i < P; i++)
        {
            if (strncmp(pais, xpaises[i].pais, strlen(xpaises[i].pais)) == 0)
                resultado = i;
        }
        if (resultado == -1)
            puts("Pais no encontrado");

    } while (resultado == -1);
    puts("Pais encontrado");
    flora = contador(xpaises[resultado].cabeza, 0, fauna);
    printf("Cantidad de reino Fauna: %d \n", fauna);
    printf("Cantidad de reino Flora: %d \n", flora);
}

// Incrementar en 200 ejemplares la cantidad de la especie con nombre Petiribí (árbol) en Brasil.

void peteribi200(puntero cabeza)
{
    if (cabeza != NULL)
    {
        if (strncmp(cabeza->nombre, "peteribi", strlen("peteribi")))
        {
            cabeza->cant += 200;
            printf("Peteribi modificado. Nuevo valor: %d \n", cabeza->cant);
            return;
        }
        peteribi200(cabeza->sig);
    }
    else
    {
        puntero nuevo;
        nuevo = (puntero)malloc(sizeof(nodo));
        strcpy(nuevo->nombre, "peteribi");
        nuevo->cant = 200;
        cabeza = nuevo;
        puts("Como no se encontro la especie, la misma fue creada e inicializada en 200");
    }
}

// Indicar en el programa principal cantidad de ejemplares de Petiribí (árbol presente en Argentina y Brasil)
// considerar solamente los ejemplares de los países indicados.

void cantPeteribi(puntero cabeza, char nombre[10])
{
    if (cabeza != NULL)
    {
        if (strncmp(cabeza->nombre, "peteribi", strlen("peteribi")))
        {
            printf("Cantidad Peteribi en %s: %d \n", nombre, cabeza->cant);
            return;
        }
        cantPeteribi(cabeza->sig, nombre);
    }
}

void liberarNodo(puntero &cabeza, puntero p)
{
    if (cabeza != NULL)
    {
        p = cabeza;
        cabeza = cabeza->sig;
        free(p);
        liberarNodo(cabeza, NULL);
    }
}

void liberar(pais xpaises[P])
{
    for (int i = 0; i < P; i++)
    {
        liberarNodo(xpaises[i].cabeza, NULL);
    }
}

int main()
{
    pais paises[P];
    puntero especies;
    inicializacionPaises(paises);
    mostrar(paises, 0);
    carga(paises);
    contadorFaunaFlora(paises);
    peteribi200(paises[1].cabeza);
    cantPeteribi(paises[0].cabeza, paises[0].pais);
    cantPeteribi(paises[1].cabeza, paises[1].pais);
    liberar(paises);
    getchar();
    return 0;
}