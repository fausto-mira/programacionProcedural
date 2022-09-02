/*Ejercicio 3
La función mcd calcula el máximo común divisor de un número, está escrita en forma iterativa. Escribirla de forma
recursiva.*/
/** Máximo común divisor en C con el algoritmo de Euclides, implementado con ciclo while * */

/*
#include <stdio.h>
int maximo_comun_divisor(int a, int b)
{
    int temporal; // Para no perder b
    while (b != 0)
    {
        temporal = b;
        b = a % b; // % es el modulo entre a y b
        a = temporal;
    }
    return a;
}
int main(void)
{
    int a, b;
    printf("ingrese numero a \n");
    scanf("%d", &a);
    printf("Ingrese numero b \n");
    scanf("%d", &b);
    printf("MCD de a y b: %d\n", maximo_comun_divisor(a, b));
    getchar();
}
*/

#include <stdio.h>

int maximo_comun_divisor(int a, int b)
{
    int temporal; // Para no perder b
    if (b != 0)
    {
        temporal = b;
        b = a % b; // % es el modulo entre a y b
        a = temporal;
        return maximo_comun_divisor(a, b);
    }
    return a;
}

int main(void)
{
    int a, b;
    printf("ingrese numero a \n");
    scanf("%d", &a);
    printf("Ingrese numero b \n");
    scanf("%d", &b);
    printf("MCD de a y b: %d\n", maximo_comun_divisor(a, b));
    getchar();
}