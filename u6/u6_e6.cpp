/*
Ejercicio 6
Una sala de cines procesa diariamente el archivo “TITULOS.DAT”. Este archivo almacena la información de cada
película proyectada: Código de la película, Título, Director y Cantidad de personas que la vieron. El archivo está
ordenado en forma secuencial por código a partir del numero 1.
Se pide realizar un programa óptimo que a través del uso de funciones genere un menú de opciones que responda a
las siguientes solicitudes:
a) Listar por cada película el título y la cantidad de personas que la vieron.
b) Dado el código de una película, mostrar el título y el director.
c) Ingresar un titulo por teclado y mostrar el código y director.
d) Genere un nuevo archivo con la información de las películas que fueron vistas por más de 1000 personas.
e) Dado un código de película, modificar la cantidad de personas que la vieron.
*/

#include <stdio.h>
#include <string.h>

typedef char string[30];

typedef struct pelicula
{
    string titulo, director;
    int cod, cant;
} pelicula;

void cargaPeliculas(FILE *arch)
{
    pelicula p;
    string tit;
    int cod = 1;
    puts("Ingrese titulo de la pelicula(termina con 'FIN')");
    getchar();
    scanf("%[^\n]s", tit);
    while (strncmp(tit, "FIN", 3))
    {
        strcpy(p.titulo, tit);
        puts("Ingrese director de la pelicula");
        getchar();
        scanf("%[^\n]s", p.director);
        puts("Ingrese cantidad de personas que vieron la pelicula");
        scanf("%d", &p.cant);
        p.cod = cod;
        cod++;
        fwrite(&p, sizeof(p), 1, arch);
        puts("Ingrese titulo de la pelicula(termina con 'FIN')");
        getchar();
        scanf("%[^\n]s", tit);
    }
}

void listar(FILE *arch)
{
    pelicula p;
    rewind(arch);
    while (fread(&p, sizeof(p), 1, arch))
        printf("Titulo: %s. Cant personas que la vieron: %d\n", p.titulo, p.cant);
}

void buscarPorCodigo(FILE *arch)
{
    pelicula p;
    int pos;
    puts("Ingrese codigo de la pelicula a buscar");
    scanf("%d", &pos);
    fseek(arch, (pos - 1) * sizeof(p), SEEK_SET);
    fread(&p, sizeof(p), 1, arch);
    printf("Titulo: %s. Director: %s\n", p.titulo, p.director);
}

void buscarPorTitulo(FILE *arch)
{
    pelicula p;
    string tit;
    rewind(arch);
    puts("Ingrese titulo a buscar");
    getchar();
    scanf("%[^\n]s", tit);
    while (fread(&p, sizeof(p), 1, arch))
    {
        if (strcmp(p.titulo, tit))
            printf("Cod: %d. Director: %s", p.cod, p.director);
    }
}

void copiar1000(FILE *arch1, FILE *arch2)
{
    pelicula p;
    rewind(arch1);
    arch2 = fopen("AUXILIAR_TITULOS.dat", "a+");
    if (arch2 == NULL)
        puts("Error al abrir le archivo auxiliar");
    else
    {
        while (fread(&p, sizeof(p), 1, arch1))
        {
            if (p.cant > 1000)
                fwrite(&p, sizeof(p), 1, arch2);
        }
    }
    fclose(arch2);
}

void modificarPorCodigo(FILE *arch)
{
    pelicula p;
    int cod, cant;
    puts("Ingrese codigo de la pelicula para modificar cant de personas que la vieron");
    scanf("%d", &cod);
    fseek(arch, (cod - 1) * sizeof(p), SEEK_SET);
    fread(&p, sizeof(p), 1, arch);
    printf("Personas que la vieron antes de modificar: %d\nIngrese nuevo valor:", p.cant);
    scanf("%d", &cant);
    p.cant = cant;
    fclose(arch);
    arch = fopen("TITULOS.dat", "r+");
    fseek(arch, (cod - 1) * sizeof(p), SEEK_SET);
    // fseek(arch, (-1) * sizeof(p), SEEK_CUR);
    fwrite(&p, sizeof(p), 1, arch);
}

void menu()
{
    puts("1 Carga");
    puts("2 Listar");
    puts("3 Buscar por codigo");
    puts("4 Buscar por titulo");
    puts("5 Generar nuevo archivo con vistas > 1000");
    puts("6 Modificar vistas por codigo");
    puts("0 Cerrar programa");
}

void seleccion(int &opcion, FILE *arch, FILE *arch2)
{
    switch (opcion)
    {
    case 1:
        cargaPeliculas(arch);
        break;
    case 2:
        listar(arch);
        break;
    case 3:
        buscarPorCodigo(arch);
        break;
    case 4:
        buscarPorTitulo(arch);
        break;
    case 5:
        copiar1000(arch, arch2);
        break;
    case 6:
        modificarPorCodigo(arch);
        break;
    case 7:
        opcion = 0;
        break;
    default:
        puts("Opcion ingresada incorrecta");
        break;
    }
}

int main()
{
    FILE *archivo1, *archivo2;
    int cod;

    archivo1 = fopen("TITULOS.dat", "a+");
    if (archivo1 == NULL)
    {
        puts("Error al intentar abrir el archivo");
        return 1;
    }
    else
    {
        puts("Archivo abierto correctamente");
        do
        {
            menu();
            scanf("%d", &cod);
            seleccion(cod, archivo1, archivo2);
        } while (cod);
    }

    fclose(archivo1);

    return 0;
}
