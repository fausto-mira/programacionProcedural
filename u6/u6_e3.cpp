/*
Ejercicio 3
Se registra la información de las operaciones realizadas por un cajero durante un fin de semana. De cada operación
se conoce: numero de operación, importe y tipo de operación (1: cobro; 2: pago).
Utilizando funciones óptimas realice lo siguiente:
a) Genere una lista con la información de las operaciones.
b) Indique cual es el/los numero/s de mayor importe cobrado. (usar una función recursiva)
c) Con la información de la lista genere un archivo con los datos de los pagos realizados.
d) Eliminar la lista generada.
e) Indicar en el principal el importe promedio de los pagos realizados.
f) Eliminar del archivo los pagos menores a $500.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct operacion
{
    int num, tipo;
    float imp;
} operacion;

typedef struct nodo
{
    operacion dato;
    nodo *sig;
} nodo;

typedef nodo *puntero;

int validarTipo()
{
    int tipo;
    puts("Ingrese tipo de operacion (1: cobro; 2: pago)");
    scanf("%d", &tipo);
    if (tipo == 1 || tipo == 2)
        return tipo;
    else
    {
        puts("Tipo incorrecto");
        return validarTipo();
    }
}

void cargaOperaciones(puntero &cabeza)
{
    int numOp;
    puntero nuevo;
    puts("Ingrese numero de operacion (termina con '0')");
    scanf("%d", &numOp);
    while (numOp)
    {
        nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->dato.num = numOp;
        puts("Ingrese importe");
        scanf("%f", &nuevo->dato.imp);
        nuevo->dato.tipo = validarTipo();
        nuevo->sig = cabeza;
        cabeza = NULL;
        puts("Ingrese numero de operacion (termina con '0')");
        scanf("%d", &numOp);
    }
}

float buscarMayor(puntero cabeza, float mayor)
{
    if (cabeza != NULL)
    {
        if (cabeza->dato.imp > mayor)
            mayor = cabeza->dato.imp;
        return buscarMayor(cabeza->sig, mayor);
    }
    else
        return mayor;
}

void mostrarMayor(puntero cabeza, float mayor)
{
    if (cabeza != NULL)
    {
        if (cabeza->dato.imp == mayor)
            printf("Operacion n°%d\n", cabeza->dato.num);
        buscarMayor(cabeza->sig, mayor);
    }
}

void guardarLista(puntero cabeza, FILE *arch)
{
    if (cabeza != NULL)
    {
        if (cabeza->dato.tipo == 2)
        {
            fwrite(&cabeza, sizeof(nodo), 1, arch);
            guardarLista(cabeza->sig, arch);
        }
    }
}

void liberar(puntero &cabeza)
{
    if (cabeza != NULL)
    {
        liberar(cabeza->sig);
        free(cabeza);
    }
}

float promedio(FILE *arch)
{
    float acum = 0;
    int cant = 0;
    operacion aux;

    while (fread(&aux, sizeof(aux), 1, arch))
    {
        acum += aux.imp;
        cant++;
    }

    return (acum / cant);
}

void copiarMenoresA500(FILE *arch, FILE *archAux)
{
    operacion auxiliar;
    while (fread(&auxiliar, sizeof(auxiliar), 1, arch))
    {
        if (auxiliar.imp > 500)
            fwrite(&auxiliar, sizeof(auxiliar), 1, archAux);
    }
}

int main()
{
    puntero cabeza = NULL;
    float mayor;
    FILE *archivo, *archivoAux;

    cargaOperaciones(cabeza);

    puts("\n\nNumeros de operaciones con importe igual al al mayor");
    mayor = buscarMayor(cabeza, 0);
    mostrarMayor(cabeza, mayor);

    archivo = fopen("operaciones.dat", "wb");
    if (archivo == NULL)
        puts("Error al intentar abrir el archivo 'operaciones.dat'");
    else
    {
        guardarLista(cabeza, archivo);
        fclose(archivo);
    }

    liberar(cabeza);

    archivo = fopen("operaciones.dat", "rb");
    if (archivo == NULL)
        puts("Error al intentar abrir el archivo 'operaciones.dat'");
    else
    {
        printf("EL importe promedio de los pagos realizados es de $%.2f\n", promedio(archivo));
        archivoAux = fopen("operacionesAuxiliar.dat", "wb");
        if (archivoAux == NULL)
            puts("Error al intentar abrir el archivo 'operacionesAuxiliar.dat'");
        else
        {
            copiarMenoresA500(archivo, archivoAux);
            fclose(archivoAux);
        }
        fclose(archivo);
    }

    remove("operaciones.dat");
    rename("opearcionesAuxiliar.dat", "operaciones.dat");

    return 0;
}