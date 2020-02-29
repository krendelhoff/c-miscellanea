#include <stdio.h>
#include <math.h>
#include "library.h"
#define MAXLINE 1000
int main(void)
{
    char line[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
        printf("\n%d\n\n", hTol(line));
    return 0;
}
