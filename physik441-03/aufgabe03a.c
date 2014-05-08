/**
 * Newton-Interpolation
 * 
 * gcc aufgabe03a.c -o aufgabe03a -Wall -pedantic -lm
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
 * Berechnung der Newton-Koeffizienten
 */
void newton_koeffizienten(const int n, const double * const x, const double * const y, double * const c) {
  return;
}

/*
 * Auswertung des Interpolationspolynoms
 */
double horner_eval(const int n, const double xeval, const double * const x, const double * const c) {
  return 1.;
}
int main() {
  /* Initialisiere die Variablen */
  double low = 0., high = 3.; /* Intervall */
  const int n = 4; /* Anzahl Stuetzstellen */
  /* Arrays fuer Daten */
  double *x = (double*) malloc(n * sizeof(double));
  double *y = (double*) malloc(n * sizeof(double));
  double *c = (double*) malloc(n * sizeof(double));
  double x1 = 1.5, x2 = 2.5;
  int i;

  /* Berechne Koeffizienten mit aequidistanten Stuetzstellen */
  stuetzstellen_aequidistant(high, low, n, x, y);
  newton_koeffizienten(n, x, y, c);

  /* Ausgabe der Funktionstabelle und der Koeffizienten */
  printf("\nFunktionstabelle:\n");
  for(i = 0; i < n; i++) {
    printf("%i\t%6.4f\t%6.4f\n", i, x[i], y[i]);
  }
  printf("\nKoeffizienten:\n");
  for(i = 0; i < n; i++) {
    printf("%i\t%6.4f\n", i, c[i]);
  }

  /* Auswertung des Interpolationspolynoms */
  printf("\nf(%6.4f) = %6.4f\n", x1, horner_eval(n, x1, x, c));
  printf("f(%6.4f) = %6.4f\n", x2, horner_eval(n, x2, x, c));

  return 0;
}
