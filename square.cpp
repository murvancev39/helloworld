#include <stdio.h>
#include <math.h>
#include "header.h"

const double EPS = 1e-9;

int main()
{
    
    printf ("MEOOOOW\n"
           "IF YOU WANT TO DO TESTS , PRINT: 1\n"
           "IF YOU WANT SOLVE THE EQUATION , PRINT: 0\n");

    int Fortnite = 1;
    scanf ("%d", &Fortnite);

    if (Fortnite)
    {
        UniTests ();
        return 0;
    }

    double a = NAN, b = NAN, c = NAN;

    printf ("ax**2 + bx + c = 0\n"
           "VVEDITE A\n");
    scanf ("%lf", &a);
    
    printf ("VVEDITE B\n");
    scanf ("%lf", &b);
    
    printf ("VVEDITE C\n");
    scanf ("%lf", &c);

    printf ("a = %lf, b = %lf, c = %lf\n", a, b, c);

    double x1 = NAN, x2 = NAN;

    enum NROOTS nRoots = quadratick (a, b, c, &x1, &x2);

    vivod_otveta (nRoots, x1, x2);

    return 0;
}

int is_notzero (double a)
{
    return (abs (a) > EPS);
}

enum NROOTS linear (double b, double c, double *x1, double *x2)
{
    if (is_notzero (b))
    {
        *x1 = *x2 = (-c / b);
        return One;
    }

    if (!is_notzero (c))
    {
        return Infinity;
    }

    return Zero;
}

enum NROOTS quadratick (double a, double b, double c, double *x1, double *x2)
{
    if (!is_notzero (a))
    {
        *x1 = *x2 = 0;
        return linear(b, c, x1, x2);
    }

    if (!is_notzero (c))
    {
        *x1 = 0;
        *x2 = -b / a;
        return Two;
    }

    double D = b * b - 4 * a * c;

    if (!is_notzero (D))
    {
        *x1 = *x2 = -b / (2 * a);
        return One;
    }
    else if (D < 0)
    {
        *x1 = *x2 = 0;
        return Zero;
    }
    else
    {
        double sqrt_D = sqrt (D);
        *x1 = (-b + sqrt_D) / (2 * a);
        *x2 = (-b - sqrt_D) / (2 * a);
        return Two;
    }
}

void vivod_otveta (enum NROOTS nRoots, double x1, double x2)
{
    if ( isnan(x1) || isnan(x2) )
    {
        printf ("PLS RESTART THE PROGRAM AND ENTER A NUMBER");
        printf("x1 = %lg , x2 = %lg", x1, x2);
        return;
    }
    switch (nRoots)
    {
    case Infinity:
        printf ("INFINITY ROOTS");
        break;
    case Zero:
        printf ("NO ROOTS");
        break;
    case One:
        printf ("ONE ROOT IS %lg", x1);
        break;
    case Two:
        printf ("TWO ROOTS: X1 = %lg AND X2 = %lg", x1, x2);
        break;
    default:
        printf ("ITS IMPOSSIBLE");
        break;
    }
    printf ("\nCOMMIT GITHUB");
}
