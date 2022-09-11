#include <stdio.h>

int main()
{
    int lista[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            lista[i][j] = 0;
        }
    }
    scanf("%d", &lista[0][0]);
    printf("%d", lista[0][0]);
    scanf("%d", &lista[0][0]);
    printf("%d", lista[0][0]);
}