/*
Ejercicio 9
La biblioteca de la facultad cuenta con una cantidad variable de libros de Programación Procedural en calidad de
préstamo en la sala de lectura que puede modificarse. Una vez prestados los libros, de los cuales se registra el
código, se confecciona para cada uno una lista de alumnos que están en cola de espera. Por cada alumno se guarda:
nombre y carrera (LSI, LCC)
Se pide realizar un programa, que a través de un menú de opciones y mediante el uso de funciones, de respuesta a
las siguientes situaciones:
a) Crear una lista de listas inicializadas en NULL. para almacenar la información de los libros
b) Para un código de libro solicitado, insertar un alumno a la cola de espera correspondiente. Usar una función
recursiva.
c) Ingresar un nuevo libro para que esté en calidad de préstamo en la biblioteca.
d) Suponiendo devuelto un libro cuyo código se lee, realizar un préstamo al primer alumno de la lista
correspondiente y actualizar la misma (Esto es eliminarlo de la lista)
e) Ingresar un código de libro y una carrera, mostrar los nombres de los alumnos de dicha carrera que están en cola
de espera.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_alumno
{
    char nombre[20];
    char carrera[4];
    struct nodo_alumno *sig;
} nodo_alumno;

typedef nodo_alumno *punteroAlu;

typedef struct nodo_libro
{
    int codigo;
    struct nodo_alumno *siguiente_alu;
    struct nodo_libro *siguiente_lib;
} nodo_libro;

typedef nodo_libro *punteroLib;

void inicializarLista(punteroLib &xbiblioteca)
{
    xbiblioteca->siguiente_alu = NULL;
    xbiblioteca->siguiente_lib = NULL;
}

void cargaBiblioteca(punteroLib &xbiblioteca)
{
    int cod;
    puts("Ingrese codigo del libro a almacenar(termina en 0)");
    scanf("%d", &cod);
    if (cod != 0)
    {
        punteroLib nuevo;
        nuevo = (punteroLib)malloc(sizeof(nodo_libro));
        nuevo->codigo = cod;
        nuevo->siguiente_alu = NULL;
        nuevo->siguiente_lib = xbiblioteca;
        xbiblioteca = nuevo;
        cargaBiblioteca(xbiblioteca->siguiente_lib);
    }
}

void mostrar(punteroLib cabeza)
{
    if (cabeza != NULL)
    {
        printf("%d  ", cabeza->codigo);
        mostrar(cabeza->siguiente_lib);
    }
}

int main()
{
    punteroLib biblioteca;
    inicializarLista(biblioteca);
    cargaBiblioteca(biblioteca);
    mostrar(biblioteca);
    puts("\n\n");
    return 0;
}