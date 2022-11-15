#include <stdio.h>
#include <stdlib.h>

typedef struct rio
{
    float caudal;
    int cod, mes;
} rio;

typedef struct aux
{
    float caudal;
    int cod;
} aux;

void busquedaPorMes(FILE *arch)
{
    rio p;
    int mes;
    puts("Ingrese numero de mes para buscar rios medidos");
    scanf("%d", &mes);
    fseek(arch, 0, SEEK_SET);
    while (fread(&p, sizeof(p), 1, arch))
    {
        if (p.mes == mes)
            printf("Codigo: %d", p.cod);
    }
}

int contarRios(FILE *arch)
{
    rio p;
    int cont = 0;
    rewind(arch);
    while (fread(&p, sizeof(p), 1, arch))
    {
        if (p.mes >= 6 && p.mes <= 12)
            cont++;
    }
    return cont;
}

void copiarAArray(FILE *arch, aux *&arr, int N)
{
    arr = (aux *)malloc(sizeof(aux) * N);
    rio p;
    int i = 0;
    rewind(arch);
    while (fread(&p, sizeof(p), 1, arch))
    {
        if (p.mes >= 6 && p.mes <= 12)
        {
            arr[i].caudal = p.caudal;
            arr[i].cod = p.cod;
            i++;
        }
    }
}

int caudalMenor3(aux *arr, int N, int i, int cont)
{
    if (i < N)
    {
        if (arr[i].caudal == 3)
            cont += 1;
        return cont = caudalMenor3(arr, N, i + 1, cont);
    }
    else
        return cont;
}

int main()
{
    FILE *archivo;
    aux *array;
    int longitud, cont;
    archivo = fopen("DATOS.DAT", "r+");
    if (archivo == NULL)
    {
        puts("Error al abrir el archivo");
        return -1;
    }
    else
    {
        busquedaPorMes(archivo);
        longitud = contarRios(archivo);
        copiarAArray(archivo, array, longitud);
        cont = caudalMenor3(array, longitud, 0, 0);
        printf("Rios caudal menor a 3: %d", cont);
        free(array);
    }
    fclose(archivo);

    return 0;
}