#include "mylib.h"

enum e_sosi { LOL, HAHA };

int main(void)
{
    print_int(getbits(217, 6, 4));
    ft_putchar('\n');
    print_int(setbits(217, 6, 4, 3));
    ft_putchar('\n');
    print_int(invert(217, 6, 4));
    ft_putchar('\n');
    print_int(bitcount(28333));
    ft_putchar('\n');
    print_int(fast_bitcount(28333));
    ft_putchar('\n');
    return (0);
}
