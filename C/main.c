#include "libft.h"
#include <limits.h>

int main(void)
{
    char s[N];
    int n;

    while ((n = scan_line(s, N)) != 0)
    {
        print_str(s);
    }
    ft_putchar('\n');
    return (0);
}
