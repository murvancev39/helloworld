#include <stdio.h>
#include <math.h>

const double EPS = 1e-9;

void UniTests(void);
int zero_notzero (double a);
void vivod_otveta (int nRoots, double x1, double x2);
int linear (double a, double b, double c, double* x1, double* x2);
int quadratick (double a, double b, double c, double* x1, double* x2);
int Test(double a, double b, double c, double x1Ref, double x2Ref, int nRootsRef);

int main ()
{
    printf("IF YOU WANT TO DO TESTS , PRINT: 1\n");
    printf("IF YOU WANT SOLVE THE EQUATION , PRINT: 0\n");

    int Fortnite = 1;
    scanf("%d", &Fortnite);
    
    if (Fortnite)
    {
        UniTests();
    }
    else
    {
        printf ("ax**2 + bx + c = 0\n");
        printf ("VVEDITE a, b, c\n");

        int nRoots = 0;

        double a = 0, b = 0, c = 0;
        scanf ("%lf, %lf, %lf", &a, &b, &c);

        double x1 = 0, x2 = 0;

        nRoots = quadratick (a, b,  c, &x1, &x2);
        
        vivod_otveta (nRoots, x1, x2);
    }
    return 0;
}

int zero_notzero (double a)
{
    if (abs (a) < EPS)
    {
        return 0;
    }

    return 1;
}

int linear (double a, double b, double c, double* x1, double* x2)
{
    if (zero_notzero (b))
    {
        *x1 = *x2 = (-c / b);
        return 1;
    }
    else
    {
        if (!zero_notzero (c))
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int quadratick (double a, double b, double c, double* x1, double* x2)
{
    if (!zero_notzero (a))
    {
        return linear (a, b, c, x1, x2);
    }
    if (!zero_notzero (c))
    {
        *x1 = 0;
        *x2 = -b/a;
        return 2;
    }

    double D = b * b - 4 * a * c;

    if (!zero_notzero (D))
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

void UniTests(void)
{
    int failed = 0;
    int n = 0;

    failed += Test(1, 2, 1, -1.0, -1.0, 1); n +=1;

    if (failed == n)
    {
        printf("All ok");
    }
    else
    {
        printf("Not ok");
    }
}

int Test(double a, double b, double c, double x1Ref, double x2Ref, int nRootsRef)
{
    double x1 = 0, x2 = 0;
    int nRoots = quadratick (a, b,  c, &x1, &x2);

    if ( !( ( (x1 == x1Ref && x2 == x2Ref) || (x1 == x2Ref && x2 == x1Ref) ) && nRoots==nRootsRef) )
    {
        printf("ERROOOR \nX1, X2: %LF, %LF SHOULD BE X1, X2: %LF, %LF\n", x1, x2, x1Ref, x2Ref);
        printf("nRoots = %d , SHOLD BE nRoots = %d\n", nRoots, nRootsRef);
        return 0;
    }
    return 1;
}