/*Ejercicio 3
Generar un arreglo de registros que posea la siguiente información de 10 alumnos de procedural: Nombre,
Apellido y DNI.
a) Cargar los datos de los alumnos.
b) Listar los alumnos cargados.
c) Indicar cuántos alumnos tiene DNI mayor a 40 millones.*/

#include <stdio.h>
#include <string.h>
#define N 2
#define M 20

typedef struct{
    char nom[M], ap[M];
    int dni;
} alumno;

void carga(alumno datos[N]) {
    int i;
    for(i=0; i<N; i++){
        puts("Ingrese nombre del alumno");
        scanf("%s", datos[i].nom);
        puts("Ingrese apellido del alumno");
        scanf("%s", datos[i].ap);
        puts("Ingrese numero de DNI");
        scanf("%d", &datos[i].dni);
    }
    return;
}

void mostrar(alumno datos[N]) {
    int i;
    for(i=0; i<N; i++){
        printf("ALUMNO N°%d \n", i);
        printf("Nombre: %s \n", datos[i].nom);
        printf("Apellido: %s \n", datos[i].ap);
        printf("DNI: %d \n", datos[i].dni);
        printf("\n");
    }
    return;
}

void mayor(alumno datos[N]) {
    int i, cont = 0;
    for(i=0; i<N; i++){
        if(datos[i].dni > 40000000){
            cont++;
        }
    }
    printf("Cantidad de alu > 40.000.000: %d \n", cont);
    return;
}

int main(){
    alumno datos[N];
    carga(datos);
    mostrar(datos);
    mayor(datos);
    return 0;
}