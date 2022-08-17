#include <stdio.h>

int main(){
    int *b, a=1;
    b=&a;
    *b += 1;
    printf(" %X %d", &a, *b);
    return 0;
}