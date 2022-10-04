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
#include <unistd.h>
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

void totalDeInscriptos(puntero cabeza, int total)
{
    if (cabeza != NULL)
    {
        total += 1;
        totalDeInscriptos(cabeza->sig, total);
    }
    else
    {
        printf("Total de inscriptos: %d", total);
    }
}

void total(titulo xtutoriales[T])
{
    int num;
    puts("Ingrese numero de tutorial para mostrar total de inscriptos");
    scanf("%d", &num);
    printf("Tutorial %s, ", xtutoriales[num - 1].nom);
    totalDeInscriptos(xtutoriales[num - 1].ins, 0);
}

// Dado el DNI de una persona, informar el/los tutoriales (número y título) en los que se inscribió.

void busqueda(titulo xtutoriales[T], puntero cabeza, int dni, int i)
{
    if (i < T)
    {
        if (cabeza != NULL)
        {
            if (cabeza->dni == dni)
            {
                printf("Inscripto en el tutorial %s \n", xtutoriales[i].nom);
            }
            busqueda(xtutoriales, cabeza->sig, dni, i);
        }
        else
            busqueda(xtutoriales, xtutoriales[i + 1].ins, dni, i + 1);
    }
}

void buscarPersona(titulo xtutoriales[T])
{
    int dni;
    puts("Ingrese DNI para buscar en que tutoriales se inscribio");
    scanf("%d", &dni);
    busqueda(xtutoriales, xtutoriales[0].ins, dni, 0);
}

void mostrarLista(puntero cabeza)
{
    if (cabeza != NULL)
    {
        printf("%d  ", cabeza->dni);
        mostrarLista(cabeza->sig);
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

void liberar(titulo xtutoriales[T])
{
    for (int i = 0; i < T; i++)
    {
        liberarNodo(xtutoriales[i].ins, NULL);
    }
}

void menu()
{
    puts("CONGRESO DE INFORMATICA");
    puts("Ingrese accion a realizar:");
    puts("1) Carga de tutoriales");
    puts("2) Carga Inscriptos");
    puts("3) Eliminar Inscriptos");
    puts("4) Mostrar total de inscriptos en un tutorial");
    puts("5) Buscar inscripcion/es por DNI");
    puts("6) Mostrar tutoriales \n");
    puts("0) Finalizar el programa\n");
    printf("Opcion: ");
}

int main()
{
    titulo tutoriales[T];
    int opcion;
    do
    {
        menu();
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            cargaTutoriales(tutoriales, 0);
            break;
        case 2:
            cargaIncriptos(tutoriales);
            break;
        case 3:
            eliminarInscripto(tutoriales);
            break;
        case 4:
            total(tutoriales);
            break;
        case 5:
            buscarPersona(tutoriales);
            break;
        case 6:
            total(tutoriales);
            break;

        case 0:
            liberar(tutoriales);
            system("clear");
            puts("Ki otsu kete user-chan :)");
            sleep(3);
        default:
            puts("Opcion Incorrecta");
        }
    } while (opcion != 0);

    mostrarTutos(tutoriales, 0);

    return 0;
}