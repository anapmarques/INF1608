#include "ode.h"
#include <math.h>

double RungeKuttaPasso (double t, double h, double y, double (*f) (double t, double y))
{
  double k1 = h * f(t, y);
  double k2 = h * f(t + h/2.0, y + k1/2.0);
  double k3 = h * f(t + h/2.0, y + k2/2.0);
  double k4 = h * f(t + h, y + k3);
  return y + (k1 + 2.0*k2 + 2.0*k3 + k4) / 6.0;
}

double RungeKutta (double t0, double t1, int n, double y0, double (*f) (double t, double y))
{
  double h = (t1 - t0) / n;
  double y = y0;
  double t = t0;
  for (int i = 0; i < n; i++) {
    y = RungeKuttaPasso(t, h, y, f);
    t += h;
  }
  return y;
}

double RungeKuttaAdaptativo (double t0, double t1, double y0, double (*f) (double t, double y), double tol)
{
  double t = t0;
  double y = y0;
  double h = 1e-7;

  while (t < t1) {
    if (t + h > t1) {
      h = t1 - t;
    }

    double y1 = RungeKuttaPasso(t, h, y, f);
    double y2_half = RungeKuttaPasso(t, h/2.0, y, f);
    double y2 = RungeKuttaPasso(t + h/2.0, h/2.0, y2_half, f);

    double delta = (y2 - y1) / 15.0;
    
    if (fabs(delta) == 0.0) { 
        t += h;
        y = y2 + delta;
        h = 1.2 * h; 
        continue;
    }

    double factor = pow(tol / fabs(delta), 0.2);

    if (factor >= 1.0) {
      t += h;
      y = y2 + delta;
      h = fmin(1.2, factor) * h;
    } else {
      h = 0.8 * factor * h;
    }
  }
  return y;
}