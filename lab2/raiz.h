#ifndef RAIZ_BISSECAO_H
#define RAIZ_BISSECAO_H

int bissecao (double a, double b, double (*f) (double x), double* r);
int newtonraphson (double x0, double (*f) (double x), double (*df) (double x), double* r);

#endif