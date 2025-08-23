#include <stdio.h>
#include <math.h>

const double EPS = 1e-9;

int sravnenie(double a);
void linear(double a, double b, double c, double* x1, double* x2, int* nRoots);
void quadratick (double a, double b, double c, double* x1, double* x2, int* nRoots);

int main()
{
    printf("ax**2 + bx + c = 0\n");
    printf("vvedite a, b, c\n");

    int nRoots = 0;

    double a = 0, b = 0, c = 0;
    scanf("%lf, %lf, %lf", &a, &b, &c);

    double x1 = 0, x2 = 0;

    quadratick(a, b,  c, &x1, &x2, &nRoots);
    
    switch (nRoots)
    {
        case -1:
            printf("INFINITY ROOTS");
            break;
        case 0:
            printf("NO ROOTS");
            break;
        case 1:
            printf("ONE ROOT IS %lg", x1);
            break;
        case 2:
            printf("TWO ROOTS: X1 = %lg AND X2 = %lg", x1, x2);
            break;
        default:
            printf("ITS IMPOSSIBLE");
            break;
    }

    return 0;
}



int sravnenie(double a)
{
    if (abs(a) < EPS)
    {
        return -1;
    }

    return 1;
}



void linear(double a, double b, double c, double* x1, double* x2, int* nRoots)
{
    if (sravnenie(b) < 0)
    {
        if (sravnenie(c) < 0)
        {
            *nRoots = -1;
        }
        else
        {
            *nRoots = 0;
        }
    }
    else
    {
        *nRoots = 1;
        *x1 = *x2 = (-c / b);
    }
}



void quadratick (double a, double b, double c, double* x1, double* x2, int* nRoots)
{
    if (sravnenie(a) < 0)
    {
        linear(a, b, c, x1, x2, nRoots);
        return;
    }
    
    double D = b * b - 4 * a * c;
    if (sravnenie(D) < 0)
    {
        *x1 = *x2 = -b / (2 * a);
        *nRoots = 1;
    }
    else if (D < 0)
    {
        *nRoots = 0;
    }
    else
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        *nRoots = 2;
    }
    
}