#include <stdio.h>
#include "library.h"
#define MAXLINE 1000
int main(void)
{
    char line[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        lower(line);
        printf("\n%s\n", line);
    }
    return 0;
}