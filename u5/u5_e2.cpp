/*Ejercicio 2
La Federación Argentina de boxeo (FAB) mantiene información de los boxeadores federados: DNI, categoría y el peso
(47..90) en kilogramos. Las categorías están codificadas por letras: ‘A’: Peso crucero, …., ‘ H’: Peso minimosca. La
cantidad de participantes se ingresa por teclado.
Escribir un programa en C que permita:
a) Cargar los datos en una estructura adecuada. (Validar el ingreso, suponiendo que código de categoría varía entre
‘A’ y ‘H‘)
b) Para una categoría determinada, mostrar los DNI de los boxeadores que tienen el peso máximo. Generar una
estructura auxiliar.
c) Realizar un listado que muestre, para cada Peso cuantos participantes existen. Generar una estructura auxiliar. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct boxeador
{
    long int dni;
    char categoria;
    float peso;

} boxeador;

char validarCategoria()
{
    char cate;
    int resultado = 0;
    while (resultado == 0)
    {
        printf("Ingrese categoria \n");
        scanf("%c", &cate);
        cate = toupper(cate);
        if (cate >= 'A' || cate <= 'H')
            resultado = 1;
        else
            puts("Categoria incorrecta");
    }
    return cate;
}

void cargaBoxeadores(boxeador *&arr, int N, int n, char cate)
{
    if (n < N)
    {
        cate = validarCategoria();
        arr[n].categoria = cate;
        puts("Ingrese DNI del boxeador");
        scanf("%ld", &arr[n].dni);
        puts("Ingrese peso del boxeador (47-90)");
        scanf("%f", &arr[n].peso);
        printf("\n\n");
        cargaBoxeadores(arr, N, n + 1, cate);
    }
}

// Para una categoría determinada, mostrar los DNI de los boxeadores que tienen el peso máximo. Generar una
// estructura auxiliar.

int buscarMaximo(boxeador *&arr, int N)
{
    float max = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].peso > max)
        {
            max = arr[i].peso;
        }
    }
    return max;
}

int contadorMaximo(boxeador *&arr, int N, float max)
{
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].peso == max)
            ++cont;
    }
    return cont;
}

void pesoMaximo(boxeador *&arr, int N, boxeador *&arrPeso, char cate)
{
    float maximo = buscarMaximo(arr, N);
    int cont = contadorMaximo(arr, N, maximo), j = 0;

    arrPeso = (boxeador *)malloc(sizeof(boxeador) * cont);

    for (int i = 0; i < N; i++)
    {
        if (arr[i].peso == maximo && arr[i].categoria == cate)
            arrPeso[j] = arr[i];
    }
}

int main()
{
    int cantParticipantes;
    boxeador *array;
    puts("Ingrese cantidad de participantes");
    scanf("%d", &cantParticipantes);
    array = (boxeador *)malloc(sizeof(boxeador) * cantParticipantes);

    return 0;
}