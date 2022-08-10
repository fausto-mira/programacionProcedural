/*Ejercicio 1
Generar un arreglo con 20 numeros enteros y codificar un programa en C que permita:
a) Indicar si alguno de los numeros generados es un cero.
b) Escribir el contenido de las componentes que se encuentren en las posiciones pares.
c) Indicar cantidad de numeros pares que contiene.*/

#include <stdio.h>
#define N 20

void cargaArre(int xarre[N]) {
	int i;
	for(i=0; i<N; i++){
		xarre[i] = i;
	}
	return;
}

void mostrarArre(int xarre[N]) {
	int i;
	for(i=0; i<N; i++){
		printf("%d ", xarre[i]);
	}
	printf("\n");
	return;
}

void numeroCero(int xarre[N]) {
	int band, i;
	
	band = i = 0;  //interesante propiedad de c
	
	while((band==0) && (i<N)){
		(xarre[i] == 0) 
			? band = 1 
			: i++;
	}
	(band == 1) 
		? printf("Algun numero es cero \n")
		: printf("No se encontro ningun 0 \n");
	return;
}

void posicionPar(int xarre[N]) {
	int i;
	for(i=0; i<N; i++){
		if((i%2 == 0) && (i != 0)){
			printf("%d ", xarre[i]);
		}
	}
	printf("\n");
	return;
}

void numeroPar(int xarre[N]) {
	int i, cont = 0;
	for(i=0; i<N; i++){
		if((xarre[i]%2 == 0) && (xarre[i] != 0)){
			cont++;
		}
	}
	printf("Cantidad de numeros pares: %d \n", cont);
	return;
}

int main() {
	int arre[N];
	cargaArre(arre);
	mostrarArre(arre);
	numeroCero(arre);
	posicionPar(arre);
	numeroPar(arre);
	getchar();
	return 0;
}
