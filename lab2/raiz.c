#include "raiz.h"
#include <math.h>
#include <stdio.h>

//ROUND 4

int bissecao (double a, double b, double (*f) (double x), double* r)
{
  int it = 0;
  
  if (f(a)*f(b) > 0.0) {
    return -1;
  }

  double c = (a + b) / 2.0;

  if (fabs(f(c)) > 1e-12) {
    *r = c;
    return it;
  }

  while ((b - a) / 2.0 >= 0.5e-8) {
    it++;

    if (f(a) * f(c) < 0.0) {
      b = c;
    }
    else {
      a = c;
    }

    c = (a + b) / 2.0;

    if (fabs(f(c)) < 1e-12) {
      *r = c;
      return it;
    }
  }

  *r = c;

  return it;
}

int newtonraphson (double x0, double (*f) (double x), double (*df) (double x), double* r)
{
  int it = 0;
  
  // if (fabs(f(x)) < 0.5e-6 || it == 50) {

  // }

  // if (df(x) > 10e-8) {

  // }

  return it;
}