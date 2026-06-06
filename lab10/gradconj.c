#include "gradconj.h"
#include "matriz.h"
#include "vetor.h"

int gradconj(int n, double** A, double* b, double* x, double tol)
{
    double *r = vet_cria(n);
    double *d = vet_cria(n);
    double *Ad = vet_cria(n);

    for (int i = 0; i < n; i++)
        Ad[i] = 0.0;

    mat_multv(n, n, A, x, Ad);

    for (int i = 0; i < n; i++) {
        r[i] = b[i] - Ad[i];
        d[i] = r[i];
    }

    int k;

    for (k = 0; k < n; k++) {

        if (vet_norma2(n, r) < tol)
            break;

        for (int i = 0; i < n; i++)
            Ad[i] = 0.0;

        mat_multv(n, n, A, d, Ad);

        double rr = vet_escalar(n, r, r);
        double alpha = rr / vet_escalar(n, d, Ad);

        for (int i = 0; i < n; i++)
            x[i] += alpha * d[i];

        for (int i = 0; i < n; i++)
            r[i] -= alpha * Ad[i];

        double rr_new = vet_escalar(n, r, r);
        double beta = rr_new / rr;

        for (int i = 0; i < n; i++)
            d[i] = r[i] + beta * d[i];
    }

    vet_libera(r);
    vet_libera(d);
    vet_libera(Ad);

    return k;
}

int gradconj_jacobi(int n, double** A, double* b, double* x, double tol)
{
    double *r = vet_cria(n);
    double *z = vet_cria(n);
    double *d = vet_cria(n);
    double *Ad = vet_cria(n);

    for (int i = 0; i < n; i++)
        Ad[i] = 0.0;

    mat_multv(n, n, A, x, Ad);

    for (int i = 0; i < n; i++) {
        r[i] = b[i] - Ad[i];
        z[i] = r[i] / A[i][i];
        d[i] = z[i];
    }

    int k;

    for (k = 0; k < n; k++) {

        if (vet_norma2(n, r) < tol)
            break;

        for (int i = 0; i < n; i++)
            Ad[i] = 0.0;

        mat_multv(n, n, A, d, Ad);

        double rtz = vet_escalar(n, r, z);
        double alpha = rtz / vet_escalar(n, d, Ad);

        for (int i = 0; i < n; i++)
            x[i] += alpha * d[i];

        for (int i = 0; i < n; i++)
            r[i] -= alpha * Ad[i];

        for (int i = 0; i < n; i++)
            z[i] = r[i] / A[i][i];

        double rtz_new = vet_escalar(n, r, z);
        double beta = rtz_new / rtz;

        for (int i = 0; i < n; i++)
            d[i] = z[i] + beta * d[i];
    }

    vet_libera(r);
    vet_libera(z);
    vet_libera(d);
    vet_libera(Ad);

    return k;
}
