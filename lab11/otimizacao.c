#include "otimizacao.h"
#include <math.h>

int msa (double a, double b, double (*f) (double x), double tol, double *xmin) {
    const double g = (sqrt(5.0) - 1.0) / 2.0;

    double x1 = a + (1.0 - g) * (b - a);
    double x2 = a + g * (b - a);

    double f1 = f(x1);
    double f2 = f(x2);

    int iter;

    for (iter = 0; iter < 50; iter++) {
        if ((b - a) / 2.0 <= tol)
            break;

        if (f1 <= f2) {
            b = x2;

            x2 = x1;
            f2 = f1;

            x1 = a + (1.0 - g) * (b - a);
            f1 = f(x1);
        }
        else {
            a = x1;

            x1 = x2;
            f1 = f2;

            x2 = a + g * (b - a);
            f2 = f(x2);
        }
    }

    *xmin = (a + b) / 2.0;

    return iter;
}

int mips(double r, double delta, double (*f) (double), double tol, double *xmin) {
    double s = r - delta;
    double t = r + delta;

    double fr = f(r);
    double fs = f(s);
    double ft = f(t);

    for (int iter = 0; iter < 50; iter++) {
        double den = 2.0 * ((s - r) * (ft - fs) - (fs - fr) * (t - s));

        double x;

        if (fabs(den) < 1e-10) {
            x = (r + s + t) / 3.0;
        }
        else {
            x = (r + s) / 2.0 - ((fs - fr) * (t - r) * (t - s)) / den;
        }
        
        if (iter >= 3) {
            if (fabs(fs - ft) <= tol) {
                *xmin = (s + t) / 2.0;
                return iter;
            }
        }
        
        double fx = f(x);

        r = s;
        fr = fs;

        s = t;
        fs = ft;

        t = x;
        ft = fx;
    }

    return 0;
}