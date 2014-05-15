/**
 * Loesungsbeispiele fuer Ableitungen
 * und Integration von verschiedenen
 * Funktionen
 * 
 * gcc aufgabe05.c -o der_int -Wall -pedantic -lm -std=gnu99
 **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Testfunktionen
 */
double f1(const double x) {
	return sin(x);
}

double f2(const double x) {
	return exp(-0.5 * x * x);
}

double f3(const double x) {
	return log(x);
}

/*
 * Funktionen fuer das Ableiten von Funktionen
 * Input: Stelle x, Schrittweite h, Funktion f
 * Output: Ableitung an der Stelle x
 */
double twopoint(const double x, const double h, double (*f) (const double)) {
	return (f(x + h) - f(x)) / h;
}

double threepoint(const double x, const double h, double (*f) (const double)) {
	return (f(x + h) - f(x - h)) / (2 * h);
}

/*
 * Funktionen fuer das Integrieren von Funktion f1
 * Input: Intervall low-high, Anzahl der Stuetzstellen n
 * Output: Integral der Funktion f1 im Intervall low-high
 */
double trapez(const double low, const double high, const int n, double (*f) (const double)) {
	double h = (high - low) / (double) n;
	double tmp_erg = f(low) + f(high);
	double tmp = low;
	for (int i = 1; i < n; i++){
		tmp += h;
		tmp_erg += 2 * f(tmp);
	}	
	return h * tmp_erg / 2;
}

double simpson(const double low, const double high, const int n, double (*f) (const double)) {
	double h = (high - low) / (double) n;
	double tmp_erg = f(low) + f(high);
	double tmp1;
	double tmp = low;
	for (int i = 1; i < n; i++){
		tmp += h;
		tmp1 = (i %2) ? 4. : 2.;
		tmp_erg += tmp1 * f(tmp);
	}
	return h * tmp_erg / 3;
}

int main() {
  /*
   * allgemeine Variablen
   */
  int i;
  double h; 
  /*
   * Variablen fuer die Differentiation
   */
  const int laenge = 3;
  double *xs = (double*) malloc(laenge * sizeof(double));
  double *genau = (double*) malloc(3 * laenge * sizeof(double));
  /*
   * Variablen fuer die Integration
   */
  double low, high;
  int n;

  printf("Differentiation\n");
  /* Stellen, an denen differenziert wird */
  xs[0] = 0.5;
  xs[1] = 1.;
  xs[2] = 5.;
  /* analytisch berechnete Ableitungen */
  /* cos(x) */
  genau[0] = 0.8775825618903728;
  genau[1] = 0.5403023058681398;
  genau[2] = 0.28366218546322625;
  /* -x*exp(-0.5*x^2) */
  genau[3] = -0.4412484512922977;
  genau[4] = -0.6065306597126334;
  genau[5] = -0.000018633265860393355;
  /* 1 / x */
  genau[6] = 2.;
  genau[7] = 1.;
  genau[8] = 0.2;
  /* Auswertung an den Stellen in xs */
  for(i = 0; i < laenge; ++i) {
    /* Scan durch verschiedene h */
    for(h = 0.1; h > 0.000001; h /= 10.) {
      printf("f1: %f %.6f\t%7.5f (%7.5f)\t%7.5f (%7.5f)\n", xs[i], h,
          twopoint(xs[i], h, f1), fabs(twopoint(xs[i], h, f1) - genau[i]) / genau[i],
          threepoint(xs[i], h, f1), fabs(threepoint(xs[i], h, f1) - genau[i]) / genau[i]);
    }
    /* Scan durch verschiedene h */
    for(h = 0.1; h > 0.000001; h /= 10.) {
      printf("f2: %f %.6f\t%7.5f (%7.5f)\t%7.5f (%7.5f)\n", xs[i], h,
          twopoint(xs[i], h, f2), fabs(twopoint(xs[i], h, f2) - genau[i + 3]) / genau[i + 3],
          threepoint(xs[i], h, f2), fabs(threepoint(xs[i], h, f2) - genau[i + 3]) / genau[i + 3]);
    }
    /* Scan durch verschiedene h */
    for(h = 0.1; h > 0.000001; h /= 10.) {
      printf("f3: %f %.6f\t%7.5f (%7.5f)\t%7.5f (%7.5f)\n", xs[i], h,
          twopoint(xs[i], h, f3), fabs(twopoint(xs[i], h, f3) - genau[i + 6]) / genau[i + 6],
          threepoint(xs[i], h, f3), fabs(threepoint(xs[i], h, f3) - genau[i + 6]) / genau[i + 6]);
    }
  }

  printf("\n\nIntegration\n");
  /* Intervall (-> Integral ist 1.) */
  low = 0.;
  high = 3. * M_PI / 2.;
  /* Scan durch die Zahl der Stuetzstellen
   * und damit durch h */
  for(n = 10; n < 1.e6; n *= 2) {
    h = (high - low) / (double) n;
    printf("%i %.6f\t%7.5f (%7.5f)\t%7.5f (%7.5f)\n", n, h,
      trapez(low, high, n, f1), fabs(trapez(low, high, n, f1) - 1.),
      simpson(low, high, n, f1), fabs(simpson(low, high, n, f1) - 1.) );
  }

  return 0;
}
