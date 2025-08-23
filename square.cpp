#include <stdio.h>
#include <math.h>

const double EPS = 1e-9;

int sravnenie(double a);
void linear(double a, double b, double c, double* x1, double* x2);
void quadratick (double a, double b, double c, double* x1, double* x2);

int main()
{
    printf("ax**2 + bx + c = 0\n");
    printf("vvedite a, b, c\n");

    double a = 0, b = 0, c = 0;
    scanf("%lf, %lf, %lf", &a, &b, &c);

    double x1 = 0, x2 = 0;

    quadratick(a, b,  c, &x1, &x2);
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



void linear(double a, double b, double c, double* x1, double* x2)
{
    if (sravnenie(b) < 0)
    {
        if (sravnenie(c) < 0)
        {
            printf("beskonechno resheniy");
        }
        else
        {
            printf("net resheniy");
        }
    }
    else
    {
        printf("ti daun?");
        *x1 = *x2 = (-c / b); // FIXME
        printf(" eto ne qvadratnoye uravnenie , a lineynoye i imeet odno resheniye\n");
        printf("x = %lf", *x1);
    }
}



void quadratick (double a, double b, double c, double* x1, double* x2)
{
    if (sravnenie(a) < 0)
    {
        linear(a, b, c, x1, x2);
        return;
    }
    
    double D = b * b - 4 * a * c;
    if (sravnenie(D) < 0)
    {
        *x1 = *x2 = -b / (2 * a);
        printf("x1 = x2 = %lf", *x1);
    }
    else if (D < 0)
    {
        printf("no solution");
    }
    else
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        printf("x1 = %lf, x2 = %lf", *x1, *x2);
    }
    
}