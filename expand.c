#include <stdio.h>
#include "library.h"
#define MAXLINE 1000
int main(void)
{
    char line[MAXLINE], line1[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        expand(line, line1);
        printf("%s", line1);
        break;
    }
    return 0;
}
