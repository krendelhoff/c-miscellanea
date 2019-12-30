#include <stdio.h>
#include "library.h"
#define MAXLINE 1000

int main(void) 
{
    char line[MAXLINE];
    int len;
    double sum = 0.0;
    while((len = getLine(line, MAXLINE)) > 0)
        printf("%d\n", calc(line));
    return 0;
}