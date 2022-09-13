#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *aux;
    aux = (char *)malloc(30 * sizeof(char));
    fgets(aux, 30, stdin);
    printf("%s \n", aux);
    fflush(stdin);
    fgets(aux, 30, stdin);
    printf("%s \n\n", aux);
}

// prueba de que pasa si introduzco una cadena mas corta luego de una mas larga
// ej; 1) asdfasdfasdf 2)asdf
