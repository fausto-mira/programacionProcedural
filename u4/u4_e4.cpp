/*Ejercicio 4
Si quieres conseguir un buen trabajo vas a necesitar buenas habilidades. Uno de los perfiles profesionales más
demandados son los programadores, pero ¿qué lenguaje de programación merece la pena aprender? Aprender a
programar te abrirá puertas a otros empleos. Son muchas las empresas las que valoran esta habilidad, pese a que no
sea necesario para el puesto, por la agilidad mental que denota. Por todo ello, la comunidad de desarrolladores
Stack Overflow llevó a cabo encuestas sobre las tendencias del sector, sobre cuál de los siguientes lenguajes utilizan.
1. Javascript: A pesar de tener nombres similares, Javascript no está relacionado con Java. Permite a los
desarrolladores crear elementos interactivos en los sitios web, convirtiéndolo en uno de los lenguajes más
omnipresentes de la web y el más popular del mundo.
2. HTML: Aunque técnicamente no es un lenguaje de programación - es un "lenguaje de marcas" - HTML es la base
para la estructura de cada sitio web.
3. Cascading Style Sheets, o CSS: Es el lenguaje de programación más utilizado para diseñar sitios web y
aplicaciones basadas en navegadores.
4. Java: Fue inventado originalmente por Sun Microsystems en 1991 como lenguaje de programación para sistemas
de televisión interactiva. Desde la compra de Sun, Oracle ha convertido a Java en una potencia. El lenguaje de
programación es la forma más común de construir aplicaciones en Android.
5. Python: Python data de 1989 y es amado por sus fans por su código altamente legible. Muchos programadores
creen que es el lenguaje más fácil de usar.
6. C: Es uno de los lenguajes de programación más antiguos aún en uso común, fue creado a principios de la
década de los 70. En 1978, el legendario manual del lenguaje, "The C Programming Language", fue publicado por
primera vez.
Esta es a información compartida en una encuesta. Para procesarla se ingresa por cada encuestado el número de
lenguaje elegido.
Practica Unidad 4 3
Realizar un programa en C que, utilizando solo funciones recursivas, permita:
a) Generar un arreglo que cuente para cada lenguaje, los encuestados que lo eligieron.
b) Mostrar el/los lenguajes/s que se eligió por menos de 4000 encuestados.
c) Indicar el lenguaje más elegido. (suponer único)
d) Mostrar el total de encuestas realizadas.
e) Mostrar la cantidad de lenguajes que fueron elegidos por menos de 5000 encuestados y cuantos por más de
9000 encuestados (hacer una función recursiva que devuelva las dos cantidades).
f) Realizar el mapa de memoria cuando se invoca a la función construida en el punto d)*/

#include <stdio.h>
#include <string.h>
#define N 6

typedef struct lenguajes
{
    char nombre[20];
    int cont;
} lenguajes;

void inicializacion(lenguajes xarre[], int n)
{
    char nombre[20];
    if (n < 6)
    {
        printf("Ingrese nombre del lenguaje\n");
        scanf("%s", nombre);
        strcpy(xarre[n].nombre, nombre);
        xarre[n].cont = 0;
        inicializacion(xarre, n + 1);
    }
    else
        return;
}

void mostrar(lenguajes xarre[], int n)
{
    if (n < 6)
    {
        printf("%s: %d\n", xarre[n].nombre, xarre[n].cont);
        mostrar(xarre, n + 1);
    }
    else
        return;
}

void carga(lenguajes xarre[N])
{
    int n;
    printf("Ingrese lenguaje (termina con '0') \n");
    scanf("%d", &n);
    if (n)
    {
        xarre[n - 1].cont += 1;
        carga(xarre);
    }
    else
        return;
}

void mayor4000(lenguajes xarre[], int n)
{
    if (n)
    {
        if (xarre[n - 1].cont > 4000)
            printf("Lenguaje %s tiene mas de 4000\n\n", xarre[n - 1].nombre);
        mayor4000(xarre, n - 1);
    }
    else
        return;
}

// Indicar el lenguaje más elegido. (suponer único)

void masElegido(lenguajes xarre[], int n, int mayor, int pos)
{
    if (n)
    {
        if (xarre[n - 1].cont > mayor)
        {
            mayor = xarre[n - 1].cont;
            pos = n;
        }
        masElegido(xarre, n - 1, mayor, pos);
    }
    else
        printf("El lenguaje mas elegido es el %s \n\n", xarre[pos - 1].nombre);
}

// Mostrar el total de encuestas realizadas.

void total(lenguajes xarre[], int n, int acum)
{
    if (n)
    {
        acum += xarre[n - 1].cont;
        total(xarre, n - 1, acum);
    }
    else
        printf("EL total de encuestas es de %d\n\n", acum);
}
// Mostrar la cantidad de lenguajes que fueron elegidos por menos de 5000 encuestados y cuantos por más de
// 9000 encuestados (hacer una función recursiva que devuelva las dos cantidades).

/*
void masMenos(lenguajes xarre[], int n, int &contMenor, int &contMayor)
{
    if (n)
    {
        if (xarre[n - 1].cont < 5000)
            contMenor++;
        else if (xarre[n - 1].cont > 9000)
            contMayor++;
        masMenos(xarre, n - 1, contMenor, contMayor);
    }
}
*/

int masMenos(lenguajes xarre[], int n, int contMenor, int &contMayor)
{
    contMenor = 0;
    if (n < N)
    {
        if (xarre[n - 1].cont < 5000)
            contMenor++;
        if (xarre[n - 1].cont > 9000)
            contMayor++;
        masMenos(xarre, n + 1, contMenor, contMayor);
    }
    return (contMenor);
}

int main()
{
    lenguajes arre[N];
    inicializacion(arre, 0);
    mostrar(arre, 0);
    carga(arre);
    arre[0].cont += 4000;
    mostrar(arre, 0);
    mayor4000(arre, N);
    masElegido(arre, N, 0, -1);
    total(arre, N, 0);
    int contMenor, contMayor = 0;
    contMenor = masMenos(arre, N, contMenor, contMayor);
    printf("Menos de 5000: %d. Mas de 9000: %d\n\n", contMenor, contMayor);
    return 0;
}