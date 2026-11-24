#include <stdio.h>
#include <math.h>

/* Estructuras */

typedef struct punto // Estructura de punto
{
  double x;
  double y;
} punto_t;

typedef struct triangulo // Estructura de triangulo
{
  punto_t v1;
  punto_t v2;
  punto_t v3;
} trian_t;

/* Funciones */

/* Predefinidas por Rebollo */

int eq(float a, float b) // Funcion
{
  const float EPS = 1e-6;
  return fabs(a - b) < EPS;
}

/* Sobre puntos */

punto_t crear_punto(double a, double b) // Funcion crear puntos
{
  punto_t punto;
  punto.x = a;
  punto.y = b;
  return punto;
}

double distancia(punto_t p1, punto_t p2) // Funcion dvolver la distancia euclidea entre dos puntos
{
  return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

/* Construccion del triangulo */

trian_t crear_triangulo(punto_t v1, punto_t v2, punto_t v3) // Funcion crear puntos
{
  trian_t triangulo;
  triangulo.v1 = v1;
  triangulo.v2 = v2;
  triangulo.v3 = v3;
  return triangulo;
}

/* Calculos elementales */

double perimetro(trian_t t) // Funcion devuelve perimetro de triangulo
{
  double d12 = distancia(t.v1, t.v2);
  double d23 = distancia(t.v2, t.v3);
  double d13 = distancia(t.v1, t.v3);
  return d12 + d23 + d13;
}

double area(trian_t t) // Funcion devuelve area del triangulo
{
  double d12 = distancia(t.v1, t.v2);
  double d23 = distancia(t.v2, t.v3);
  double d13 = distancia(t.v1, t.v3);
  double s = (d12 + d23 + d13) / 2;
  return sqrt(s * (s - d12) * (s - d23) * (s - d13));
}

/* Validacion */

int es_valido(trian_t t)
{
  double d12 = distancia(t.v1, t.v2);
  double d23 = distancia(t.v2, t.v3);
  double d13 = distancia(t.v1, t.v3);
  if (d12 + d23 < d13 || d23 + d13 < d12 || d12 + d13 < d23 || eq(d12 + d23, d13) || eq(d23 + d13, d12) || eq(d12 + d13, d23)) 
  {
    printf("Es invalido\n");
    return 0;
  }
  else
  {
    printf("Es valido\nPerimetro: %0.3f\nArea: %0.3f\n", perimetro(t), area(t));
    return 1;
  }
}

/* Utilidades */

void imprimir(trian_t t) // Funcion mostrar triangulo por pantalla
{
  printf("Triangulo:\nv1 = (%.2f,%.2f)\nv2 = (%.2f,%.2f)\nv3 = (%.2f,%.2f)\n", t.v1.x, t.v1.y, t.v2.x, t.v2.y, t.v3.x, t.v3.y);
}

/* Programa principal */

int main()
{
  /* Declaracion de variables */
  char decision;
  float x, y;
  punto_t v1, v2, v3;
  trian_t t1;

  /* Creacion del triangulo */

  printf("Introduce los vertices de un triangulo en el formato (x,y)\n");
  do
  {
    printf("Vertice 1 > ");
    scanf(" (%f,%f)", &x, &y);
    v1 = crear_punto(x, y);

    printf("Vertice 2 > ");
    scanf(" (%f,%f)", &x, &y);
    v2 = crear_punto(x, y);

    printf("Vertice 3 > ");
    scanf(" (%f,%f)", &x, &y);
    v3 = crear_punto(x, y);

    t1 = crear_triangulo(v1, v2, v3);
    imprimir(t1);
    es_valido(t1);

    printf("Crear otro triangulo? (s/n) > ");
    scanf(" %c", &decision);
  } while ((decision != 's' && decision != 'n') || decision == 's');

  /* Mostrar por pantalla */
}
