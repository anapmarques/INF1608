#include "vetor.h"
#include "matriz.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  /* Exemplo de construcao de vetor dinamico */
  double* v = vet_cria(2);
  v[0] = 1.0;
  v[1] = 2.0;

  double* u = vet_cria(3);
  u[0] = -3.0;
  u[1] =  4.0;
  u[2] =  7.0;

  /* Exemplo de construcao de vetor estatico */
  double w1[] = {  1.0,  2.0,   4.0,  -3.0 };
  double w2[] = {  5.0,  2.0,  -1.0,  -2.0 };
  double w3[] = { 5.02, 1.99, -1.01, -2.01 };

  /* Imprime vetores */
  printf("Vetor v: ");
  vet_imprime(2,v);
  printf("Vetor u: ");
  vet_imprime(3,u);
  printf("Vetor w1: ");
  vet_imprime(4,w1);
  printf("Vetor w2: ");
  vet_imprime(4,w2);
  printf("Vetor w3: ");
  vet_imprime(4,w3);

  printf("vet_escalar w1*w2: %f\n", vet_escalar(4, w1, w2));

  printf("vet_norma2 w1: %f\n", vet_norma2(4, w1));
  printf("vet_norma2 w2: %f\n", vet_norma2(4, w2));

  printf("vet_iguais w1 == w2 (tol 0.1): %d\n",  vet_iguais(4, w1, w2, 0.1));
  printf("vet_iguais w2 == w2 (tol 0.1): %d\n",  vet_iguais(4, w2, w2, 0.1));
  printf("vet_iguais w2 == w3 (tol 0.1): %d\n",  vet_iguais(4, w2, w3, 0.1));
  printf("vet_iguais w2 == w3 (tol 0.01): %d\n", vet_iguais(4, w2, w3, 0.01));

  /* Exemplo de construcao de matriz dinamica */
  double** A = mat_cria(3,2);
  A[0][0] = 1.0;
  A[0][1] = 2.0;
  A[1][0] = 3.0;
  A[1][1] = 4.0;
  A[2][0] = 5.0;
  A[2][1] = 6.0;

  /* Exemplo de construcao de matriz estatica no formato ponteiro para ponteiro */
  double linha1[] = {1.0,2.0};
  double linha2[] = {3.0,4.0};
  double linha3[] = {5.0,6.0};
  double* B[] = {linha1,linha2,linha3};

  /* Imprime matrizes (sao iguais em conteudo) */
  printf("Matriz A:\n");
  mat_imprime(3,2,A);
  printf("Matriz B:\n");
  mat_imprime(3,2,B);

  double** At = mat_cria(2,3);
  mat_transposta(3,2,A,At);
  printf("Matriz A transposta:\n");
  mat_imprime(2,3,At);

  double** Att = mat_cria(3,2);
  mat_transposta(2,3,At,Att);
  printf("Matriz A transposta transposta:\n");
  mat_imprime(3,2,Att);

  double* Av = vet_cria(3);
  double* Atu = vet_cria(2);
  mat_multv(3, 2, A, v, Av);
  printf("Vetor Av: ");
  vet_imprime(3,Av);

  mat_multv(2, 3, At, u, Atu);
  printf("Vetor Atu: ");
  vet_imprime(2,Atu);

  double** AAt = mat_cria(3,3);
  mat_multm(3, 2, 3, A, At, AAt);
  printf("Matriz A*At:\n");
  mat_imprime(3,3,AAt);

  double** AtA = mat_cria(2,2);
  mat_multm(2, 3, 2, At, A, AtA);
  printf("Matriz At*A:\n");
  mat_imprime(2,2,AtA);

  /* Apenas objetos dinâmicos podem ser liberados */
  vet_libera(v);
  vet_libera(u);
  vet_libera(Av);
  vet_libera(Atu);
  mat_libera(3,A);
  mat_libera(2,At);
  mat_libera(2,Att);
  mat_libera(3,AAt);
  mat_libera(2,AtA);

  return 0; 
} 
