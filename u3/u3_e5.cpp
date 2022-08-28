/*Ejercicio 5
En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa un área
temática. En cada sala se dictarán 4 conferencias en distintos turnos. Para procesar la información, en un primer
momento y por única vez se ingresa el nombre de cada una de las 6 áreas temáticas que se tratarán en el congreso y
el cupo de personas para la sala donde se dictará la misma. Por cada interesado se ingresa su nombre, nombre del
área temática, y número correspondiente a la conferencia a la que quiere asistir. La inscripción se realiza previa
verificación del cupo de la sala. A partir de la información ingresada generar una tabla que permita responder los
siguientes ítems:
a) Decir para cada área temática qué conferencia tuvo menos asistentes y cuál la mayor cantidad
    (Suponer el mayor y el menor como valores únicos).
b) Indicar el nombre del área temática con menos inscriptos.
c) Dado un nombre de área temática decir cuál fue el promedio de inscriptos.
d) Indicar la/s áreas temáticas que en algún turno tuvieron la sala completa, si las hubiera*/

#include <stdio.h>
#include <string.h>
#define M 6
#define N 4

typedef struct congreso
{
    char nombre[20];
    int cupo;
} congreso;

void inicializar(congreso xsalas[M], int xtabla[M][N])
{
    char areaTematica[20];
    for (int i = 0; i < M; i++)
    {
        puts("Ingrese nombre del area tematica");
        scanf("%s", areaTematica);
        strcpy(xsalas[i].nombre, areaTematica);
        printf("Inrgese cupo del area %s: \n", areaTematica, i + 1);
        scanf("%d", &xsalas[i].cupo);

        for (int j = 0; j < N; j++)
        {
            xtabla[i][j] = 0;
        }
    }
    return;
}

int busqueda(congreso xsalas[M], char xarea[20])
{
    int bandera = -1;

    for (int i = 0; i < M; i++)
    {
        if (strcmp(xsalas[i].nombre, xarea) == 0)
            bandera = i;
    }
    return (bandera);
}

void carga(congreso xsalas[M], int xtabla[M][N])
{
    int resultado, turno;
    char nombre[20], areaTematica[20];
    puts("Ingrese nombre su nombre");
    scanf("%s", nombre);
    printf("Buenas tardes %s! \n", nombre);
    puts("Ingrese nombre del area tematica (termina con 'FIN')");
    scanf("%d", areaTematica);

    while (strcmp(areaTematica, "FIN") != 0)
    {
        resultado = busqueda(xsalas, areaTematica);
        if (resultado != -1)
        {
            puts("Ingrese el turno deseado");
            scanf("%d", turno);
            if (xsalas[resultado].cupo > 0)
            {
                xsalas[resultado].cupo--;
                xtabla[resultado][turno - 1]++;
            }
            else
                puts("Este turno tiene el cupo lleno");
        }
        else
            puts("No se encontro el area tematica ingresada");
    }
    return;
}

// Decir para cada área temática qué conferencia tuvo menos asistentes y cuál la mayor cantidad
// (Suponer el mayor y el menor como valores únicos).

void menosAsistentes(congreso xsalas[M], int xtabla[M][N])
{
    for (int i = 0; i < M; i++)
    {
        int menor = 9999, mayor = 0, posMayor = 0, posMenor = 0;
        for (int j = 0; j < N; j++)
        {
            if (xtabla[i][j] > mayor)
            {
                mayor = xtabla[i][j];
                posMayor = j;
            }
            if (xtabla[i][j] < menor)
            {
                menor = xtabla[i][j];
                posMenor = j;
            }
        }
        printf("Area tematica %s \n", xsalas[i].nombre);
        printf(" Conferencia con mayor cantidad de asistentes: %d \n", posMayor + 1);
        printf(" Conferencia con manor cantidad de asistentes: %d \n", posMenor + 1);
    }
    return;
}

// Indicar el nombre del área temática con menos inscriptos.

void menosInscriptos(congreso xsalas[M], int xtabla[M][N])
{
    int menor = 9999, pos = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (xtabla[i][j] < menor)
            {
                menor = xtabla[i][j];
                pos = i;
            }
        }
    }
    printf("EL area tematica con la menor cantidad de insciptos es la %d", pos + 1);
    return;
}

// Dado un nombre de área temática decir cuál fue el promedio de inscriptos.

void promedioIncriptos(congreso xsalas[M], int xtabla[M][N])
{
    int resultado, acumulador = 0;
    char nombre[20];
    puts("Ingrese el nombre del area para calcular el promedio");
    scanf("%s", nombre);

    resultado = busqueda(xsalas, nombre);

    if (resultado != -1)
    {
        for (int i = 0; i < N; i++)
            acumulador += xtabla[resultado][i];

        printf("El promedio de inscriptos del area %s es: %d \n", nombre, acumulador / N);
    }
    else
        puts("El area no se encontro");

    return;
}

// Indicar la/s áreas temáticas que en algún turno tuvieron la sala completa, si las hubiera

void salaCompleta(congreso xsalas[M])
{
    for (int i = 0; i < M; i++)
    {
        if (xsalas[i].cupo == 0)
            printf("El area %s quedo completa", xsalas[i].nombre);
    }
    return;
}

int main()
{
    congreso salas[M];
    int tabla[M][N];

    inicializar(salas, tabla);
    carga(salas, tabla);
    menosAsistentes(salas, tabla);
    menosInscriptos(salas, tabla);
    promedioIncriptos(salas, tabla);
    salaCompleta(salas);
    return 0;
}