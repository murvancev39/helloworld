#include <stdio.h>
#include "header.h"
void UniTests(void)
{
    int failed = 0;
    int n = 0;

    failed += Test(0, 0, 0, 0, 0, Zero); n +=1;
    failed += Test(1, 2, 1, -1.0, -1.0, One); n +=1;
    failed += Test(1e-6, 2e-6, 1e-6, -1.0, -1.0, One); n +=1;
    failed += Test(1, -5, -14, -2, 7, Two); n +=1;
    failed += Test(1e10, -5e10, -1.4e11, -2, 7, Two); n +=1;
    failed += Test(1, 2, 5, 0, 0, Zero); n +=1;
    failed += Test(100, -5397, 5141, 53, 0.97, Two); n +=1;

    if (failed == n)
    {
        printf("All ok");
    }
    else
    {
        printf("Not ok");
    }
}

int Test(double a, double b, double c, double x1Ref, double x2Ref, enum NROOTS nRootsRef)
{
    double x1 = 0, x2 = 0;
    enum NROOTS nRoots = quadratick (a, b,  c, &x1, &x2);

    if ( !( ( (x1 == x1Ref && x2 == x2Ref) || (x1 == x2Ref && x2 == x1Ref) ) && nRoots==nRootsRef) )
    {
        printf("ERROOOR \nX1, X2: %LF, %LF "
               "SHOULD BE X1, X2: %LF, %LF\n", x1, x2, x1Ref, x2Ref);
        printf("nRoots = %d , SHOLD BE nRoots = %d\n", nRoots, nRootsRef);
        return 0;
    }
    return 1;
}