/*
Ejercicio 8
La UNSJ todos los años otorga becas, para lo cual se ingresa el número de facultades participantes, de las misma se
ingresan los nombres y de cada una las inscripciones de los alumnos aspirantes a las becas de ayuda económica. Se
ingresa, en forma ordenada por facultad, los datos de cada alumno: Nombre, promedio y año que cursa.
Se pide, un programa que permita:
a) Realizar un listado ordenado por promedio, de los alumnos inscriptos en una determinada facultad cuyo nombre
se ingresa por teclado. (Mostrar nombre del alumno, promedio y año que cursa).
b) Indicar el nombre de la facultad que tiene menos inscriptos y la cantidad de inscriptos suponer único).
c) Mostar por cada facultad la cantidad de alumnos con promedio mayor o igual a 7, que cursan de segundo año en
adelante. Usar una función recursiva.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CANT_FACULTADES;

typedef char cadena[30];

typedef struct alumno
{
    cadena nombre;
    float promedio;
    int año;
    alumno *sig;
} alumno;

typedef alumno *puntero;

typedef struct facultad
{
    cadena nombre;
    int cant;
    puntero cabeza;
} facultad;

void inicializacion(facultad *&arr, int N)
{
    puts("Ingrese cantidad de facultades");
    scanf("%d", &CANT_FACULTADES);
    arr = (facultad *)malloc(sizeof(facultad) * CANT_FACULTADES);
    for (int i = 0; i < N; i++)
    {
        arr[i].cabeza = NULL;
        arr[i].cant = 0;
    }
}

void insertar(puntero &cabeza, puntero anterior, puntero nuevo)
{
    if ((cabeza != NULL) && ((nuevo->promedio) > (cabeza->promedio)))
    {
        anterior = cabeza;
        cabeza = cabeza->sig;
        insertar(cabeza, anterior, nuevo);
    }
    else
    {
        anterior->sig = nuevo;
        nuevo->sig = cabeza;
    }
}

void cargaAlumnos(puntero &cabeza)
{
    cadena nombre;
    puntero nuevo;
    float prom;
    int anio;
    puts("Ingrese nombre de alumno. Termina con 'FIN'");
    fgets(nombre, 30, stdin);
    if (strcmp(nombre, "FIN") != 0)
    {
        puts("Ingrese promedio del alumno");
        scanf("%f", &prom);
        puts("Ingrese año que cursa el alumno");
        scanf("%d", &anio);
        nuevo = (puntero)malloc(sizeof(alumno));
        strcpy(nuevo->nombre, nombre);
        nuevo->promedio = prom;
        nuevo->año = anio;
        nuevo->sig = NULL;
        insertar(cabeza, NULL, nuevo);
        cargaAlumnos(cabeza);
    }
}

void carga(facultad *&arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("CARGA FACULTAD N°%d \n", i + 1);
        puts("Ingrese nombre de la facultad");
        fgets(arr[i].nombre, 30, stdin);
        cargaAlumnos(arr[i].cabeza);
        puts("\n");
    }
}

void mostrarFacultadOrdenado(puntero cabeza)
{
    if (cabeza != NULL)
    {
        printf("Nombre: %s \nPromedio: %d \nAnio: %d \n\n", cabeza->nombre, cabeza->promedio, cabeza->año);
        mostrarFacultadOrdenado(cabeza->sig);
    }
}

void mostrar(facultad *&arr, int N)
{
    cadena nombre;
    int i = 0, resultado = 0;
    do
    {
        puts("Ingrese nombre de la facultad a buscar");
        fgets(nombre, 30, stdin);
        if (strncmp(arr[i].nombre, nombre, strlen(nombre)) == 0 && i < N)
        {
            mostrarFacultadOrdenado(arr[i].cabeza);
            resultado = 1;
        }
        else if (i < N)
            ++i;
        else
        {
            puts("Facultad ingresada no existe");
            i = 0;
        }

    } while (resultado = 0);
}

int contar(puntero cabeza, int cont)
{
    if (cabeza != NULL)
    {
        cont += 1;
        return cont = contar(cabeza->sig, cont);
    }
    else
        return cont;
}

void contarInscriptos(facultad *&arr, int N)
{
    int resultado;
    for (int i = 0; i < N; i++)
    {
        resultado = contar(arr[i].cabeza, 0);
        arr[i].cant = resultado;
    }
}

int menosInscriptos(facultad *&arr, int N, int i, int menor, int pos)
{
    if (i < N)
    {
        if (arr[i].cant < menor)
        {
            menor = arr[i].cant;
            pos = i;
        }
        return pos = menosInscriptos(arr, N, i + 1, menor, pos);
    }
    else
        return pos;
}

int contarPromedio7anio2(puntero cabeza, int cont)
{
    if (cabeza != NULL)
    {
        if (cabeza->promedio >= 7 && cabeza->año == 2)
            cont += 1;
        return cont = contarPromedio7anio2(cabeza->sig, cont);
    }
    else
        return cont;
}

int promedio7anio2(facultad *&arr, int N, int i, int cont)
{
    if (i < N)
    {
        cont = contarPromedio7anio2(arr[i].cabeza, cont);
        if (cont == 0)
            printf("Ningun alumno supera las condiciones en la facu %s", arr[i].nombre);
        else
            printf("Facultad %s tiene %d alumnos con prom mayor igual a 7 y esta en 2° anio");
        promedio7anio2(arr, N, i + 1, 0);
    }
}

int main()
{
    facultad *array;
    int pos;

    inicializacion(array, CANT_FACULTADES);
    carga(array, CANT_FACULTADES);
    mostrar(array, CANT_FACULTADES);

    contarInscriptos(array, CANT_FACULTADES);
    pos = menosInscriptos(array, CANT_FACULTADES, 0, 9999999, pos);
    printf("Facultad con menor cantidad de inscriptos es %s. Cantidad: %d\n", array[pos].nombre, array[pos].cant);

    promedio7anio2(array, CANT_FACULTADES, 0, 0);

    return 0;
}