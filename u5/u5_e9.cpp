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
#include <string.h>
#include <unistd.h>

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
    punteroAlu siguiente_alu;
    nodo_libro *siguiente_lib;
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

void busqueda(punteroAlu &cabeza, punteroAlu nuevo)
{
    if (cabeza == NULL)
        cabeza = nuevo;
    else
        busqueda(cabeza->sig, nuevo);
}

void insercion(punteroLib &cabeza, int cod)
{
    if (cabeza != NULL)
    {
        if (cabeza->codigo == cod)
        {
            punteroAlu nuevo;
            nuevo = (punteroAlu)malloc(sizeof(nodo_alumno));
            puts("Ingrese nombre del alumno");
            getchar();
            scanf("%[^\n]s", nuevo->nombre);
            puts("Ingrese carrera 'LCC', 'LSI' o 'TPW'");
            getchar();
            scanf("%[^\n]s", nuevo->carrera);
            nuevo->sig = NULL;
            busqueda(cabeza->siguiente_alu, nuevo);
        }
        else
            insercion(cabeza->siguiente_lib, cod);
    }
    else
        puts("Libro no encontrado");
}

void cargaAlumnos(punteroLib &cabeza)
{
    int cod;
    do
    {
        puts("Ingrese codigo de libro para agregar alumno a la cola (termina con '0')");
        scanf("%d", &cod);
        insercion(cabeza, cod);
    } while (cod != 0);
}

int eliminar(punteroLib &cabeza, int cod)
{
    if (cabeza != NULL)
    {
        if (cabeza->codigo == cod)
        {
            punteroAlu p;
            p = cabeza->siguiente_alu;
            cabeza->siguiente_alu = cabeza->siguiente_alu->sig;
            free(p);
            if (cabeza->siguiente_alu == NULL)
                puts("No hay alumnos en la cola");
            else
                printf("Alumno siguiente %s", cabeza->siguiente_alu->nombre);
            return 1;
        }
        else
            return eliminar(cabeza->siguiente_lib, cod);
    }
    else
    {
        puts("Libro no encontrado");
        return 0;
    }
}

void libroDevuelto(punteroLib &cabeza)
{
    int cod, r;
    do
    {
        puts("Ingrese codigo del libro devuelto");
        scanf("%d", &cod);
        r = eliminar(cabeza, cod);
    } while (r == 0);
}

void mostrarAluCarrera(punteroAlu cabeza, char carrera[4], int cont)
{
    if (cabeza != NULL)
    {
        if (strncmp(cabeza->carrera, carrera, strlen(carrera)) == 0)
        {
            printf("Nombre: %s \n", cabeza->nombre);
            cont += 1;
        }
        mostrarAluCarrera(cabeza->sig, carrera, cont);
    }
    else if (cont == 0)
        printf("No hay alumnos carrera %s en la cola \n", carrera);
}

int busquedaCod(punteroLib cabeza, int cod, char carrera[4])
{
    if (cabeza != NULL)
    {
        if (cabeza->codigo == cod)
        {
            printf("Cola libro codigo %d \n", cod);
            mostrarAluCarrera(cabeza->siguiente_alu, carrera, 0);
            return 1;
        }
        else
            return busquedaCod(cabeza->siguiente_lib, cod, carrera);
    }
    else
    {
        puts("Libro no encontrado");
        return 0;
    }
}

void busquedaPorLibroYCarrera(punteroLib cabeza)
{
    int cod, r;
    char carrera[4];
    do
    {

        puts("Ingrese codigo de libro y carrera a buscar");
        scanf("%d", &cod);
        getchar();
        scanf("%[^\n]s", carrera);
        if (strncmp(carrera, "LCC", strlen("LCC")) == 0 ||
            strncmp(carrera, "LSI", strlen("LSI")) == 0 ||
            strncmp(carrera, "TPW", strlen("TPW")) == 0)
        {
            r = busquedaCod(cabeza, cod, carrera);
        }
        else
        {
            puts("Carrera ingresada no existe");
            r = 0;
        }
    } while (r == 0);
}

void mostrarAlu(punteroAlu cabeza, int cont)
{
    if (cabeza != NULL)
    {
        printf("Nombre: %s. Carrera: %s\n", cabeza->nombre, cabeza->carrera);
        cont += 1;
        mostrarAlu(cabeza->sig, cont);
    }
    else if (cont == 0)
    {
        puts("*No hay alumnos en la cola*");
    }
}

void mostrarLib(punteroLib cabeza)
{
    if (cabeza->siguiente_lib != NULL)
    {
        printf("Libro codigo %d\n", cabeza->codigo);
        mostrarAlu(cabeza->siguiente_alu, 0);
        printf("\n");
        mostrarLib(cabeza->siguiente_lib);
    }
}

void liberarAlu(punteroAlu &cabeza, punteroAlu q)
{
    if (cabeza != NULL)
    {
        q = cabeza;
        cabeza = cabeza->sig;
        free(q);
        liberarAlu(cabeza, NULL);
    }
}

void liberarLib(punteroLib &cabeza, punteroLib p)
{
    if (cabeza->siguiente_lib != NULL)
    {
        liberarAlu(cabeza->siguiente_alu, NULL);
        p = cabeza;
        cabeza = cabeza->siguiente_lib;
        free(p);
        liberarLib(cabeza, NULL);
    }
}

void menu()
{
    puts("BIBLIOTECA INFORMATICA\n");
    puts("Opciones:");
    puts("1) Carga de libro/s");
    puts("2) Insertar alumno cola libro");
    puts("3) Devolucion de libro");
    puts("4) Mostrar cola para un libro y una carrera");
    puts("5) Mostrar por cada libro, la cola de estudiantes en cada uno");
    puts("0) Cerrar programa\n");
    printf("Opcion: ");
}

void seleccionOpcion(int opcion, punteroLib &xbiblioteca)
{
    switch (opcion)
    {
    case 1:
        cargaBiblioteca(xbiblioteca);
        system("clear");
        break;
    case 2:
        cargaAlumnos(xbiblioteca);
        system("clear");
        break;
    case 3:
        libroDevuelto(xbiblioteca);
        system("clear");
        break;
    case 4:
        busquedaPorLibroYCarrera(xbiblioteca);
        system("clear");
        break;
    case 5:
        mostrarLib(xbiblioteca);
        sleep(10);
        system("clear");
        break;
    case 0:
        liberarLib(xbiblioteca, NULL);
        break;
    default:
        puts("\n*Opcion invalida*\n");
    }
}

int main()
{
    punteroLib biblioteca;
    inicializarLista(biblioteca);
    int opcion;
    do
    {
        menu();
        scanf("%d", &opcion);
        puts("");
        seleccionOpcion(opcion, biblioteca);
    } while (opcion != 0);

    return 0;
}