#include <stdio.h>
#include <math.h>

int main()
{
    printf("ax**2 + bx + c = 0\n");
    printf("vvedite a, b, c\n");

    double a = 0, b = 0, c = 0;
    scanf("%lf, %lf, %lf", &a, &b, &c);

    double x1 = 0, x2 = 0;
    double eps = 1e-9;

    if (abs(a) < eps) // TODO const
    {
        printf("ti daun?"); // FIXME
        x1 = x2 = -c/b;
        printf(" eto ne qvadratnoye uravnenie , a lineynoye i imeet odno resheniye\n");
        printf("x = %lf", x1);
    }
    else
    {
        double D = b * b - 4 * a * c;
        if (abs(D) < eps)
        {
            x1 = x2 = -b / (2 * a);
            printf("x1 = x2 = %lf", x1);
        }
        else if (D < -eps)
        {
            printf("no solution");
        }
        else
        {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            printf("x1 = %lf, x2 = %lf", x1, x2);
        }
    }
    return 0;
}