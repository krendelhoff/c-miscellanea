#include "libft.h"

int main(void)
{
    char s[N];
    char t[N];

    scan_line(s, N - 1);
    expand(s, t);
    ft_squeeze(t, '\\');
    print_str(t);
    ft_putchar('\n');
    return (0);
}
