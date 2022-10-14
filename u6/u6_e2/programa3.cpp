/*
Ejercicio 2

Programa 3:
Codificar una función que permita mostrar Número de Registro y Nombre de alumnos que aprobaron ambas
materias.
*/

#include <stdio.h>

typedef char cadena[30];

typedef struct alumno
{
    cadena nombre;
    int reg;
    char resultado;
} alumno;

int buscar(alumno dato, FILE *arch)
{
    alumno dato2;
    rewind(arch);
    fread(&dato2, sizeof(alumno), 1, arch);
    while (!feof(arch))
    {
        if (dato.reg == dato2.reg && dato.resultado == 'A' && dato2.resultado == 'A')
            return 1;
        else
            fread(&dato2, sizeof(alumno), 1, arch);
    }
    return 0;
}

void comparar(FILE *arch1, FILE *arch2)
{
    arch1 = fopen("alumnoPP.dat", "r");
    arch2 = fopen("alumnoAL.dat", "r");
    alumno progProcedural;
    alumno algLineal;

    if (arch1 == NULL)
    {
        puts("Error al intentar abrir el archivo 'alumnoPP.dat'");
    }
    else if (arch2 == NULL)
        puts("Error al intentar abrir el archivo 'alumnoPP.dat'");
    else
    {
        puts("Alumnos que aprobaron ambas materias");
        fread(&progProcedural, sizeof(alumno), 1, arch1);
        while (!feof(arch1))
        {
            if (buscar(progProcedural, arch2))
                printf("Registro: %d. Nombre: %s", progProcedural.reg, progProcedural.nombre);
            fread(&progProcedural, sizeof(alumno), 1, arch1);
        }
    }
}

int main()
{
    FILE *archivo1;
    FILE *archivo2;

    comparar(archivo1, archivo2);

    return 0;
}