#include "libft.h"

void iswap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void cswap(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void dswap(double *a, double *b)
{
    double tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
