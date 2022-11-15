/*
Una Empresa Constructora procesa el archivo ASPIRANTES.DAT. Este archivo almacena la información de los aspirantes
a un nuevo barrio a construirse: número aspirante, apellido y nombre, cantidad de Integrantes del grupo familiar,
cantidad de cuotas e importe de cuota.
El archivo no posee ningún orden en particular.
Se pide realizar un programa óptimo que a través del uso de funciones genere un menú de opciones que responda a las
siguientes solicitudes:
    1. Listar los aspirantes que han pagado más de $ 77.500, indicando apellido y nombre, cantidad de cuotas e importe
    total abonado a la empresa.
    2. Dado un apellido y nombre que se ingresa por teclado, indicar la cantidad de cuotas y la cantidad de integrantes.
    3. La empresa ha generado un método de selección, que consiste en otorgar una casa a los aspirantes que tienen
    familia numerosa (cantidad de integrantes del grupo familiar mayor a cinco). Generar una nueva estructura que
    almacene el apellido y nombre y cantidad de integrantes de los aspirantes que cumplen con la condición.
    4. Utilizando la estructura generada, mostrar en forma ordenada alfabéticamente, nombre y apellido de cada uno de
    los aspirantes seleccionados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3

typedef char string[30];

typedef struct aspirante
{
    string nom, ap;
    int num, cantIntegrantes, cantCuotas;
    float imp;
} aspirante;

typedef struct nodo
{
    string nom, ap;
    int cantIntegrantes;
    nodo *sig;
} nodo;

typedef nodo *puntero;

void carga(FILE *arch)
{
    aspirante p;
    for (int i = 0; i < N; i++)
    {
        puts("Ingresar datos:");
        getchar();
        scanf("%s", p.nom);
        scanf("%s", p.ap);
        scanf("%d", &p.num);
        scanf("%d", &p.cantIntegrantes);
        scanf("%d", &p.cantCuotas);
        scanf("%f", &p.imp);
        fwrite(&p, sizeof(p), 1, arch);
    }
}

void listar(FILE *arch)
{
    float imp;
    aspirante p;
    rewind(arch);
    while (fread(&p, sizeof(p), 1, arch))
    {
        imp = p.cantCuotas * p.imp;
        if (imp > 77500)
            printf("NyA: %s %s. CantCuotas: %d. ImpTotal: %.2f \n", p.nom, p.ap, p.cantCuotas, imp);
    }
}

void buscarNyA(FILE *arch)
{
    string nom, ap;
    aspirante p;
    rewind(arch);
    puts("Ingrese nombre y apellido a buscar");
    getchar();
    scanf("%s", nom);
    scanf("%s", ap);
    while (fread(&p, sizeof(p), 1, arch))
    {
        if (strcmp(nom, p.nom) == 0 && strcmp(ap, p.ap) == 0)
            printf("CantCuotas: %d. CantIntegrantes: %d", p.cantCuotas, p.cantIntegrantes);
    }
}

void copiarALista(FILE *arch, puntero &cabeza)
{
    aspirante p;
    puntero aux;
    while (fread(&p, sizeof(p), 1, arch))
    {
        if (p.cantIntegrantes == 5)
        {
            aux = (nodo *)malloc(sizeof(nodo));
            strcpy(aux->nom, p.nom);
            strcpy(aux->ap, p.ap);
            aux->cantIntegrantes = 5;
            aux->sig = cabeza;
            cabeza = aux;
        }
    }
}

void ordena(puntero cab)
{
    puntero k, cota, p, aux;
    cota = NULL;
    k = NULL;
    while (k != cab)
    {
        k = cab;
        p = cab;
        while (p->sig != cota)
        {
            if (strcmp(cab->nom, cab->sig->nom) > 0) // && strcmp(cab->ap, cab->sig->ap) > 0
            {
                aux = p->sig;
                p->sig = p;
                p = aux;
                k = p;
            }
            p = p->sig;
        }
        cota = k->sig;
    }
}
void mostrarLista(puntero cabeza)
{
    if (cabeza != NULL)
    {
        printf("NyA: %s %s \n", cabeza->nom, cabeza->ap);
        mostrarLista(cabeza->sig);
    }
}

void liberarLista(puntero &cabeza)
{
    if (cabeza != NULL)
    {
        liberarLista(cabeza->sig);
        free(cabeza);
    }
}

void menu()
{
    puts("1 Carga");
    puts("2 77.500");
    puts("3 Buscar n&p");
    puts("4 Estructura aux");
    puts("5 Mostrar nombres alfabeticamente del aux");
    puts("6 Cerrar programa");
}

void seleccion(int &opcion, FILE *arch, puntero &cabeza)
{
    switch (opcion)
    {
    case 1:
        carga(arch);
        break;

    case 2:
        listar(arch);
        break;

    case 3:
        buscarNyA(arch);
        break;

    case 4:
        copiarALista(arch, cabeza);
        if (cabeza != NULL)
        {
            puts("Auxiliar creado pana");
            ordena(cabeza);
        }

        else
            puts("Problemas\n");
        break;
    case 5:
        mostrarLista(cabeza);
        break;
    case 6:
        opcion = 0;
        break;

    default:
        puts("Opcion incorrecta");
        break;
    }
}

int main()
{
    FILE *archivo;
    puntero cabeza = NULL;
    int x;

    if (!(archivo = fopen("aspirantes.txt", "a+")))
    {
        puts("Error al abrir el archvio");
        exit(1);
    }
    else
        puts("Archivo abierto correctamente");

    do
    {
        menu();
        scanf("%d", &x);
        seleccion(x, archivo, cabeza);
    } while (x != 0);

    fclose(archivo);
    liberarLista(cabeza);
    return 0;
}

/*

Maria
Teresa
1
5
2
50000
Mario
Guemes
2
5
3
30000
Faustino
Mira
3
5
2
25000


*/