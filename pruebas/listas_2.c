#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int num;
    struct nodo *sig;
} nodo;

typedef nodo *puntero;

int main()
{
    puntero cabeza;
    cabeza = NULL;
    int num;

    puts("Inrgese numero para guardar en la lista (finaliza con -1)");
    scanf("%d", &num);
    while (num != -1)
    {
    }
    return 0;
}