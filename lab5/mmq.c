#include "mmq.h"
#include "matriz.h"
#include "sistlinear.h"
#include "vetor.h"
#include <stdio.h>
#include <math.h>

double mmq (int m, int n, double** A, double* b, double* x)
{
  double** At = mat_cria(n, m);
  mat_transposta(m, n, A, At);
  
  double** AtA = mat_cria(n, n);
  mat_multm(n, m, n, At, A, AtA);
  
  double* Atb = vet_cria(n);
  mat_multv(n, m, At, b, Atb);
  
  gauss(n, AtA, Atb, x);
  
  double* Ax = vet_cria(m);
  mat_multv(m, n, A, x, Ax);
  
  double* r = vet_cria(m);
  for (int i = 0; i < m; i++) {
      r[i] = b[i] - Ax[i];
  }
  
  double erro = vet_norma2(m, r);
  
  mat_libera(n, At);
  mat_libera(n, AtA);
  vet_libera(Atb);
  vet_libera(Ax);
  vet_libera(r);
 
  return erro;
}

double ajuste_parabola (int n, double* px, double* py, double* a, double* b, double* c)
{
    double** A = mat_cria(n, 3);

    for (int i = 0; i < n; i++) {
        A[i][0] = 1.0;
        A[i][1] = px[i];
        A[i][2] = px[i] * px[i];
    }

    double* x = vet_cria(3);

    double erro = mmq(n, 3, A, py, x);

    *a = x[0];
    *b = x[1];
    *c = x[2];

    mat_libera(n, A);
    vet_libera(x);

    return erro;
}

double ajuste_cubica (int n, double* px, double* py, double* a, double* b, double* c, double* d)
{
  double** A = mat_cria(n, 4);

  for (int i = 0; i < n; i++) {
      A[i][0] = 1.0;
      A[i][1] = px[i];
      A[i][2] = px[i] * px[i];
      A[i][3] = px[i] * px[i] * px[i];
  }

  double* x = vet_cria(4);

  double erro = mmq(n, 4, A, py, x);

  *a = x[0];
  *b = x[1];
  *c = x[2];
  *d = x[3];

  mat_libera(n, A);
  vet_libera(x);

  return erro;
}

double ajuste_exponencial_exp (int n, double* px, double* py, double* a, double* b)
{
  double** A = mat_cria(n, 2);
  double* Y = vet_cria(n);

  for (int i = 0; i < n; i++) {
    A[i][0] = 1.0;
    A[i][1] = px[i];
    Y[i] = log(py[i]);
  }

  double* x = vet_cria(2);

  double erro = mmq(n, 2, A, Y, x);

  *a = exp(x[0]);
  *b = x[1];

  mat_libera(n, A);
  vet_libera(x);
  vet_libera(Y);

  return erro;
}
