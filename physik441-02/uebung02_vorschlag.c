/**
 * Newton-Interpolation
 * Author: C. Jost
 * 
 * gcc uebung03_vorschlag.c -o interpolation -Wall -pedantic -lm
 **/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

const double PI = 3.141592653589793238463;

/* Testfunktion */
double function1(double x) {
  return sinh(x);
}

/**
 * Berechnet aequidistante Stuetzstellen fuer eine gegebene Funktion "function1"
 * high, low: Intervallgrenzen
 * n: Anzahl der Stuetzstellen
 * x: enthaelt die Stuetzpunkte
 * y: Funktionswerte an den Stellen x
 **/
void stuetzstelle(const double high, const double low, const int n, double *x, double *y) {
  int i;
  /* Fehler abfangen */
  if(n < 1 || NULL == x || NULL == y) {
    printf("Fehler in der Berechnung der Stuetzstellen!\nAbbruch...\n");
    exit(0);
  }
  /* Berechnung der Stuetzstellen */
  for(i = 0; i < n; i++) {
    x[i] = ((high - low) / (double) (n - 1)) * i + low;
    if(y != NULL)
      y[i] = function1(x[i]);
  }
  return;
}

/**
 * Berechnet die Koeffizienten fuer das Newton-Verfahren
 * n: Anzahl der Stuetzstellen
 * x: Stuetzstellen
 * y: Funktionswerte
 * c: Koeffiziente
 **/
void koeffizienten(const int n, double *x, double *y, double *c) {
  int i, j;
  /* Fehler abfangen */
  if (n < 1 || NULL == x || NULL == y || NULL == c) {
    printf("Fehler in der Berechnung der Koeffizienten!\nAbbruch...\n");
    exit(0);
  }
  /* Initialisierung der Koeffizienten */
  for(i = 0; i < n; i++) {
    c[i] = y[i];
  }
  /* Berechnung der Koeffizienten */
  for(i = 1; i < n; i++) {
    for(j = n-1; j >= i; j--) {
      c[j] = (c[j] - c[j-1]) / (x[j] - x[j-i]);
    }
  }
  return;
}

/**
 * Benutzt das Horner-Schema um das Interpolationspolynom auszuwerten
 * n: Anzahl der Stuetzstellen
 * xeval: Punkt zur Auswertung des Polynoms
 * x: Stuetzpunkte
 * c: Koeffizienten
 **/
double horner_eval(const int n, const double xeval, double *x, double *c) {
  double p = 0.;
  int i;
  /* Fehler abfangen */
  if (n < 1 || NULL == x || NULL == c) {
    printf("Fehler in der Berechnung des Horner-Schemas!\nAbbruch...\n");
    exit(0);
  }
  /* Berechnung der Interpolation */
  for(i = n-1; i >= 0; i--) {
    p = c[i] + (xeval - x[i]) * p;
  }
  return p;
}

int main(void) {
  /* Initialisiere die Variablen */
  double low = 0., high = 3.; /* Intervall */
  const int n = 4; /* Anzahl Stuetzstellen */
  double sx[4], sy[4], c[4]; /* Arrays fuer Daten, Die Laenge muss an n angepasst werden */
  double x1 = 1.5, x2 = 2.5;
  int i;

  /* Berechne Koeffizienten mit aequidistanten Stuetzstellen */
  stuetzstelle(high, low, n, sx, sy);
  koeffizienten(n, sx, sy, c);

  /* Ausgabe der Funktionstabelle und der Koeffizienten */
  printf("\nFunktionstabelle:\n");
  for(i = 0; i < n; i++) {
    printf("%i\t%6.4f\t%6.4f\n", i, sx[i], sy[i]);
  }
  printf("\nKoeffizienten:\n");
  for(i = 0; i < n; i++) {
    printf("%i\t%6.4f\n", i, c[i]);
  }

  /* Auswertung des Interpolationspolynoms */
  printf("\nf(%6.4f) = %6.4f\n", x1, horner_eval(n, x1, sx, c));
  printf("f(%6.4f) = %6.4f\n", x2, horner_eval(n, x2, sx, c));

  return 0;
}