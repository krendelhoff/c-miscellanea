#include "libft.h"
#include <stdio.h>
#define swap(t, x, y) {t tmp; tmp = x; x = y; y = tmp;}

int main(int argc, char **argv)
{
    while (--argc > 0)
    {
        printf("%s ", argv[argc]);
    }
    ft_putchar('\n');
    return (0);
}

