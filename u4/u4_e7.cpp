/*Ejercicio 7
El Ministerio de Producción ha lanzado un Plan de Promoción de Capacitación de Empleados (PPCE) para las PYMES
(Pequeñas j Medianas Empresas). La siguiente tabla detalla los montos financiados para el año actual (expresados
en millones de pesos) según las distintas categorías/sectores, lo que permite clasificar cada una de las empresas.

         Agropecuario      Industria y    Comercio     Servicios      Construcción
                            Minería

Micro         $2               $7,5          $9           $2,5           $3,5
Pequeña       $13              $45,5         $55          $15            $22,5
Mediana       $100             $360          $450         $125           $180

a) Indicar el monto total financiado para una categoría ingresada por teclado.
b) Indicar el monto total financiado para el sector de Servicios, sin importar la categoría de la empresa.
c) Emitir un listado con el total financiado, sin importar la categoría/ sector.
d) Emitir un listado con los montos superiores a uno ingresado por teclado, y a continuación los inferiores e iguales,
indicando sector y categoría.*/

#include <stdio.h>
#include <string.h>
#define M 3
#define N 5

char *sector(int n)
{
    char *resultado[20];
    switch (n)
    {
    case 0:
        strcpy(*resultado, "Micro");
        break;
    case 1:
        strcpy(*resultado, "Pequenia");
        break;
    case 2:
        strcpy(*resultado, "Mediana");
        break;

    default:
        break;
    }
    return *resultado;
}

char *categoria(int n)
{
    char *resultado[30];
    switch (n)
    {
    case 0:
        strcpy(*resultado, "Agropecuario");
        break;
    case 1:
        strcpy(*resultado, "Industriaymineria");
        break;
    case 2:
        strcpy(*resultado, "Comercio");
        break;

    case 3:
        strcpy(*resultado, "Servicios");
        break;

    case 4:
        strcpy(*resultado, "Construccion");
        break;

    default:
        break;
    }
    return *resultado;
}

void mostrar(float xtabla[M][N], int i, int j)
{
    if (i < M)
    {
        if (j < N)
        {
            printf("%7.1f ", xtabla[i][j]);
            mostrar(xtabla, i, j + 1);
        }
        else
        {
            printf("\n");
            mostrar(xtabla, i + 1, 0);
        }
    }
}

float montoTotalCategoria(float xtabla[M][N], int categoria, int j, float acum)
{
    if (j < N)
    {
        acum += xtabla[categoria - 1][j];
        return montoTotalCategoria(xtabla, categoria, j + 1, acum);
    }
    else
        return acum;
}

float montoTotalServicios(float xtabla[M][N], int i, float acum)
{
    if (i < M)
    {
        acum += xtabla[i][3];
        return montoTotalServicios(xtabla, i + 1, acum);
    }
    else
        return acum;
}

float montoTotalFinanciado(float xtabla[M][N], int i, int j, float acum)
{
    if (i < M)
    {
        if (j < N)
        {
            acum += xtabla[i][j];
            return montoTotalFinanciado(xtabla, i, j + 1, acum);
        }
        montoTotalFinanciado(xtabla, i + 1, 0, acum);
    }
    else
        return acum;
}

void montoSuperior(float xtabla[M][N], int i, int j, float num)
{
    if (i < M)
    {
        if (j < N - 1)
        {
            if (xtabla[i][j] > num)
                printf("%.1f, ", xtabla[i][j]);
            montoSuperior(xtabla, i, j + 1, num);
        }
        else if (j == N - 1)
        {
            if (xtabla[i][j] > num)
                printf("%.1f \n", xtabla[i][j]);
            montoSuperior(xtabla, i, j + 1, num);
        }
        else
            montoSuperior(xtabla, i + 1, 0, num);
    }
}

/*
void montoIgualEInferior(float xtabla[M][N], int i, int j, float num)
{
    if (i < M)
    {
        if (j < N)
        {
            if (xtabla[i][j] == num)
            {
                printf("%s:", sector(i));
                printf("%s es igual al numero buscado\n", categoria(j));
            }
            else if (xtabla[i][j] < num)
            {
                printf("%s:", sector(i));
                printf("%s es menor al numero buscado\n", categoria(j));
            }

            montoIgualEInferior(xtabla, i, j + 1, num);
        }
        else
            montoIgualEInferior(xtabla, i + 1, 0, num);
    }
}
*/

void montoIgualEInferior(float xtabla[M][N], int i, int j, float num)
{
    if (i < M)
    {
        if (j < N)
        {
            if (xtabla[i][j] == num)
                printf("sector: %d. categoria: %d es igual al numero buscado\n", i + 1, j + 1);
            else if (xtabla[i][j] < num)
                printf("sector: %d. categoria: %d es menor al numero buscado\n", i + 1, j + 1);

            montoIgualEInferior(xtabla, i, j + 1, num);
        }
        else
            montoIgualEInferior(xtabla, i + 1, 0, num);
    }
}
int main()
{
    float tabla[M][N] = {{2, 7.5, 9, 2.5, 3.5},
                         {13, 45.5, 55, 15, 22.5},
                         {100, 360, 450, 125, 180}};
    int categoria;
    float numero;
    // char resultado[20];
    mostrar(tabla, 0, 0);
    printf("Ingrese una categoria para calcular el total \n");
    scanf("%d", &categoria);
    printf("Total: %.1f \n", montoTotalCategoria(tabla, categoria, 0, 0));
    printf("Total monto de Sercivios %.1f\n", montoTotalServicios(tabla, 0, 0));
    printf("Monto total financiado: %.1f \n", montoTotalFinanciado(tabla, 0, 0, 0));
    printf("Ingrese monto para mostrar montos superiores a este\n");
    scanf("%f", &numero);
    montoSuperior(tabla, 0, 0, numero);
    printf("Montos menores e iguales al buscado: \n\n");
    montoIgualEInferior(tabla, 0, 0, numero);
    return 0;
}
