#include <stdio.h>
#include <stdlib.h>

typedef char cadena[30];

typedef struct postulante
{
    cadena nombre;
    long dni;
    char sexo;
    int cod, edad;
} postulante;

void carga(postulante *&arr, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        puts("Ingrese nombre de postulante");
        scanf("%[^\n]s", arr[i].nombre);
        puts("Ingrese dni");
        scanf("%ld", &arr[i].dni);
        getchar();
        puts("Ingrse sexo del postulante M o F");
        scanf("%c", &arr[i].sexo);
        puts("Ingrese codigo de localidad donde vive");
        scanf("%d", &arr[i].cod);
        puts("Ingrese edad");
        scanf("%d", &arr[i].edad);
        getchar();
    }
}

int contarVarones(postulante *&arr, int &loc3, int N)
{
    int loc16 = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].cod == 3)
            loc3 += 1;
        if (arr[i].cod == 16)
            loc16 += 1;
    }
    return loc16;
}

float edadPromedioVarones(postulante *&arr, int N)
{
    int acum = 0;
    for (int i = 0; i < N; i++)
        if (arr[i].sexo == 'M')
            acum += arr[i].edad;
    return (acum / N);
}

void mostrar(postulante *&arr, int N, int i)
{
    if (i < N)
    {
        if (arr[i].cod == 10)
            printf("%s %ld\n", arr[i].nombre, arr[i].dni);
        mostrar(arr, N, i + 1);
    }
}

int main()
{
    postulante *array;
    int cant, loc3 = 0, loc16;

    puts("Ingrese cantidad de postulantes");
    scanf("%d", &cant);
    getchar();
    array = (postulante *)malloc(sizeof(postulante) * cant);
    carga(array, cant);

    loc16 = contarVarones(array, loc3, cant);
    printf("Cantidad loc 3: %d\nCantidad loc 16: %d\n", loc3, loc16);

    printf("Edad promedio de los varones: %.0f\n", edadPromedioVarones(array, cant));

    puts("Nombre de psotulantes que viven en la localidad 10");
    mostrar(array, cant, 0);

    free(array);

    return 0;
}