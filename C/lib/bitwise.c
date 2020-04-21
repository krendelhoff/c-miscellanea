#include "libft.h"

unsigned getbits(unsigned x, int p, int n)
{
    return ((x >> (p - n + 1)) & ~(~0 << n));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned a;
    unsigned b;

    a = ~(~0 << n) & y;
    a = a << (p - n + 1);
    b = ~(~(~0 << n) << (p - n + 1));
    x = x & b;
    x = x | a;
    return (x);
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned a;
    unsigned b;

    a = ~(~0 << n) << (p - n + 1);
    x = x ^ a;
    return (x);
}

unsigned rigthrot(unsigned x, int n)
{
    int i;
    unsigned a;
    unsigned b;

    i = 0;
    while (i < n)
    {
        a = ~(~(unsigned)0 << 1) & x;
        if (a == 1)
        {
            x = (x >> 1) | (~(~0 >> 1));
        }
        else
        {
            x = (x >> 1);
        }
        i++;
    }
    return (x);
}

int bitcount(unsigned x)
{
    int b;

    b = 0;
    while (x != 0)
    {
        if (x & 01)
        {
            b++;
        }
        x >>= 1;
    }
    return (b);
}

int fast_bitcount(unsigned x)
{
    int b;

    b = 0;
    if (x > 0)
    {
        while((x &= x - 1) != 0)
        {
            b++;
        }
        return (++b);
    }
    return (FALSE);
}
