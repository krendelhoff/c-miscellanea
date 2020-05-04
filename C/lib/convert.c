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
    while (i < ft_strlen(s))
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
    while (s[i] != '.' && i < ft_strlen(s))
    {
        n = n + (s[i] - '0')*power(10, --length);
        i++;
    }
    length = i++;
    while (i < ft_strlen(s))
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
        n = 10 * n + (s[i] - '0');
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

void ft_itoa(int n, char s[])
{
    int i;
    int sign;

    if (n < 0)
        sign = -1;
    i = 0;
    while (TRUE)
    {
        if (sign < 0)
        {
            s[i++] =(-1) * (n % 10) + '0';
        }
        else
            s[i++] = n % 10 + '0';
        if ((n /= 10) == 0)
            break;
    }
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

char chex(int n)
{
    if (n >= 10 && n <= 15)
        return ('A' + (n - 10));
    else
        return (n + '0');
}

void itob(int n, char s[], int base)
{
    int i;
    int sign;

    if (base < 2 || base > 16)
    {
        print_str("Wrong base.\n");
    }
    else
    {
        if (n < 0)
            sign = -1;
        i = 0;
        while (TRUE)
        {
            if (sign < 0)
            {
                if (base > 10)
                {
                    s[i++] = chex((-1) * (n % base));
                }
                else
                    s[i++] =(-1) * (n % base) + '0';
            }
            else if (base > 10)
                s[i++] = chex(n % base);
            else
                s[i++] = n % base + '0';
            if ((n /= base) == 0)
                break;
        }
        if (base == 16)
        {
            s[i++] = 'x';
            s[i++] = '0';
        }
        else if (base == 8)
            s[i++] = '0';
        if (sign < 0)
            s[i++] = '-';
        s[i] = '\0';
        reverse(s);
    }
}

void ft_itoa_extended(int n, char s[], int b)
{
    char t[N];
    int i;

    ft_itoa(n, s);
    if (ft_strlen(s) < b)
    {
        i = b - ft_strlen(s);
        while (i >= 0)
        {
            cprepend(s, ' ');
            i--;
        }
    }
}

double ft_atof(char s[])
{
    double val;
    int pow;
    int i;
    int sign;

    i = 0;
    sign = 1;
    val = 0;
    pow = 1;
    while (s[i] == ' ')
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        val = 10.0 * val + (s[i] - '0');
        i++;
    }
    if (s[i] == '.')
        i++;
    while (s[i] >= '0' && s[i] <= '9')
    {
        val = 10.0 * val + (s[i] - '0');
        pow *= 10;
        i++;
    }
    if (s[i] == 'e')
    {
        i++;
        if (s[i] == '-')
        {
            i++;
            if (s[i] >= '0' && s[i] <= '9')
                return (sign * (val / pow) * power(10, (-1) * (s[i] - '0')));
        }
        else if (s[i] >= '0' && s[i] <= '9')
            return (sign * val * rpower(10, s[i] - '0') / pow);
        else if (s[i] == '+')
        {
            i++;
            if (s[i] >= '0' && s[i] <= '9')
                return (sign * val * rpower(10, s[i] - '0') / pow);
        }
    }
    return (sign * val / pow);
}

void ritoa(int n, char *s)
{
    static int i;

    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        ritoa(n / 10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}

