#include "derivadaintegral.h"
#include <math.h>

double derivada (double (*f) (double), double x, double h) {
    return (f(x+h) - f(x-h)) / (2*h);
}

double simpson (double (*f) (double), double a, double b, int n) {

    double h = (b - a) / n;
    double soma = 0.0;
    double x, xm;
    
    for (int i = 0; i < n; i++) {
        x = a + i * h;
        xm = x + h / 2.0;
        
        soma += (h / 6.0) * (f(x) + (4.0 * f(xm)) + f(x + h));
    }
    
    return soma;
}

double simpsonadaptativo (double (*f) (double), double a, double b, double tol) {
    double c = (a + b) / 2.0;
    
    double Sab = simpson(f, a, b, 1);
    double Sac = simpson(f, a, c, 1);
    double Scb = simpson(f, c, b, 1);
    
    double delta = Sab - (Sac + Scb);
    
    if (fabs(delta) < (15.0*tol)) {
        return Sac + Scb - (delta/15.0);
    }
    else return simpsonadaptativo(f, a, c, tol/2.0) + simpsonadaptativo(f, c, b, tol/2.0);
}
