#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct inf
{
	int cod;
	float imp;
	int tipo;
};

struct lista
{
	inf A;
	struct lista *sig;
};
typedef struct lista *puntero;

void recorre(puntero p, puntero k, puntero n)
{
	if (p != NULL && n->A.cod > p->A.cod)
	{
		k = p;
		p = p->sig;
		return recorre(p, k, n);
	}
	k->sig = n;
	n->sig = p;
}

void Carga(puntero &cab)
{
	puntero nuevo, k, p;
	int c;
	printf("Ingrese el numero de operacion \n");
	scanf("%d", &c);
	while (c != 0)
	{
		nuevo = (puntero)malloc(sizeof(struct lista));
		nuevo->A.cod = c;
		printf("Ingrese el importe de la operacion %d \n", nuevo->A.cod);
		scanf("%f", &nuevo->A.imp);
		printf("Ingrese el tipo 1 (cobro) o 2 (pago) de la operacion %d \n", nuevo->A.cod);
		scanf("%d", &nuevo->A.tipo);
		if (cab == NULL)
		{
			nuevo->sig = cab;
			cab = nuevo;
		}
		else
		{
			k = cab;
			p = cab;
			if (nuevo->A.cod > p->A.cod)
			{
				recorre(p, k, nuevo);
			}
			else if (nuevo->A.cod < p->A.cod)
			{
				nuevo->sig = cab;
				cab = nuevo;
			}
		}
		printf("Ingrese el numero de operacion, 0 para terminar \n");
		scanf("%d", &c);
	}
}

void Mostrar(puntero cab)
{
	while (cab != NULL)
	{
		printf("\nOperacion: %d \n", cab->A.cod);
		printf("Importe: %.2f \n", cab->A.imp);
		printf("Tipo: %d \n", cab->A.tipo);
		cab = cab->sig;
	}
}

void Indicar(puntero cab, float &a, puntero aux)
{
	if (cab == NULL)
	{
		return;
	}

	if (cab->A.imp > a && cab->A.tipo == 1)
	{
		a = cab->A.imp;
	}

	aux = cab;
	cab = cab->sig;
	Indicar(cab, a, aux);

	if (aux->A.imp == a && aux->A.tipo == 1)
	{
		printf("Codigo de operacion %d \n", aux->A.cod);
	}
}

void CargaA(puntero cab, FILE *archi)
{
	while (cab != NULL)
	{
		fwrite(&cab->A, sizeof(cab->A), 1, archi);
		cab = cab->sig;
	}
}

void Eliminar(puntero &cab)
{
	puntero p;
	while (cab != NULL)
	{
		p = cab;
		cab = cab->sig;
		free(p);
	}
}

void MostrarA(FILE *archi)
{
	inf d;
	rewind(archi);
	printf("\nLeido desde el archivo \n");
	while (fread(&d, sizeof(d), 1, archi))
	{
		printf("\nOperacion: %d \n", d.cod);
		printf("Importe: %.2f \n", d.imp);
		printf("Tipo: %d \n", d.tipo);
	}
}

void IndicarA(FILE *archi)
{
	inf d;
	fpos_t x;
	fseek(archi, 0, SEEK_END);
	fgetpos(archi, &x);
	int valor = (int)(x / sizeof(d));
	printf("\nLa cantidad de elementos son (%d) \n", valor);
}

void Modificar(FILE *archi, float m)
{
	inf d;
	rewind(archi);
	fread(&d, sizeof(d), 1, archi);
	while (!feof(archi) && d.imp != m)
	{
		fread(&d, sizeof(d), 1, archi);
	}
	if (!feof(archi))
	{
		printf("Cod (%d), imp (%.2f),tipo (%d) \n", d.cod, d.imp, d.tipo);
		printf("Modificar imp \n");
		scanf("%f", &d.imp);
		fseek(archi, -sizeof(d), SEEK_CUR);
		fwrite(&d, sizeof(d), 1, archi);
	}
}

void Editar(FILE *archi, int cd)
{
	inf d;
	fseek(archi, cd * sizeof(d), SEEK_SET);
	fread(&d, sizeof(d), 1, archi);
	printf("Cod (%d), imp (%.2f),tipo (%d) \n", d.cod, d.imp, d.tipo);
	printf("Modifique imp \n");
	scanf("%f", &d.imp);
	printf("Modifique tipo \n");
	scanf("%d", &d.tipo);
	fseek(archi, cd * sizeof(d), SEEK_SET);
	fwrite(&d, sizeof(d), 1, archi);
}

float IndicarA(FILE *archi, float a, int &c, int &x)
{
	inf d;
	rewind(archi);
	while (fread(&d, sizeof(d), 1, archi))
	{
		if (d.tipo == 2)
		{
			a = a + d.imp;
			c = c + 1;
		}
		if (d.imp < 25)
		{
			x++;
		}
	}
	return (a);
}

void Eliminar2(FILE *archi, int &x)
{
	inf d, m;
	int b, c = 0;
	fseek(archi, 0, SEEK_SET);
	while (x != 0)
	{
		b = 0;
		while ((b == 0) && fread(&d, sizeof(d), 1, archi))
		{
			if (d.imp < 25)
			{
				b = 1;
				x--;
			}
		}

		if (b == 1)
		{
			fseek(archi, -sizeof(d), SEEK_CUR);
			d.cod = -1;
			fwrite(&d, sizeof(d), 1, archi);
		}

		fseek(archi, -sizeof(d), SEEK_SET);
	}
}

void comprimir(FILE *A, FILE *B)
{
	inf d;
	fseek(A, 0, SEEK_SET);
	fread(&d, sizeof(d), 1, A);
	while (feof(A) == 0)
	{
		if (d.cod != -1)
		{
			fwrite(&d, sizeof(d), 1, B);
		}
		fread(&d, sizeof(d), 1, A);
	}

	fclose(A);
}

void MostrarB(FILE *A)
{
	inf d;
	fseek(A, 0, SEEK_CUR);
	fread(&d, sizeof(d), 1, A);
	printf("\nULTIMO ELEMENTO \n");
	printf("\nOperacion: %d \n", d.cod);
	printf("Importe: %.2f \n", d.imp);
	printf("Tipo: %d \n", d.tipo);
}

int main()
{
	FILE *archivo;
	FILE *auxarc;
	float a = 0;
	int count = 0, x = 0, cd;
	puntero cab, aux;
	cab = NULL;
	Carga(cab);
	Mostrar(cab);
	printf("\n\n\n\nMOSTRAR\n");
	Indicar(cab, a, aux);
	printf("\n\n\n");
	if ((archivo = fopen("lista.txt", "w+")) == NULL)
	{
		printf("\nError\n");
	}
	else
	{
		CargaA(cab, archivo);
		Eliminar(cab);
		Mostrar(cab);
		MostrarA(archivo);
		IndicarA(archivo);
		printf("\nIngrese el imp a modificar \n");
		scanf("%f", &a);
		Modificar(archivo, a);
		MostrarA(archivo);
		printf("\nIngrese el codigo del producto a modificar \n");
		scanf("%d", &cd);
		Editar(archivo, cd - 1);
		MostrarA(archivo);
		a = 0;
		a = IndicarA(archivo, a, count, x);
		printf("Promedio de importes pagados (%.2f) \n", a / count);
		Eliminar2(archivo, x);
		MostrarA(archivo);
		if ((auxarc = fopen("auxiliar.txt", "w+")) == NULL)
		{
			printf("\nError\n");
		}
		else
		{
			comprimir(archivo, auxarc);
			remove("lista.txt");
			rename("auxiliar.txt", "lista.txt");
			printf("\n\n\n\nELIMINADO");
			MostrarA(auxarc);
			MostrarB(auxarc);
		}
	}
}
