#include <stdio.h>
#include "library.h"
int main(void)
{
    char line[1000];
    for (int i = 2; i <= 36; i++)
    {
        itob(line, 40950, i);
        printf("%d:%s\n", i, line);
    }
    putchar('\n');
    return 0;
}