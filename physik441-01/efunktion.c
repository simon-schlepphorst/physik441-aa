/*
 * gcc -Wall -pedantic efunktion.c
 * Simon Schlepphorst
 */

#include <stdio.h>

/**
 * Taylorreihe der e-Funktion
 *
 * \param[in] n Ordnung der Entwicklung
 * \param[in] x Entwicklungspunkt
 */

double efunc (int n, double x){
	double result = 1;
	double summand = 1;
	for (int i = 1; i <= n; i++){
		summand = summand * x / i;
		result = result + summand;
	}
	return result;
}

int main(){
	int cap = 30;
	double a = 1;
	double b = 3;
	double c = -4;

	double tmp_a;
	double tmp_b;
	double tmp_c;
	double tmp_d;

	printf("#\texp(%f)\texp(%f)\texp(%f)\t1/exp(%f)\n", a, b, c, -c);

	for (int i = 0; i <= cap; i++){
		tmp_a = efunc (i, a);
		tmp_b = efunc (i, b);
		tmp_c = efunc (i, c);
		tmp_d = 1 / efunc(i, -c);
		printf("%d\t%f\t%f\t%f\t%f\n", i, tmp_a, tmp_b, tmp_c, tmp_d);
	}
	printf("\nRechnung abgeschlossen\n");
	return 0;
}
