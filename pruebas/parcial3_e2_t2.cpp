#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[30];

typedef struct pelicula
{
    int cod, cant;
    string titulo, director;
} pelicula;

typedef struct nodo
{
    int cod;
    string titulo;
    nodo *sig;
} nodo;

typedef nodo *puntero;

void agregarNuevaPelicula(FILE *arch)
{
    pelicula p;
    fseek(arch, sizeof(p) * (-1), SEEK_END);
    fread(&p, sizeof(p), 1, arch);
    puts("Ingrese titulo, director, cant espectadores");
    scanf("%s", p.titulo);
    scanf("%s", p.director);
    scanf("%d", &p.cant);
    p.cod += 1;
    fwrite(&p, sizeof(p), 1, arch);
}

void copiarArchivoALista(puntero &cabeza, FILE *arch)
{
    pelicula p;
    puntero nuevo;
    rewind(arch);

    while (fread(&p, sizeof(p), 1, arch))
    {
        if (p.cant < 100)
        {
            nuevo = (nodo *)malloc(sizeof(nodo));
            nuevo->cod = p.cod;
            strcpy(nuevo->titulo, p.titulo);
            nuevo->sig = cabeza;
            cabeza = nuevo;
        }
    }
}

void eliminarNodo(puntero cabeza, string titulo, puntero aux)
{
    if (cabeza != NULL)
    {
        if (strcmp(cabeza->sig->titulo, titulo) == 0)
        {
            aux = cabeza->sig;
            cabeza->sig = cabeza->sig->sig;
            free(aux);
        }
    }
}

void eliminarDeLaLista(puntero &cabeza)
{
    string tit;
    puntero aux;
    puts("Ingrese titulo a eliminar");
    scanf("%s", tit);
    if (strcmp(cabeza->titulo, tit) == 0)
    {
        aux = cabeza;
        cabeza = cabeza->sig;
        free(aux);
    }
    else
        eliminarNodo(cabeza, tit, aux);
}

void nuevoArchivo(puntero &cabeza, FILE *nuevo)
{
    if (cabeza != NULL)
    {
        fwrite(&cabeza, sizeof(nodo), 1, nuevo);
        nuevoArchivo(cabeza->sig, nuevo);
        free(cabeza);
    }
}

int main()
{
    FILE *archivo1, *archivo2;
    puntero cabeza = NULL;
    fopen("TITULOS.DAT", "r+");
    if (archivo1 == NULL)
    {
        puts("Error al abrir");
        return -1;
    }
    else
    {
        agregarNuevaPelicula(archivo1);
        copiarArchivoALista(cabeza, archivo1);
        eliminarDeLaLista(cabeza);

        archivo2 = fopen("TITULOS2.DAT", "w");
        if (archivo2 == NULL)
            puts("Error al intentar abrir el archivo");
        else
        {
            nuevoArchivo(cabeza, archivo2);
            fclose(archivo2);
        }
        fclose(archivo1);
    }

    return 0;
}