/*Ejercicio 2
Hacer una función recursiva que muestre la tabla de multiplicar para un número (entre 1 y 9)
ingresado por teclado.*/

#include <stdio.h>

int tablaMultiplicar(int n, int m)
{
    if (n)
    {
        tablaMultiplicar(n - 1, m);
        printf("%d\n", m * n);
    }
}

int main()
{
    int n;
    printf("Ingrese un numero del 1 al 9\n");
    scanf("%d", &n);
    int m = n;
    tablaMultiplicar(n + 1, m);
    return 0;
}