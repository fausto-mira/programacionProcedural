#include <stdio.h>

void FuncionA(int n)
{
    // printf("Funcion A");
    if (n)
    {
        printf("%d", n % 10);
        n = n / 10;
        return FuncionA(n);
    }
    else
        return;
    // por lo que entiendo, esta funcion muestra el resultado del modulo 10 de n, y lo va dividiendo en
    // 10 hasta que n es 0 truncado, y desacopila.
    // lo que realmente hacer: da vuelta el numero xd
}

int FuncionB(int n)
{
    if (n == 0)
        return n;
    else
        return FuncionB(n / 10) + (n % 10);
}

int FuncionC(int x[], int n, int dato)
{
    if (n == 0)
    {
        if (dato > x[n])
            return x[0];
        else
            return dato;
    }
    else
    {
        if (dato > x[n])
            return FuncionC(x, n - 1, x[n]);
        else
            return FuncionC(x, n - 1, dato);
    }
    // esta funcion busca el menor valor del arreglo, por debajo de 50
}
int main()
{
    int n = 6745, m = 5679, r, g;
    int x[4] = {25, 18, 56, 35};
    FuncionA(n);
    r = FuncionB(m);
    printf("\n\n resultado:%d", r);
    g = FuncionC(x, 3, 50);
    printf("\n\n resutado %d\n\n", g);
    return 0;
}