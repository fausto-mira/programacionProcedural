#include <stdio.h>

int main()
{
    int *p;
    p = NULL;

    if (p == 0)
        puts("Verdadero");
    else
        puts("Falso");

    if (!p)
        puts("Verdadero");
    else
        puts("Falso");

    printf("\nValor de EOF: %d\n\n", EOF);

    return 0;
}

// El valor de NULL es 0, y el de EOF -1