/*
Ejercicio 7
La Facultad de Ciencias Exactas organizó el Congreso de Informática, y necesita administrar la información relativa a
los 10 tutoriales que se proponen en dicho evento.
Realizar un programa, que a través de un menú de opciones permita:

a) Ingresar los datos correspondientes a cada tutorial: número de tutorial (1-10) y título.
b) Registrar las inscripciones, ingresando el DNI del inscripto y el número de tutorial al que desea asistir.
c) Eliminar alguna inscripción, en cuyo caso se ingresarán los mismos datos que en el ítem anterior.
d) Dado el número de un tutorial, mostrar su título y la cantidad de inscriptos en él.
e) Dado el DNI de una persona, informar el/los tutoriales (número y título) en los que se inscribió.
Nota: Para cada ítem emplear al menos una función recursiva.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 10

typedef struct nodo
{
    int dni;
    struct nodo *sig;
} nodo;

typedef nodo *puntero;

typedef char cadena[30];

typedef struct titulo
{
    cadena nom;
    puntero ins;
} titulo;

void cargaTutoriales(titulo xtuto[T], int i)
{
    if (i < T)
    {
        printf("Ingrese nombre tutorial N°%d \n", i + 1);
        fgets(xtuto[i].nom, 30, stdin);
        cargaTutoriales(xtuto, i + 1);
    }
}

void mostrarTutos(titulo xtuto[T], int i)
{
    if (i < T)
    {
        printf("Tutorial N°%d: %s", i + 1, xtuto[i].nom);
        xtuto[i].ins = NULL;
        mostrarTutos(xtuto, i + 1);
    }
}

void cargaNodos(puntero &cab, int dni)
{
    if (cab == NULL)
    {
        puntero nuevo;
        nuevo = (puntero)malloc(sizeof(nodo));
        nuevo->dni = dni;
        nuevo->sig = NULL;
        cab = nuevo;
    }
    else
    {
        cargaNodos(cab->sig, dni);
    }
}

void cargaIncriptos(titulo xtuto[T])
{
    int numTitulo, dni;
    printf("Ingrese numero de titulo (termina con 0) \n");
    scanf("%d", &numTitulo);
    do
    {
        if (numTitulo >= 0 && numTitulo <= 10)
        {
            printf("Ingrese numero de DNI \n");
            scanf("%d", &dni);
            cargaNodos(xtuto[numTitulo - 1].ins, dni);
        }
        else
            puts("Titulo incorrecto");

        printf("Ingrese numero de titulo (termina con 0) \n");
        scanf("%d", &numTitulo);

    } while (numTitulo != 0);
}

void eliminarNodo(puntero &cab, puntero anterior, puntero auxiliar, int dni)
{

    if (cab->sig != NULL)
    {
        if (cab->dni == dni)
        {
            anterior->sig = cab->sig;
            free(cab);
            puts("El numero fue elimindado de la lista");
        }
        else
        {
            anterior = cab;
            eliminarNodo(cab->sig, anterior, auxiliar, dni);
        }
    }
    else
    {
        if (cab->dni == dni)
        {
            auxiliar = cab->sig;
            free(cab);
            puts("El numero fue elimindado de la lista");
        }
        else
        {
            puts("El elemento no fue encontrado");
        }
    }
}

void eliminarInscripto(titulo xtuto[T])
{
    int numTitulo, dni;
    printf("Ingrese numero de titulo y dni del alumno \n");
    scanf("%d", &numTitulo);
    scanf("%d", &dni);
    eliminarNodo(xtuto[numTitulo - 1].ins, NULL, NULL, dni);
}

void mostrar(puntero cabeza)
{
    if (cabeza != NULL)
    {
        printf("%d  ", cabeza->dni);
        mostrar(cabeza->sig);
    }
}

int main()
{
    titulo tutoriales[T];
    cargaTutoriales(tutoriales, 0);
    mostrarTutos(tutoriales, 0);
    cargaIncriptos(tutoriales);
    mostrar(tutoriales[0].ins);
    eliminarInscripto(tutoriales);
    mostrar(tutoriales[0].ins);
    return 0;
}