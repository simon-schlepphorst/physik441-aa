/**
 * Beispielprogramm zum Benutzen von komplexen Zahlen
 * Author: C. Jost
 *
 * gcc -Wall -pedantic -o complex complex_beispiel.c -lm
 */

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

int main () {
  /* Initialisierung einer komplexen Zahl */
  double complex  c1 = 1. +  1. * I;
  double complex  c2 = 2. +  2. * I;

  /* Ausgabe einer komplexen Zahl */
  printf("komplexe Zahl: %f + %f i\n", creal(c1), cimag(c1) );

  /* Addition und Subtraktion von komplexen Zahlen */
  c1 = c1 + c2;
  printf("komplexe Zahl: %f + %f i\n", creal(c1), cimag(c1) );
  c1 = c1 - 2.;
  printf("komplexe Zahl: %f + %f i\n", creal(c1), cimag(c1) );
  c1 = c1 + I;
  printf("komplexe Zahl: %f + %f i\n", creal(c1), cimag(c1) );

  /* Multiplikation und Division von komplexen Zahlen */
  c1 = c1 * c2;
  printf("komplexe Zahl: %f + %f i\n", creal(c1), cimag(c1) );
  c1 = c1 / 2.;
  printf("komplexe Zahl: %f + %f i\n", creal(c1), cimag(c1) );
  c1 = I * I;
  printf("komplexe Zahl: %f + %f i\n", creal(c1), cimag(c1) );

  /*
   * alle diese Operationen koennen mit zwei komplexen Zahlen
   * oder einer komplexen Zahl und einer nicht-komplexen Zahl
   */

  /*
   * ACHTUNG:
   * Bei der Division von komplexen Zahlen muessen Sie
   * besonders vorsichtig sein und schauen, ob ihr Ergebniss
   * sinnvoll ist!.
   */

  return 0;
}
