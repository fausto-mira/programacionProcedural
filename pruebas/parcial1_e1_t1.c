#include <stdio.h>
#define N 3

typedef struct estudiante
{
    char nombre[20];
    int edad, matRendidas;
} estudiante;

void cargaEstudiantes(estudiante xarray[N], int n)
{
    if (n < N)
    {
        printf("Ingrese nombre del estudiante n %d \n", n + 1);
        fflush(stdin);
        fgets(xarray[n].nombre, 20, stdin);
        printf("Ingrese edad del estudiante \n");
        scanf("%d", &xarray[n].edad);
        printf("Ingrese numero de materia rendidas");
        scanf("%d", &xarray[n].matRendidas);
        cargaEstudiantes(xarray, n + 1);
    }
}

void mayores21Anios(estudiante xarray[N], int n)
{
    if (n < N)
    {
        if (xarray[n].edad > 21)
            printf("Alumno %s supera edad de 21 anios, con %d mat rendidas \n", xarray[n].nombre, xarray[n].matRendidas);
        mayores21Anios(xarray, n + 1);
    }
}

int cantMateriaRendidas(estudiante xarray[N], int n, int numMat, int cantIgual, int *cantMayor)
{
    if (n < N)
    {
        if (xarray[n].matRendidas == numMat)
        {
            cantIgual++;
        }
        else if (xarray[n].matRendidas > numMat)
        {
            *cantMayor += 1;
        }
        return cantMateriaRendidas(xarray, n + 1, numMat, cantIgual, cantMayor);
    }
    else
        return cantIgual;
}

int main()
{
    estudiante array[N];
    int cantMayor = 0, cantIgual, cantMaterias;
    cargaEstudiantes(array, 0);
    mayores21Anios(array, 0);
    puts("Ingrese cantidad de materia rendidas para filtrar");
    scanf("%d", &cantMaterias);
    cantIgual = cantMateriaRendidas(array, 0, cantMaterias, 0, &cantMayor);
    printf("Cantidad igual: %d \nCantidad mayor: %d \n", cantIgual, cantMayor);
    return 0;
}