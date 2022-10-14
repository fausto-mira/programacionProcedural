/*
Ejercicio 2

Programa 1:
a) Generar un archivo alumnosPP.dat que contiene la siguiente información correspondiente a los alumnos que
cursan la materia Programación Procedural: Nombre, Numero de Registro y Resultado de un parcial (‘A’:
Aprobado – ‘R’: Reprobado). La información se ingresa ordenada por Número de Registro.
b) Codificar una función que permita mostrar la información de cada uno de los alumnos.
*/

#include <stdio.h>

typedef char cadena[30];

typedef struct alumno
{
    cadena nombre;
    int reg;
    char resultado;
} alumno;

void carga(FILE *arch)
{
    arch = fopen("alumnoPP.dat", "w");
    alumno alu;
    int numReg;

    if (arch == NULL)
        puts("Error al intentar abrir el archivo");
    else
    {

        puts("Ingrese numero de registro (termina con numero de registro '0')");
        scanf("%d", &numReg);
        getchar();
        while (numReg)
        {
            alu.reg = numReg;
            puts("Ingrese nombre del alumno");
            fflush(stdin);
            fgets(alu.nombre, 30, stdin);
            puts("Ingrese resultado del parcial (‘A’:Aprobado .‘R’: Reprobado)");
            scanf("%c", &alu.resultado);
            getchar();
            fwrite(&alu, sizeof(alu), 1, arch);
            puts("Ingrese numero de registro (termina con numero de registro '0')");
            scanf("%d", &numReg);
            getchar();
        }
        fclose(arch);
    }
}

void mostrar(FILE *arch)
{
    arch = fopen("alumnoPP.dat", "r");
    alumno datos;
    rewind(arch);
    if (arch == NULL)
        puts("Error al intentar abrir el archivo");
    else
    {
        fread(&datos, sizeof(datos), 1, arch);
        puts("\n\nLista de alumnos Programacion Procedural: \n");
        while (!feof(arch))
        {
            printf("Numero de registro: %d. Nombre: %s. Resultado: %c \n", datos.reg, datos.nombre, datos.resultado);
            fread(&datos, sizeof(datos), 1, arch);
        }
    }
}

int main()
{
    FILE *archivo;

    carga(archivo);
    mostrar(archivo);

    return 0;
}