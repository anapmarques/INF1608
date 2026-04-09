#include "mmq.h"
#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

int main (void)
{
  {
    int m = 5;
    int n = 3;
    double** A = mat_cria(5,3);
    A[0][0] =  3; A[0][1] = -1; A[0][2] =  2;
    A[1][0] =  4; A[1][1] =  1; A[1][2] =  0;
    A[2][0] = -3; A[2][1] =  2; A[2][2] =  1;
    A[3][0] =  1; A[3][1] =  1; A[3][2] =  5;
    A[4][0] = -2; A[4][1] =  0; A[4][2] =  3;
    double b[] = { 10, 10, -5, 15, 0};
    double x[3];
    
    double error = mmq(m, n, A, b, x);
    
    printf("Erro: %lf\n", error);
	
    mat_libera(5, A);
  }
  printf("-------------------------\n");
  {
    double** A = mat_cria(5,4);
    A[0][0] =  4; A[0][1] = 2; A[0][2] =  3; A[0][3] =  0;
    A[1][0] = -2; A[1][1] = 3; A[1][2] = -1; A[1][3] =  1;
    A[2][0] =  1; A[2][1] = 3; A[2][2] = -4; A[2][3] =  2;
    A[3][0] =  1; A[3][1] = 0; A[3][2] =  1; A[3][3] = -1;
    A[4][0] =  3; A[4][1] = 1; A[4][2] =  3; A[4][3] = -2;
    double b[] = { 10, 0, 2, 0, 5};
    double x[4];
    
    int m = 5;
    int n = 4;
    
    double error = mmq(m, n, A, b, x);
    
    printf("Erro: %lf\n", error);

    mat_libera(5, A);
  }
  printf("-------------------------\n");
  {
    double px[] = {-1,0,1,2};
    double py[] = {1,0,0,-2};
    double a, b, c, d;
    
    printf("parabola:\n");
	double error = ajuste_parabola(4, px, py, &a, &b, &c);
	printf("Erro: %lf\n", error);
	printf("a = %.2lf b = %.2lf c= %.2lf\n", a, b, c);
	
	
	  // TODO: chamar ajuste de cubica
  }
  printf("-------------------------\n");
  {
    double px[] = {0,1,2,5};
    double py[] = {0,3,3,6};
    double a, b, c, d;
	  // TODO: chamar ajuste de parabola
	  // TODO: chamar ajuste de cubica
  }
  printf("-------------------------\n");
  {
    double px[] = {1,3,4,6};
    double py[] = {2,2,1,3};
    double a, b, c, d;
	  // TODO: chamar ajuste de parabola
	  // TODO: chamar ajuste de cubica
  }
  printf("-------------------------\n");
  {
    double px[] = { 1950,  1955,  1960,   1965,   1970,   1975,   1980};
    double py[] = {53.05, 73.04, 98.31, 139.78, 193.48, 260.20, 320.39};
    double a, b;
	  // TODO: chamar ajuste exponencial
  }
  printf("-------------------------\n");
  {
    double px[] = { 0,  5, 10,   15,   20,   25,   30};
    double py[] = {53.05, 73.04, 98.31, 139.78, 193.48, 260.20, 320.39};
    double a, b;
	  // TODO: chamar ajuste exponencial
  }
   	
  return 0; 
}

