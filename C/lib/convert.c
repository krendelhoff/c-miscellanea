#include "libft.h"

int str_to_int(char s[])
{
    int length;
    int i;
    int n;
    int sign;

    n = i = 0;
    sign = 1;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    length = find(s, '.');
    while (i < strlength(s))
    {
        n += (s[i] - '0')*power(10, --length);
        i++;
    }
    return (sign*n);
}

double str_to_float(char s[])
{
    int length;
    int i;
    double n;
    int sign;

    n = i = 0;
    sign = 1;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    length = find(s, '.');
    while (s[i] != '.' && i < strlength(s))
    {
        n = n + (s[i] - '0')*power(10, --length);
        i++;
    }
    length = i++;
    while (i < strlength(s))
    {
        n += (s[i] - '0')*power(10, length - i);
        i++;
    }
    return (n*sign);
}

int ft_atoi(char s[])
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (s[i] >= '0' && s[i] <= '9')
    {
        ft_putchar(s[i]);
        ft_putchar(' ');
        n = 10 * n + (s[i] - '0');
        print_int(n);
        ft_putchar('\n');
        i++;
    }
    return (n);
}

int hex(char c)
{
    if (c >= '0' && c <= '9')
    {
        return (c - '0');
    }
    else if (c == 'A' || c == 'a')
    {
        return (10);
    }
    else if (c == 'B' || c == 'b')
    {
        return (11);
    }
    else if (c == 'C' || c == 'c')
    {
        return (12);
    }
    else if (c == 'D' || c == 'd')
    {
        return (13);
    }
    else if (c == 'E' || c == 'e')
    {
        return (14);
    }
    else if (c == 'F' || c == 'f')
    {
        return (15);
    }
    else
    {
        print_str("Wrong number!\n");
        exit(1);
    }
}

int ft_htoi(char s[])
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (s[i] != '0' && (s[i + 1] != 'x' || s[i + 1] != 'X'))
    {
        print_str("Error!\n");
        exit(1);
    }
    i += 2;
    while (s[i] != '\0')
    {
        n = hex(s[i]) + 16 * n;
        i++;
    }
    return (n);
}
