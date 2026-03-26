#include "sistlinear.h"
#include <math.h>
#include <stdio.h>

void gauss (int n, double** a, double* b, double* x) {
    double f;
    for (int j = 0; j < n - 1; j++) {
        int p = j;
        for (int k = j + 1; k < n; k++) {
            if (fabs(a[k][j]) > fabs(a[p][j])){
                p = k;
            }
        }
        for (int k = j; k < n; k++) {
            double ajk = a[j][k];
            a[j][k] = a[p][k];
            a[p][k] = ajk;
        }
        double bj = b[j];
        b[j] = b[p];
        b[p] = bj;
      for (int i = j + 1; i < n; i++) {
          f = a[i][j] / a[j][j];
      
          for (int k = j + 1; k < n; k++) {
              a[i][k] = a[i][k] - (a[j][k] * f);
          }
          
          b[i] = b[i] - (b[j] * f);
      }
    }
    
    double s;
    for (int i = n - 1; i >= 0; i--) {
        s = 0;
        for (int j = i + 1; j < n; j++) {
            s = s + a[i][j] * x[j];
        }
        x[i] = (b[i] - s) / a[i][i];
    }
}