// 3.c -- a program in which uses two function in one file
#include <stdio.h>
void butler(void); // prototype of the function in standart iso/ansi C
int main(void)
{
    printf(" i'm calling dvor.\n");
    butler();
    printf("yes , bring me some tea.\n");
    return 0;
}
void butler(void) // start determine of the function
{
    printf( "you , sir?\n");
}