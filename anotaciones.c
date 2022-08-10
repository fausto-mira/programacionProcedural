#include <stdio.h>

main(){
	
	float num = 122334.1223434;
	printf("%10.2f", num);
	
	int i;
	printf("%d", i);
	
	int x=12, *p;
	p=&x;
	printf("\n %g", p);  //mostrar direccion de memoria contenida en p
	printf("\n %d", *p);  //mostrar lo que apunta p
}


