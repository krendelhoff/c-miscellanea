#include <stdio.h>
#include "library.h"
#define MAXLINE 1000
int main(void)
{
    int len;
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        escape(line);
        printf("%s\n", line);
    }
    return 0;
}