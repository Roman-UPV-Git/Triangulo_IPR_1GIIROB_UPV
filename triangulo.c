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

/* Construcción del triangulo */

trian_t crear_triangulo(punto_t v1, punto_t v2, punto_t v3) // Funcion crear puntos
{
  trian_t triangulo;
  triangulo.v1 = v1;
  triangulo.v2 = v2;
  triangulo.v3 = v3;
  return triangulo;
}

int es_valido(trian_t t)
{
  double d12 = distancia(t.v1, t.v2);
  double d23 = distancia(t.v2, t.v3);
  double d13 = distancia(t.v1, t.v3);
  if (d12 + d23 <= d13 || d23 + d13 <= d12 || d12 + d13 <= d23)
    return 0;
  else
    return 1;
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

/* Utilidades */

void imprimir(trian_t t) // Funcion mostrar triangulo por pantalla
{
  printf("Triangulo:\nv1 = (%.2f,%.2f)\nv2 = (%.2f,%.2f)\nv3 = (%.2f,%.2f)\n", t.v1.x, t.v1.y, t.v2.x, t.v2.y, t.v3.x, t.v3.y);
}

/* Programa principal */

int main()
{
  /* Declaracion de variables */
  punto_t v11, v12, v13;
  trian_t t1;

  /* Asignacion de valores de variables */
  v11 = crear_punto(-1, 0);
  v12 = crear_punto(0, 1);
  v13 = crear_punto(1, 0);
  t1 = crear_triangulo(v11, v12, v13);

  /* Mostrar por pantalla */
  imprimir(t1);

  /* Verificacion y calculos */
  if (es_valido(t1))
    printf("Es valido\nPerimetro: %0.3f\nArea: %0.3f", perimetro(t1), area(t1));
  else
    printf("Es invalido\n");
}
