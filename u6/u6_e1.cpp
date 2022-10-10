/*
Ejercicio 1
Almacenar la información de los asistentes a unas jornadas de capacitación, de cada asistente se conoce su nombre
y edad.
Utilizando funciones óptimas realice lo siguiente:
a) Genere un archivo de acceso secuencial con la información de los asistentes a las jornadas.
b) Muestre los nombres de los asistentes mayores de 40 años.
c) Indique en el principal la edad promedio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct asistente
{
    char nombre[30];
    int edad;
} asistente;

void carga(FILE *arch)
{
    asistente datos;
    int i = 0;
    char nombre[20], ch;

    puts("Ingrese nombre del asistente ( termina con \"FIN\")");
    scanf("%[^\n]s", nombre);
    getchar();

    while (nombre[i])
    {
        nombre[i] = toupper(nombre[i]);
        i++;
    }
    i = 0;

    while (strncmp(nombre, "FIN", 4))
    {
        strcpy(datos.nombre, nombre);
        puts("Ingrese edad del asistente");
        fflush(stdin);
        scanf("%d", &datos.edad);
        getchar();
        fwrite(&datos, sizeof(datos), 1, arch);

        puts("Ingrese nombre del asistente ( termina con \"FIN\")");
        scanf("%[^\n]s", nombre);
        getchar();

        while (nombre[i])
        {
            nombre[i] = toupper(nombre[i]);
            i++;
        }
        i = 0;
    }
}

void mostrar(FILE *arch)
{
    asistente datos;
    rewind(arch);
    fread(&datos, sizeof(datos), 1, arch);
    puts("\n\nLista de assitentes: \n");
    while (!feof(arch))
    {
        printf("Nombre: %s. Edad: %d \n", datos.nombre, datos.edad);
        fread(&datos, sizeof(datos), 1, arch);
    }
}

void mayores40(FILE *arch)
{
    asistente datos;
    int n = 1;
    rewind(arch);
    fread(&datos, sizeof(datos), 1, arch);
    puts("\n\nAsistentes con mas de 40 anios\n");
    while (!feof(arch))
    {
        if (datos.edad > 40)
        {
            printf("%d) %s\n", n, datos.nombre);
            n++;
        }

        fread(&datos, sizeof(datos), 1, arch);
    }
    puts("\n\n");
}

float edadPromedio(FILE *arch)
{
    asistente datos;
    int prom = 0, cant = 0;
    rewind(arch);
    fread(&datos, sizeof(datos), 1, arch);
    while (!feof(arch))
    {
        prom += datos.edad;
        cant++;
        fread(&datos, sizeof(datos), 1, arch);
    }
    return (prom / cant);
}

int main()
{
    FILE *archivo;
    float promedio;

    archivo = fopen("jornada.txt", "w");
    if (archivo == NULL)
        printf("Error de apertura de archivo \n");
    else
    {
        carga(archivo);
        fclose(archivo);
    }

    archivo = fopen("jornada.txt", "r");
    if (archivo == NULL)
        printf("Error de apertura de archivo \n");
    else
    {
        mostrar(archivo);
        mayores40(archivo);
        promedio = edadPromedio(archivo);
        printf("Edad promedio de los asistentes: %.0f \n\n", promedio);
        fclose(archivo);
    }

    return 0;
}