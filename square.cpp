#include <stdio.h>
#include <math.h>
#include "header.h"
#include "testik.cpp"
const double EPS = 1e-9;

int main ()
{
    printf("IF YOU WANT TO DO TESTS , PRINT: 1\n"
           "IF YOU WANT SOLVE THE EQUATION , PRINT: 0\n");

    int Fortnite = 1;
    scanf("%d", &Fortnite);
    
    if (Fortnite)
    {
        UniTests();
    }
    else
    {
        printf ("ax**2 + bx + c = 0\n"
                "VVEDITE a, b, c\n");

        double a = 0, b = 0, c = 0;
        scanf ("%lf, %lf, %lf", &a, &b, &c);
                
        double x1 = 0, x2 = 0;
                
        int nRoots = quadratick (a, b,  c, &x1, &x2);
        
        vivod_otveta (nRoots, x1, x2);
    }
    return 0;
}

int is_notzero (double a) 
{
    return (abs (a) > EPS);
}

enum NROOTS linear (double a, double b, double c, double* x1, double* x2)
{
    if (is_notzero (b))
    {
        *x1 = *x2 = (-c / b);
        return One;
    }
    else
    {
        if (!is_notzero (c))
        {
            return Infinity;
        }
        else
        {
            return Zero;
        }
    }
}

enum NROOTS quadratick (double a, double b, double c, double* x1, double* x2)
{
    if (!is_notzero (a))
    {
        return linear (a, b, c, x1, x2);
    }
    if (!is_notzero (c))
    {
        *x1 = 0;
        *x2 = -b/a;
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

void vivod_otveta (int nRoots, double x1, double x2)
{
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
}
