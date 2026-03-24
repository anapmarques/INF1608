#include "raiz.h"
#include <math.h>

int bissecao (double a, double b, double (*f) (double x), double* r)
{
  int it = 0;
  double fa = f(a);
  double fb = f(b);
  
  if (fa * fb > 0.0) {
    return -1;
  }

  double c = (a + b) / 2.0;
  double fc;

  while ((b - a) / 2.0 >= 0.5e-8) {
    fc = f(c);

    if (fabs(fc) < 1e-12) {
      *r = c;
      return it;
    }

    it++;

    if (fa * fc < 0.0) {
      b = c;
      fb = fc;
    }
    else {
      a = c;
      fa = fc;
    }

    c = (a + b) / 2.0;
  }

  *r = c;

  return it;
}

int newtonraphson (double x0, double (*f) (double x), double (*df) (double x), double* r)
{
  int it = 0;

  double xi = x0;

  while (it < 50) {
    double fxi = f(xi);
    double dfxi = df(xi);

    if (fabs(fxi) < 0.5e-6) {
      *r = xi;
      return it;
    }

    if (dfxi < 1e-8) {
      dfxi = 1e-8;
    }

    it++;
    double xi1 = xi - (fxi / dfxi);
    xi = xi1;
  }

  *r = xi;
  return it;
}