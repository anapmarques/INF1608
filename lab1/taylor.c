#include "taylor.h"
#include <stdlib.h>

double avalia_taylor (int n, double* c, double x0, double x) {
    double p = 0;

    for (int i = 0; i < n; i++) {
        p += (c[i] / i * (i - 1)) * ((x - x0) ^ i);
    }

    return p;
}