#include "raiz.h"
#include <math.h>
#include <stdio.h>

// contagem de avaliacoes da funcao (N=0 antes de chamar o metodo da bissecao)
int N;

static double f1 (double x)
{
  N++;
  return x*x*x + 2*x*x - 2;
}

static double f2 (double x)
{
  N++;
  return x*x*x*x + x + 1;
}

static double massa (double x)
{
  return -1; // retorne o valor correto
}

void testebissecao (double a, double b, double (*f)(double))
{
  N = 0;
  double x_r;
  int it = bissecao(a, b, f, &x_r);
  if (it < 0) {
    printf("Intervalo sem inversao, it: %d, av: %d\n", it, N);
  }
  else {
    printf("raiz: %.9f, it: %d, av: %d\n", x_r, it, N);
  }
}

static double x2_a (double x)
{
  N++;
  double a = 9.0;
  return -1; // complete com a funcao correta
}

static double d_x2_a (double x)
{
  N++;
  return 2*x;
}

static double x3_a (double x)
{
  N++;
  double a = 64.0;
  return -1; // complete com a funcao correta
}

static double d_x3_a (double x)
{
  N++;
  return 3.0*x*x;
}

void testenewtonraphson (double x0, double (*f)(double), double (*df)(double))
{
  N = 0;
  double x_r = x0;
  int it = newtonraphson(x0, f, df, &x_r);
  printf("raiz: %.10f, it: %d, av: %d\n", x_r, it, N);
}

int main (void)
{
  printf("Testes com bissecao: 'it': iteracoes, 'av': avaliacoes de f(x)\n");
  printf("Q1 de -3 a +3:\n");
  testebissecao(-3, 3, f1);
  printf("Q2 de -3 a +3:\n");
  testebissecao(-3, 3, f2);
  printf("Q1 de -5 a +5:\n");
  testebissecao(-5, 5, f1);
  printf("Q3 de 0 a 150:\n");
  testebissecao(0, 150, massa);
  printf("Q3 de 0 a 250:\n");
  testebissecao(0, 250, massa);
  printf("Q3 de 0 a  50:\n");
  testebissecao(0, 50, massa);

  printf("Testes com newton raphson: 'it': iteracoes, 'av': avaliacoes de f(x) e f'(x)\n");
  printf("sqrt(9), com x0 = 2.0:\n");
  testenewtonraphson(2.0, x2_a, d_x2_a);
  printf("cbrt(64), com x0 = 1.0:\n");
  testenewtonraphson(1.0, x3_a, d_x3_a);
  printf("sqrt(9), com x0 = 10^-10:\n");
  testenewtonraphson(1e-10, x2_a, d_x2_a);
  printf("cbrt(64), com x0 = 10^-10:\n");
  testenewtonraphson(1e-10, x3_a, d_x3_a);

  return 0;
}

