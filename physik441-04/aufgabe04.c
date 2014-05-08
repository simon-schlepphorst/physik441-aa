/**
 * schnelle Fourier-Transformation
 * 
 * gcc aufgabe04.c -o aufgabe04 -Wall -pedantic -lm
 **/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

/*
 * Testfunktion
 */
double complex testfunktion(const double complex x) {
  return 1.0;
}

/*
 * Berechnung der aequidistanten Stuetzstellen im Intervall [0, 1[
 */
void stuetzstellen_aequidistant(const int n, double complex * const y) {
  return;
}

/*
 * Berechnung der schnellen Fourier-Transformation
 */
void fft(const int r, double complex * const f) {
  return;
}

/*
 * Sortieren der Koeffizienten
 */
void indexsortieren(const int n, int * const index) {
  return;
}

int main() {
  /* Parameter fuer die FFT */
  const int r = 3;
  const int n = pow(2, r);
  
  double complex *f;
  int *index;

  int i;

  index = (int *) malloc(n * sizeof(int));
  f = (double complex *) malloc(n * sizeof(double complex)); 

  stuetzstellen_aequidistant(r, f);
  
  printf("Unsortiert:\n");
  fft(r, f);
  for(i = 0; i < n; ++i) {
    printf("%i: %f + %fi\n", i, creal(f[i]), cimag(f[i]));
  }

  printf("Sortiert:\n");
  indexsortieren(r, index);
  for(i = 0; i < n; ++i) {
    printf("%i -> %i: %f + %fi\n", i, index[i], creal(f[index[i]]), cimag(f[index[i]]));
  }

  return 0;
}
