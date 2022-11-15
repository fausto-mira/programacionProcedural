/*
Ejercicio 5
La UNSJ tiene almacenada en el archivo “CarreUni.Dat” información de todas las carreras y de los alumnos que se
inscribieron en los últimos 10 ciclos lectivos. Por cada carrera se ingresa: código de carrera , nombre de la carrera,
cantidad de años de cursado (3..6) y un arreglo con los 4 totales de inscriptos correspondientes a los ciclos lectivos
2018 a 2021. El archivo está ordenado en forma secuencial por código de carrera a partir de 1.
Construir un programa que a través del uso adecuado de funciones y un manejo eficiente de archivos permita:
a) Ingresar un código de carrera e indicar: nombre de la carrera y ciclo lectivo con mayor cantidad de inscriptos.
b) Modificar la cantidad de algún/os de los 4 totales de inscriptos correspondientes a los ciclos lectivos 2018 a
2021 para un código de carrera ingresado por teclado.
c) Para el ciclo lectivo 2020 indicar en qué carrera/s se registró la mayor cantidad de inscriptos.
d) Por cada facultad, mostrar un listado con el nombre de cada carrera, cantidad de años de cursado y total de
inscriptos (suma de todos los ciclos lectivos). El listado debe estar ordenado ascendentemente por total de
inscriptos.
*/

#include <stdio.h>
#define N 4

typedef char cadena[30];

typedef struct carrera
{
    int cod, cantAños, cantIns[N];
    cadena nombre;
} carrera;

void carga(FILE *arch)
{
}

int main()
{
    FILE *archivo;

    archivo = fopen("CarreUni.dat", "a+");
    if (archivo == NULL)
        puts("Error al intentar abrir el archivo");
    else
    {
        carga(archivo);
    }

    return 0;
}