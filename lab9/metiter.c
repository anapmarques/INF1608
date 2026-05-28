#include "metiter.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int gaussseidel (int n, double** A, double* b, double* x, double tol) {
    int iter = 0;
    double norma;
    do {
        for (int i = 0; i < n; i++) {
            double soma = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    soma += A[i][j] * x[j];
                }
            }
            if(A[i][i] == 0.0) break;
            x[i] = (b[i] - soma) / A[i][i];
        }
        norma = 0.0;
        for (int i = 0; i < n; i++) {
            double ri = b[i];
            for (int j = 0; j < n; j++) {
                ri -= A[i][j] * x[j];
            }
            norma += ri * ri;
        }
        norma = sqrt(norma);
        iter++;
    } while (norma > tol);
    return iter;
}

int sor_gaussseidel (int n, double** A, double* b, double* x, double tol, double w) {
    int iter = 0;
    double norma;
    do {
        for (int i = 0; i < n; i++) {
            double soma = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    soma += A[i][j] * x[j];
                }
            }
            if(A[i][i] == 0.0) break;
            double x_gs = (b[i] - soma) / A[i][i];
            x[i] = (1.0 - w) * x[i] + w * x_gs;
        }
        norma = 0.0;
        for (int i = 0; i < n; i++) {
            double ri = b[i];
            for (int j = 0; j < n; j++) {
                ri -= A[i][j] * x[j];
            }
            norma += ri * ri;
        }
        norma = sqrt(norma);
        iter++;
    } while (norma > tol);
    return iter;
}