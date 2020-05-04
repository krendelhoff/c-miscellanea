#include "libft.h"

void print_int(int n)
{
    int i;
    char c;
    int arr[10];

    i = 0;
    if (n < 0)
    {
        ft_putchar('-');
        n = n*(-1);
    }
    while (n >= 0)
    {
        arr[i] = n % 10;
        n = n / 10;
        if (n == 0)
                break;
        i++;
    }
    while (i >= 0)
    {
        ft_putchar(arr[i] + '0');
        i--;
    }
}

void print_arr(int arr[], int first, int last)
{
    int i;
    char c;

    i = first;
    while (i <= last)
    {
        print_int(arr[i]);
        ft_putchar(' ');
        i++;
    }
    ft_putchar('\n');
}

void print_str(char s[])
{
    int i;
    char c;

    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar(s[i]);
        i++;
    }
}

void print_float(double n, int signs)
{
    int i;
    double k;
    int state;

    i = 0;
    if (n < 0)
    {
        ft_putchar('-');
        n = n*(-1);
    }
    print_int((int) n);
    ft_putchar('.');
    k = n - (int) n;
    if (n != (int) n)
        while (i < signs)
        {
            k *= 10;
            print_int((int) k);
            i++;
            k -= (int) k;
        }
    else
        while (i++ < signs)
            print_int(0);
}

void printd(int n)
{
    if (n < 0)
    {
        n = -n;
        ft_putchar('-');
    }
    if (n / 10)
        printd(n / 10);
    ft_putchar(n % 10 + '0');
}

void ln(void)
{
    ft_putchar('\n');
}
