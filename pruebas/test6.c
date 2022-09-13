#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    p = (int *)malloc(sizeof(int) * 100);
    *p = 12;
    printf("P: %ld v: %i\n", sizeof(p), *p);
    free(p);
    return 0;
}