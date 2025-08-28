#ifndef HEADER_H
#define HEADER_H
enum NROOTS
{
    Infinity = -1,
    Zero,
    One,
    Two,
};

void UniTests(void);
int Test(double a, double b, double c, double x1Ref, double x2Ref, enum NROOTS nRootsRef);
int is_notzero (double a);
void vivod_otveta (enum NROOTS nRoots, double x1, double x2);
enum NROOTS linear (double b, double c, double* x1, double* x2);
enum NROOTS quadratick (double a, double b, double c, double* x1, double* x2);
void clear ();
int NAN_TEST (double x);
#endif