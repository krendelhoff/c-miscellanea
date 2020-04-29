#include "libft.h"
#include <stdio.h>
#define swap(t, x, y) {t tmp; tmp = x; x = y; y = tmp;}

int soska(char s[])
{
    return (0);
}

unsigned hash(const char *word)
{
    return (26 * (word[0] - 'a') + (word[1] - 'a'));
}

int main(void)
{
    double arr[N];
    int i;

    i = 0;
    while (i < 5)
    {
        if (getfloat(&arr[i]))
            i++;
    }
    i = 0;
    while (i < 5)
    {
        printf("%g ", arr[i]);
        i++;
    }
    putchar('\n');
    return (0);
}
