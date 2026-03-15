#include "taylor.h"
#include <stdlib.h>

double avalia_taylor (int n, double* c, double x0, double x) {
    double p = 0.0;
    double fat = 1.0;
    double exp = 1.0;

    for (int i = 0; i < n; i++) {
        if (i != 0)  {
            fat *= i;
            exp *= (x - x0);
        }
        p += (c[i] / fat) * (exp);
    }

    return p;
}

double avalia_seno (int n, double x) {
    double c[n];
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            c[i] = 0;
        }
        else{
            if (((i - 1) / 2) % 2 == 0){
                c[i] = 1;
            }
            else {
                c[i] = -1;
            }
        }
    }
    return avalia_taylor(n, c, 0.0, x);
}