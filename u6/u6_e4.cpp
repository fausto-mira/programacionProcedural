/*
Ejercicio 4
Una biblioteca procesa diariamente el archivo, “TITULOS.DAT”. Este archivo almacena la información para cada libro:
Código (de 1 a 500), Título, Autor y Cantidad de ejemplares disponibles. El archivo está ordenado en forma
secuencial por código a partir de 1.
Se pide realizar un programa óptimo que a través del uso de funciones genere un menú de opciones que responda a
las siguientes solicitudes:
a) Dado el código de un libro, mostrar el título y la cantidad de ejemplares disponibles.
b) Dado el título de un libro, mostrar el autor.
c) Dado un Autor, mostrar todos los libros de su autoría registrados.
d) Agregar un nuevo libro al archivo.
*/

#include <stdio.h>

typedef char cadena[30];

typedef struct libro
{
    cadena titulo, autor;
    int cant;
} libro;

int main()
{
    FILE *archivo;

    return 0;
}