#include <stdio.h>
#include "library.h"
#define MAXLINE 1000
int main(void)
{
    char line[MAXLINE], grep[] = "mel";
    int len, found = 0, i = 0, sum = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        printf("%d\n", strindexl(line, grep));
        if (strindexf(line, grep) >= 0)
        {
            found++;
            sum++;
        }
        i++;
        if (!(i % 3))
        {
            printf("In there 3 strings: %d\nSum: %d\n", found, sum);
            found = 0;
        }
    }
    return 0;
}