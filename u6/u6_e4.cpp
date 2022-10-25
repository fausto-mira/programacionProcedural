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
#include <string.h>
#define N 500

typedef char cadena[30];

typedef struct libro
{
    cadena titulo, autor;
    int cant, cod;
} libro;

void carga(FILE *arch)
{
    libro p;
    fpos_t x;
    int cod;
    for (int i = 0; i < N; i++)
    {
        fseek(arch, 0, SEEK_END);
        fgetpos(arch, &x);
        cod = (int)(x / sizeof(libro)) + N;
        p.cod = cod;
        printf("Libro codigo: %d \n", p.cod);
        puts("Ingrese titulo de libro");
        scanf("[^\n]s", &p.titulo);
        puts("Ingrese autor de libro");
        scanf("[^\n]s", &p.autor);
        puts("Ingrese cantidad de ejemplares");
        scanf("%d", &p.cant);
        fwrite(&p, sizeof(p), 1, arch);
    }
}

// Dado el código de un libro, mostrar el título y la cantidad de ejemplares disponibles.

void busquedaPorCodigo(FILE *arch)
{
    libro p;
    int pos;
    puts("Ingrese codigo a buscar");
    scanf("%d", &pos);
    rewind(arch);
    fseek(arch, pos * sizeof(libro), SEEK_SET);
    fread(&p, sizeof(p), 1, arch);
    printf("Titulo: %s. Cantidad de ejemplares: %d \n", p.titulo, p.cant);
}

// Dado el título de un libro, mostrar el autor.

void buscarPorTitulo(FILE *arch)
{
    libro p;
    cadena titulo;
    puts("Ingrese titulo del libro a buscar");
    scanf("[^\n]s", &titulo);

    rewind(arch);
    while (fread(&p, sizeof(p), 1, arch))
    {
        if (!strncmp(p.titulo, titulo, strlen(titulo)))
        {
            printf("Autor del libro: %s \n", p.autor);
            return;
        }
    }
    puts("Titulo del libro ingresado no existe");
}

// Dado un Autor, mostrar todos los libros de su autoría registrados.

void buscarLibrosDeAutor(FILE *arch)
{
    libro p;
    cadena autor;
    puts("Ingrese autor para buscar sus libros");
    scanf("[^\n]s", &autor);

    rewind(arch);
    while (fread(&p, sizeof(p), 1, arch))
    {
        if (!strncmp(p.autor, autor, strlen(autor)))
        {
            printf("%s \n", p.autor);
            return;
        }
    }
    puts("Autor ingresado no existe");
}

// Agregar un nuevo libro al archivo.

void cargarUnLibro(FILE *arch)
{
    libro p;
    int pos;
    puts("Ingrese porsicion a reemplazar");
    scanf("%d", &pos);
    fseek(arch, pos * sizeof(libro), SEEK_SET);

    printf("Libro codigo: %d \n", p.cod);
    puts("Ingrese titulo de libro");
    scanf("[^\n]s", &p.titulo);
    puts("Ingrese autor de libro");
    scanf("[^\n]s", &p.autor);
    puts("Ingrese cantidad de ejemplares");
    scanf("%d", &p.cant);
    fwrite(&p, sizeof(p), 1, arch);
}

void menu()
{
    puts("BIBLIOTECA 'LA RE CONCHA DE TU MADRE'\n");
    puts("1) Carga secuencial de la biblioteca");
    puts("2) Buscar por codigo de libro");
    puts("3) Buscar por titulo");
    puts("4) Buscar libros por autor");
    puts("5) Agregar un nuevo libro");
    puts("6) Cerrar programa");
}

int seleccion(int opcion, FILE *arch)
{
    switch (opcion)
    {
    case 1:
        carga(arch);
        break;
    case 2:
        busquedaPorCodigo(arch);
        break;
    case 3:
        buscarPorTitulo(arch);
        break;
    case 4:
        buscarLibrosDeAutor(arch);
        break;
    case 5:
        cargarUnLibro(arch);
        break;
    case 6:
        return 0;
    default:
        puts("Opcion ingresada incorrecta");
    }
    return 1;
}

void abrirArchivo(FILE *arch)
{
    arch = fopen("biblioteca.dat", "a+");
    if (arch == NULL)
        puts("Error al intentar abrir el archivo 'operaciones.dat'");
}

int main()
{
    FILE *archivo;
    int a;

    abrirArchivo(archivo);

    do
    {
        menu();
        scanf("%d", &a);
        a = seleccion(a, archivo);
    } while (a != 0);

    fclose(archivo);

    return 0;
}