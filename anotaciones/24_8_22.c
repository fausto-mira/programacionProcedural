#include <stdio.h>
#define n 5

/*
variables locales = variables AUTOMATICAS
variables globales = variables EXTERNAS

RECURSIVIDAD

Se puede usar un if(bandera), ya que mientras int bandera sea distinta de 0,
sera verdadera, y si es 0 sera falsa.


*/

void stat(void) // ejemplo de static
{
    static a = 0;
    printf("%d \n", a);
    a++;
    return;
}

void carga(int arr[n], int i)
{
    if (i != n)
    {
        printf("\ningrese valor la posición%d:", i);
        scanf("%d", arr + i);
        carga(arr, i + 1);
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
        stat();

    int b = 0;
    printf("%x", &b);

    int arr[n], i = 0;
    carga(arr, i);

    for (int j = 0; j < n; j++)
    {
        printf("%d", arr[j]);
    }
    return 0;
}