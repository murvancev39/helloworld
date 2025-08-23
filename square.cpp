#include <stdio.h>
#include <math.h>

const double EPS = 1e-9;

int sravnenie (double a);
int linear (double a, double b, double c, double* x1, double* x2);
int quadratick (double a, double b, double c, double* x1, double* x2);

int main ()
{
    printf ("ax**2 + bx + c = 0\n");
    printf ("vvedite a, b, c\n");

    int nRoots = 0;

    double a = 0, b = 0, c = 0;
    scanf ("%lf, %lf, %lf", &a, &b, &c);

    double x1 = 0, x2 = 0;

    nRoots = quadratick (a, b,  c, &x1, &x2);
    
    switch (nRoots)
    {
        case -1:
            printf ("INFINITY ROOTS");
            break;
        case 0:
            printf ("NO ROOTS");
            break;
        case 1:
            printf ("ONE ROOT IS %lg", x1);
            break;
        case 2:
            printf ("TWO ROOTS: X1 = %lg AND X2 = %lg", x1, x2);
            break;
        default:
            printf ("ITS IMPOSSIBLE");
            break;
    }

    return 0;
}

int sravnenie (double a)
{
    if (abs (a) < EPS)
    {
        return -1;
    }

    return 1;
}

int linear (double a, double b, double c, double* x1, double* x2)
{
    if (sravnenie (b) < 0)
    {
        if (sravnenie (c) < 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        *x1 = *x2 = (-c / b);
        return 1;
    }
}

int quadratick (double a, double b, double c, double* x1, double* x2)
{
    if (sravnenie (a) < 0)
    {
        return linear (a, b, c, x1, x2);
    }
    if (sravnenie (c) < 0)
    {
        *x1 = 0;
        *x2 = -b/a;
        return 2;
    }

    double D = b * b - 4 * a * c;

    if (sravnenie (D) < 0)
    {
        *x1 = *x2 = -b / (2 * a);
        return 1;
    }
    else if (D < 0)
    {
        return 0;
    }
    else
    {
        double sqrt_D = sqrt (D);
        *x1 = (-b + sqrt_D) / (2 * a);
        *x2 = (-b - sqrt_D) / (2 * a);
        return 2;
    }
    
}