#include <stdio.h>
#define N 3

// ejrmplo de carga con arreglos

void carga(int arr[], int i)
{
    if (i != N)
    {
        printf("Ingrese valor \n");
        scanf("%d", arr + i);
        carga(arr, i + 1);
    }
}

void mostrar(int arre[], int i)
{
    if (i < N)
    {
        printf("%d\n", arre[i]);
        mostrar(arre, i + 1);
    }
}

int main()
{
    int arre[N];
    carga(arre, 0);
    mostrar(arre, 0);
}