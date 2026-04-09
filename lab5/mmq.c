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
  
  printf("solução:\n");
  for (int i = 0; i < n; i++){
      printf("x[%d] = %lf\n", i, x[i]);
  }
  
  double* Ax = vet_cria(m);
  mat_multv(m, n, A, x, Ax);
  
  printf("Ax:\n");
  double* r = vet_cria(m);
  for (int i = 0; i < m; i++) {
      r[i] = b[i] - Ax[i];
      printf("Ax[%d] = %lf\n", i, Ax[i]);
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
  return -1.0; // Completar
}

double ajuste_exponencial_exp (int n, double* px, double* py, double* a, double* b)
{
  return -1.0; // Completar
}
