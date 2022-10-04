/*
//  Mira Faustino
//  44406373
//  21801
//  LCC
*/

/*
Ejercicio 1
Durante una conferencia se registró el nombre y edad de los asistentes.
Se pide que usando funciones para cada ítem resuelva:
Generar un arreglo dinámico para almacenar nombre y edad de las personas que asistieron a la conferencia.
Mostrar los nombres de los asistentes y la edad promedio.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct asistente
{
    char nombre[20];
    int edad;
} asistente;

void carga(asistente *&arr, int cant)
{
    char nom[20];
    puts("CARGA DE LOS ASISTENTES");
    for (int i = 0; i < cant; i++)
    {
        puts("Ingrese nombre del asistente");
        scanf("%s", arr[i].nombre);
        puts("Ingrese edad del participante");
        scanf("%d", &arr[i].edad);
        getchar();
    }
}

void mostrar(asistente *&arr, int cant)
{
    puts("\n\nNOMBRES DE LOS ASISTENTES:");
    for (int i = 0; i < cant; i++)
    {
        puts(arr[i].nombre);
    }
}

void promedio(asistente *&arr, int cant, int i, float prom)
{
    if (i < cant)
    {
        prom += arr[i].edad;
        promedio(arr, cant, i + 1, prom);
    }
    else
        printf("\n\nEDAD PROMEDIO: %f \n\n", prom / cant);
}

int main()
{
    int cant;
    asistente *array;

    puts("Ingrese cantidad de asistentes");
    scanf("%d", &cant);
    array = (asistente *)malloc(sizeof(asistente) * cant);

    carga(array, cant);
    mostrar(array, cant);
    promedio(array, cant, 0, 0);

    free(array);

    return 0;
}

/* Lote de prueba
Juan
26
Lucia
28
Ana
42
José
50
Luis
22
*/