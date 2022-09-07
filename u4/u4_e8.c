/*Ejercicio 8
Dada una matriz cuadrada, calcular la suma de los elementos de su diagonal.*/

#include <stdio.h>
#define N 3

void inicializar(int xtabla[N][N], int x, int y)
{
    if (x < N)
    {
        if (y < N)
        {
            xtabla[x][y] = y + 1;
            inicializar(xtabla, x, y + 1);
        }
        inicializar(xtabla, x + 1, 0);
    }
}

void mostrar(int xtabla[N][N], int x, int y)
{
    if (x < N)
    {
        if (y < N)
        {
            printf("%3d ", xtabla[x][y]);
            mostrar(xtabla, x, y + 1);
        }
        else
        {
            printf("\n");
            mostrar(xtabla, x + 1, 0);
        }
    }
}

int sumaDiagonal(int xtabla[N][N])
{
    return (xtabla[0][0] + xtabla[1][1] + xtabla[2][2]);
}

int sumaDiagonalDos(int xtabla[N][N], int n, int suma)
{
    if (n < N)
    {
        suma += xtabla[n][n];
        return sumaDiagonalDos(xtabla, n + 1, suma);
    }
    else
        return suma;
}

int main()
{
    int tabla[N][N];
    inicializar(tabla, 0, 0);
    mostrar(tabla, 0, 0);
    printf("\n Suma de la diagonales: %d \n\n", sumaDiagonal(tabla));
    printf("\n Suma de la diagonales: %d \n\n", sumaDiagonalDos(tabla, 0, 0));
    return 0;
}