#include "interp.h"
#include <math.h>
#define PI 3.141592653589793

void regular (int n, double a, double b, double* xi) {
  double h = (b - a) / (n - 1);

  for (int i = 0; i < n - 1; i++) {
    xi[i] = a + i * h;
  }

  xi[n - 1] = b;
}

void chebyshev (int n, double a, double b, double* xi) {
  double beta = 1.0;

  for (int i = 0; i < n; i++) {
    xi[i] = ((b - a) / 2.0) * cos((beta * PI) / (2.0 * n)) + ((a + b) / 2.0);
    beta += 2.0;
  }
}

void coeficientes (int n, double* xi, double (*f) (double), double* bi) {
  for (int i = 0; i < n; i++) {
    bi[i] = f(xi[i]);
  }

  for (int j = 1; j < n; j++) {
    for (int i = n - 1; i >= j; i--) {
      bi[i] = (bi[i] - bi[i - 1]) / (xi[i] - xi[i - j]);
    }
  }
}

double avalia (int n, double* xi, double* bi, double x) {
  double p = bi[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    p = p * (x - xi[i]) + bi[i];
  }

  return p;
}