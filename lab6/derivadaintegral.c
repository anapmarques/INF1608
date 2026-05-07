#include "derivadaintegral.h"
#include <math.h>

double derivada (double (*f) (double), double x, double h) {
    return (f(x+h) - f(x-h)) / (2*h);
}

double simpson (double (*f) (double), double a, double b, int n) {
    double h = (b - a) / n;
    double soma = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;

        if (i % 2 == 0) {
            soma += 2 * f(x);
        } else {
            soma += 4 * f(x);
        }
    }

    return (h / 3.0) * soma;
}

double simpsonadaptativo (double (*f) (double), double a, double b, double tol) {
    double c = (a + b) / 2;
    
    double Sab = simpson(f, a, b, 2);
    double Sac = simpson(f, a, c, 2);
    double Scb = simpson(f, c, b, 2);
    
    double delta = Sab - Sac - Scb;
    
    if (fabs(delta) < (15*tol)) {
        return Sac + Scb - (delta/15);
    }
    else return simpsonadaptativo(f, a, c, tol/2) + simpsonadaptativo(f, c, b, tol/2);
}
