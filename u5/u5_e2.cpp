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
    int peso;

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
        scanf("%d", &arr[n].peso);
        printf("\n\n");
        cargaBoxeadores(arr, N, n + 1, cate);
    }
}

// Para una categoría determinada, mostrar los DNI de los boxeadores que tienen el peso máximo. Generar una
// estructura auxiliar.

/*int buscarMaximo(boxeador *&arr, int N)
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
} */

int contadorMaximo(boxeador *&arr, int N)
{
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].peso == 90)
            ++cont;
    }
    return cont;
}

int pesoMaximo(boxeador *&arr, int N, boxeador *&subArr, char cate)
{
    int cantMax = contadorMaximo(arr, N), cont = 0;
    subArr = (boxeador *)malloc(sizeof(boxeador) * cantMax);
    for (int i = 0; i < N; i++)
    {
        if (arr[i].peso == 90)
        {
            subArr[cont] = arr[i];
            cont++;
        }
    }
    return cont;
}

void inicializarPesos(int xpesos[43])
{
    for (int i = 0; i < 43; i++)
        xpesos[i] = 0;
}

void contadorPorPeso(boxeador *&arr, int N, int xpesos[43])
{
    for (int i = 0; i < N; i++)
        xpesos[arr[i].peso - 47] += 1;
}

void mostrarPorPeso(int xpesos[43])
{
    puts("CANTIDAD DE INSCRIPTOS POR PESO");
    for (int i = 0; i < 43; i++)
        printf("Cantidad en peso %d: %d\n", i + 47, xpesos[i]);
}

int main()
{
    int cantParticipantes, cantParticipantesSubArray, pesos[43];
    char cate;
    boxeador *array, *subArray;
    puts("Ingrese cantidad de participantes");
    scanf("%d", &cantParticipantes);
    array = (boxeador *)malloc(sizeof(boxeador) * cantParticipantes);

    cargaBoxeadores(array, cantParticipantes, 0, 'x');

    puts("Ingrese categoria para buscar cantidad de peso maximo");
    scanf("%c", &cate);
    cantParticipantesSubArray = pesoMaximo(array, cantParticipantes, subArray, cate);

    inicializarPesos(pesos);
    contadorPorPeso(array, cantParticipantes, pesos);
    mostrarPorPeso(pesos);

    return 0;
}