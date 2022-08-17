/*Ejercicio 6
En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa
un área temática. En cada sala se dictan 4 conferencias en distintos turnos. Por cada interesado se ingresa
número del área temática (1-6), y turno al que quiere asistir (1-4). La Facultad desea llevar un registro de la
cantidad de alumnos inscriptos en cada área y en cada turno, para ello realizar los siguientes items:
a) Carga de los datos. La carga es desordenada, cada alumno indica área y turno. No se sabe la cantidad de
alumnos.
b) Indicar la cantidad de inscriptos en cada turno de cada área.
c) Dada un área temática, indicar el promedio de inscriptos.*/

#include <stdio.h>
#define f 6
#define c 4

void inicializacion(int xtabla[f][c]){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++)
            xtabla[i][j] = 0;
    }
    return;
}

void carga(int xtabla[f][c]){
    int area, turno;
    puts("Ingrese area tematica (termina con '0')");
    scanf("%d", &area);
    while( area != 0 ){
        
        puts("Ingrese turno");
        scanf("%d", &turno);
        xtabla[area-1][turno-1]++ ;
        puts("Ingrese area tematica");
        scanf("%d", &area);
    }
    return;
}

void mostrar(int xtabla[f][c]){
    puts("\nTABLA: ------------------------------------\n");
    puts("\t   Turno 1 Turno 2 Turno 3 Turno 4 \n");
    for(int i=0; i<f; i++){
        printf("Tematica %d %7d %7d %7d %7d \n", i+1, xtabla[i][0], xtabla[i][1],xtabla[i][2], xtabla[i][3]);
    }
    printf("-------------------------------------------\n\n");
    return;
}

void promedio(int xtabla[f][c]){
    int area;
    float prom=0;
    puts("Ingrese area tematica para calcular el promedio");
    scanf("%d", &area);
    for(int j=0; j<f; j++){
        prom += xtabla[area-1][j];
    }
    printf("El promedio del area %d es de %.2f \n\n", area, prom/c);
    return;
}

int main(){
    int tabla[f][c];

    inicializacion(tabla);
    carga(tabla);
    mostrar(tabla);
    promedio(tabla);

    return 0;
}