/*Ejercicio 5
Construir un programa en lenguaje C que a través de funciones recursivas resuelva los siguientes ítems:
a) Cargar un arreglo de enteros, de N componentes.
b) Generar un subarreglo con las componentes del arreglo cargado, cuyo valor es mayor o igual al Promedio.
c) Indicar cuantas componentes del subarreglo son mayores al promedio y cuantas iguales a éste.
d) Ingresar un número y decir si se encuentra en el subarreglo.
e) Realice el ítem anterior si el arreglo original estuviera ordenado ascendentemente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N;

void carga(int xarre[], int n)
{
    if (n)
    {
        xarre[n - 1] = rand() % 10;
        carga(xarre, n - 1);
    }
}

void mostrar(int xarre[], int n, int cota)
{
    if (n < cota)
    {
        printf("%d\n", xarre[n]);
        mostrar(xarre, n + 1, cota);
    }
}

float promedio(int xarre[], int n, int xresult)
{
    if (n)
    {
        xresult += xarre[n - 1];
        xresult = promedio(xarre, n - 1, xresult);
    }
    return xresult;
}

int cargaSubarreglo(int xarre[], int xarre2[], int n, int m, float xprom)
{
    if (n < N)
    {
        if (xarre[n] >= xprom)
        {
            xarre2[m] = xarre[n];
            m += 1;
        }
        return cargaSubarreglo(xarre, xarre2, n + 1, m, xprom);
    }
    return (m);
}

// Indicar cuantas componentes del subarreglo son mayores al promedio y cuantas iguales a éste.

void mayoresProm(int xarre2[], int n, int cota, int &mayores, int &iguales, int xprom)
{
    if (n < cota)
    {
        if (xarre2[n] > xprom)
            mayores += 1;
        if (xarre2[n] == xprom)
            iguales += 1;
        mayoresProm(xarre2, n + 1, cota, mayores, iguales, xprom);
    }
}

// Ingresar un número y decir si se encuentra en el subarreglo

int busqueda(int xarre2[], int n, int num, int resultado)
{
    if (n && resultado == 0)
    {
        if (xarre2[n - 1] == num)
            resultado = 1;
        return busqueda(xarre2, n - 1, num, resultado);
    }
    return resultado;
}

int main()
{
    srand(time(NULL));

    printf("Ingrese tamaño del arreglo \n N: ");
    scanf("%d", &N);
    int arre[N], arre2[N], cota, mayores, iguales, numero, resultadoBusqueda;
    float resultado;

    carga(arre, N);
    mostrar(arre, 0, N);
    resultado = promedio(arre, N, resultado) / N;
    printf("\nResultado: %.2f\n", resultado);

    cota = cargaSubarreglo(arre, arre2, 0, 0, resultado);
    // printf("\nArreglo de numeros que superan el promedio \n");
    mostrar(arre2, 0, cota);

    mayoresProm(arre2, 0, cota, mayores, iguales, resultado);
    printf("Mayores al prom: %d. Iguales al promedio %d\n\n", mayores, iguales);

    printf("Ingrese un numero a buscar: ");
    scanf("%d", &numero);
    resultadoBusqueda = busqueda(arre, N, numero, 0);
    if (resultadoBusqueda != 0)
        printf("\nEL numero ha sido encontrado\n");
    else
        printf("\nEl numero no se encontro\n");

    printf("Ingrese un numero a buscar: ");
    scanf("%d", &numero);
    resultadoBusqueda = busqueda(arre, N, numero, 0);
    if (resultadoBusqueda != 0)
        printf("\nEL numero ha sido encontrado\n");
    else
        printf("\nEl numero no se encontro\n");
    return 0;
}