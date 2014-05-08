/**
 * Newton-Interpolation
 * 
 * gcc aufgabe03c.c -o aufgabe03c -Wall -pedantic -lm
 **/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Testfunktion
 */
double testfunktion(const double x) {
  return 1.0;
}

/*
 * Berechnung der aequidistanten Stuetzstellen
 */
void stuetzstellen_aequidistant(const double high, const double low, const int n, double * const x, double * const y) {
  return;
}

/*
 * rationale Interpolation nach Neville
 */
double rationale_interpolation(const int n, const double * const x, const double * const y, const double xeval) {
  return 1.;
}

int main() {
  /* Initialisiere die Variablen */
  double low = 0., high = 3.; /* Intervall */
  const int n = 4; /* Anzahl Stuetzstellen */
  /* Arrays fuer Daten */
  double *x = (double*) malloc(n * sizeof(double));
  double *y = (double*) malloc(n * sizeof(double));
  double x1 = 1.5, x2 = 2.5;
  int i;

  /* Berechne Koeffizienten mit aequidistanten Stuetzstellen */
  stuetzstellen_aequidistant(high, low, n, x, y);

  /* Ausgabe der Funktionstabelle */
  printf("\nFunktionstabelle:\n");
  for(i = 0; i < n; i++) {
    printf("%i\t%6.4f\t%6.4f\n", i, x[i], y[i]);
  }

  /* Auswertung des Interpolationspolynoms */
  printf("\nf(%6.4f) = %6.4f\n", x1, rationale_interpolation(n, x, y, x1));
  printf("f(%6.4f) = %6.4f\n", x2, rationale_interpolation(n, x, y, x2));

  return 0;
}
