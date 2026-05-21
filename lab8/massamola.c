#include "massamola.h"
#include <math.h>
#include <stdio.h>

const double k = 0.3;
const double r = 200.0;
const double m = 2.0;
const double delta = 0.002;

const double gx = 0.0;
const double gy = 9.8;

const double wx = 10.0;
const double wy = 0.0;

void forca (double t, double x, double y, double* fx, double* fy){
    double fgx = m * gx;
    double fgy = m * gy;
    
    double expo = exp(-t/20.0);
    double fwx = wx * expo;
    double fwy = wy * expo;
    
    double norma = sqrt(x*x + y*y);
    
    double fator = -k * (norma - r) / norma;
    double fkx = fator * x;
    double fky = fator * y;
    
    *fx = fgx + fwx + fkx;
    *fy = fgy + fwy + fky;
}

double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn){
    double fx, fy;
    forca(t, x, y, &fx, &fy);
    
    *xn = x + (1 - delta)*(x - xp) + (pow(h, 2.0))*(fx/m);
    *yn = y + (1 - delta)*(y - yp) + (pow(h, 2.0))*(fy/m);
    
    return t + h;
}

void simula(double x0, double y0, double t, int n, double* x, double* y){
    double h = t / n;

    double tempo = 0.0;

    double xp = x0;
    double yp = y0;

    double xc = x0;
    double yc = y0;

    double xn, yn;

    for (int i = 0; i < n; i++) {

        tempo = evolui(tempo, h, xc, yc, xp, yp, &xn, &yn);

        x[i] = xn;
        y[i] = yn;

        xp = xc;
        yp = yc;

        xc = xn;
        yc = yn;
    }
}
