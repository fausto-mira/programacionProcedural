/*Ejercicio 1
Escribir un programa en lenguaje C que usando funciones permita:

    a) Crear y cargar 2 arreglos dinámicos de componentes enteras, ingresar por teclado la dimensión de cada uno de
ellos (no deben ser del mismo tamaño).

    b) Calcular el producto escalar.

    c) Generar una nueva estructura con los valores impares contenidos en uno de los arreglos (realizar un
subprograma que solicite memoria para la nueva estructura y la devuelva cargada).

    d) Realizar el mapa de memoria con el siguiente lote de prueba, específicamente al momento de la carga de un
vector, creación y carga de la nueva estructura.

    Arreglo A={1, 2, 3}
    Arreglo B={4, 5, 6},

Nota
El producto escalar es una operación donde al multiplicar dos arreglos se obtiene un único valor.
A * B = A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1]*/

#include <stdio.h>
#include <stdlib.h>

void carga(int *&arre, int N)
{
    arre = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i)
    {
        arre[i] = i;
    }
}

void cargaRecursiva(int *&arre, int N, int n)
{
    arre = (int *)malloc(sizeof(int) * N);
    if (n < N)
    {
        arre[n] = n;
        cargaRecursiva(arre, N, n);
    }
}

void mostrar(int *&arre, int N, int n)
{
    if (n < N)
    {
        printf("%d", arre[n]);
        mostrar(arre, N, n + 1);
    }
    else
        printf("\n");
}

// Calcular el producto escalar.

int productoEscalar(int *&arre1, int *&arre2, int M, int N, int n, int prod)
{
    if ((n < N) && (n < M))
    {
        prod = arre1[n] * arre2[n];
        return prod + productoEscalar(arre1, arre2, M, N, n + 1, prod);
    }
    else
        return 0;
}

// Generar una nueva estructura con los valores impares contenidos en uno de los arreglos (realizar un
// subprograma que solicite memoria para la nueva estructura y la devuelva cargada).

int calcularImpares(int *&arre, int N, int n, int cont)
{
    if (n < N)
    {
        if (arre[n] % 2 != 0)
            cont++;
        return calcularImpares(arre, N, n + 1, cont);
    }
    else
        return cont;
}

int valoresImpares(int *&arre, int *&arreImpares, int N)
{
    int cantImpares = calcularImpares(arre, N, 0, 0);
    int cont = 0;
    arreImpares = (int *)malloc(cantImpares * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        if (arre[i] % 2 != 0)
        {
            arreImpares[cont] = arre[i];
            cont++;
        }
    }
    return cantImpares;
}

int main()
{
    int *a, *b, *impar, M, N, resultado, cantImpares;
    puts("Ingrese tamaño del arreglo a");
    scanf("%d", &M);
    carga(a, M);
    // cargaRecursiva(a, M, 0);
    puts("Ingrese tamaño del arreglo b");
    scanf("%d", &N);
    carga(b, N);
    mostrar(a, M, 0);
    mostrar(b, N, 0);

    resultado = productoEscalar(a, b, M, N, 0, 0);
    printf("Resultado del producto escalar: %d \n", resultado);

    cantImpares = valoresImpares(a, impar, N);
    mostrar(impar, cantImpares, 0);

    return 0;
}