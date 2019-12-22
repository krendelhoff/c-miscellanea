#include <stdio.h>
int setbits(int x, int p, int n, int y);
int invert(int x, int p, int n);
int getbits(int x, int p, int n);
int rightrot(int x, int n);
int bitcount(unsigned x);
int main(void)
{
    printf("%d\n", setbits(85, 4, 3, 59));
    printf("%d\n", invert(85, 4, 3));
    printf("%d\n", rightrot(85, 3));
    printf("%d\n", bitcount(100));
}
int setbits(int x, int p, int n, int y)
{
    y = y & (~(~0 << n));
    y = y << (p - n + 1);
    int i = ~(~(~0 << n) << (p - n + 1));
    x = x & i;
    x = x | y;
    return x;
}
int invert(int x, int p, int n)
{
    int bits = (~getbits(x, p, n) & ~(~0 << n)) << (p - n + 1);
    x = x & ~(~(~0 << n) << (p - n + 1));
    x = x | bits;
    return x;
}
int getbits(int x, int p, int n)
{
    return (x >> (p - n + 1)) & ~(~0 << n);
}
int rightrot(int x, int n)
{
    for (int i = 0; i < n; i++)
        x = x >> 1;
    return x;
}
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x - 1)) /* когда выражение в цикле не меняется, то ход цикла не происходит и он снова вычисляет выражение пока не изменится*/
        b++;
    return b;
}