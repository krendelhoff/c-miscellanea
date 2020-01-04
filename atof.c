#include <stdio.h>
#include "library.h"
#define MAXLINE 1000
int main(void)
{
    int len;
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (atof(line) == (int)atof(line))
            printf("%d\n", (int)atof(line));
        else
            printf("%lf\n", atof(line));
        break;
    }
    return 0;
}
