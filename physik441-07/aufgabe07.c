/*
 * gcc -Wall -pedantic aufgabe07.c -lm -sdt=c99
 * © Simon Schlepphorst
 */

#include <stdio.h>
#include <stdlib.h>

int index_matrix (int zeile, int spalte, int *dim_A)
{
	return spalte * dim_A[0] + zeile;
}

void matrix_vector_mult (double *A, int *dim_A, double *b, double *c)
{
	for (int i = 0; i < dim_A[0]; i++){
		c[i] = 0;
		for (int j = 0; j < dim_A[1]; j++){
			c[i] += A[index_matrix(i, j, dim_A)] * b[j];
		}
	}
}

void l_substitution (double *L, int *dim_L, double *b, double *x)
{
	double tmp;
	for (int i = 0; i < dim_L[0]; i++){
		x[i] = 0;
		tmp = 0;
		for (int j = 0; j < i; j++){
			tmp += L[index_matrix(i, j, dim_L)] * x[j];
		}
		x[i] = b[i] - tmp;
	}
}

void r_substitution (double *R, int *dim_R, double *b, double *x)
{
	double tmp;
	for (int i = dim_R[0] - 1; i >= 0; i--){
		x[i] = 0;
		tmp = 0;
		for (int j = dim_R[1] - 1; j > i; j--){
			tmp += R[index_matrix(i, j, dim_R)] * x[j];
		}
		x[i] = (b[i] - tmp) / R[index_matrix(i, i, dim_R)];
	}
}

void lr_zerlegung (double *A, int *dim_A, double *s)
{
	for (int i = 0; i < dim_A[0]; i++){
		/* TODO Pivotisierung */
		for (int j = 0; j < dim_A[0]; j++){
			for (int k = 0; k < dim_A[0]; k++){
				A[index_matrix(s[i], j, dim_A)] -= A[index_matrix(s[i], k, dim_A)] * A[index_matrix(s[k], j, dim_A)];
			}
		}
		for (int j = i; j < dim_A[0]; j++){
			for (int k = 0; k < dim_A[0]; k++){
				A[index_matrix(s[j], i, dim_A)] -= A[index_matrix(s[j], k, dim_A)] * A[index_matrix(s[k], i, dim_A)];
			}
			A[index_matrix(s[j], i, dim_A)] /= A[index_matrix(s[i], i, dim_A)];
		}
	}
}

int main() {
	double A[16] = { 4, 3, 2, 1, 3, 4, 3, 2, 2, 3, 4, 3, 1, 2, 3, 4};
	int dim_A[2] = {4, 4};
	double b[4] = { 1, 2, 3, 4};
	double c[4];

	/* Test der Matrix-Vector-Multiplikation */
	matrix_vector_mult (A, dim_A, b, c);
	
	/* Test der Rückwärtssubstitution */
	double R[16] = {-1, 0, 0, 0, 2, -2, 0, 0, -10, 4, 3, 0, 7, -5, 9, 1};
	r_substitution(R, dim_A, b, c);

	/* Test der Vorwärtssubstitution */
	l_substitution(A, dim_A, b, c);

	printf("c = (");
	for (int i = 0; i < 3; i++)
		printf("%g, ", c[i]);
	printf("%g)\n", c[3]);

	int dim_B[2] = {3, 3};
	double B[9] = {2, 6, 8, 3, 10, 14, 5, 17, 28};
	double s[4] = {0, 1, 2, 3};
	lr_zerlegung(B, dim_B, s);
	for (int i = 0; i < dim_B[0]; i++){
		for (int j = 0; j < dim_B[1]; j++){
			printf("%g\t", B[index_matrix(i, j, dim_B)]);
		}
		printf("\n");
	}

	return 0;
}
