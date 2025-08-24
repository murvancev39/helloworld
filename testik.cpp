#include <stdio.h>
#include "header.h"
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