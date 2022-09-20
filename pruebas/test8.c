#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}, i = 0;
    for (;;)
    {
        printf("%d", arr[i]);
        if (arr[i] == 4)
            break;
        ++i;
    }
}