#include "expr.h"

double val[N];
double *stackp = val;

double pop(void)
{
    if (stackp > val)
        return (*(--stackp));
    else
    {
        print_str("Stack is empty.\n");
        return (0.0);
    }
}

void push(double n)
{
    if (stackp < val + N)
        *stackp++ = n;
    else
    {
        print_str("Stack overflow. Can't put ");
        print_float(n, 4);
        ft_putchar('\n');
    }
}
