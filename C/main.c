#include "libft.h"
#define swap(t, x, y) {t tmp; tmp = x; x = y; y = tmp;}
int ft_gcd(int a, int b);

int main(void)
{
    print_int(ring(10494545));
    ln();
    return (0);
}

int ft_gcd(int a, int b)
{
    if (a == 0)
        return (b);
    return (ft_gcd(b % a, a));
}
