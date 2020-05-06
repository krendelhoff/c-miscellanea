#include "libft.h"

int cache[100] = {0};

double power(int a, int k)
{
    double n;
    int i;

    n = 1;
    i = 0;
    if (k >= 0)
        while (i < k)
        {
            n *= a;
            i++;
        }
    else
        while (i > k)
        {
            n /= a;
            i--;
        }
    return (n);
}

int rpower(int a, int k)
{
    if (k == 0)
        return (1);
    if (k % 2 == 0)
        return (rpower(a*a, k / 2));
    return (a*rpower(a, k - 1));
}

int factorial(int n)
{
    int m;

    m = 1;
    while (n > 0)
        m *= (n--);
    return m;
}

int isprime(int n)
{
    int divisor;

    divisor = 2;
    while (power(divisor, 2) <= n)
    {
        if (n % divisor == 0)
            return (0);
        divisor++;
    }
    return (1);
}

void print_number_factors(int n)
{
    int divisor;
    int original;

    divisor = 2;
    original = n;
    while (n != 1)
    {
        while (n % divisor == 0)
        {
            n /= divisor;
            print_int(divisor);
            print_str(" ");
        }
        divisor++;
    }
}

void sieve(int arr[], int n)
{
    int i;
    int k;

    i = 2;
    while (i*i < n)
    {
        k = i*i;
        if (arr[i] == 0)
            while (k < n)
            {
                arr[k] = 1;
                k += i;
            }
        i++;
    }
    print_arr(arr, 0, n);
}

int euclidus(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return (a);
}

int fast_euclidus(int a, int b)
{
    int tmp;

    if (b > a)
        iswap(&a, &b);
    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return (a);
}

int gcd(int a, int b)
{
    if (a == 0)
        return (b);
    gcd(b % a, a);
}

int gcd_expanded(int a, int b, int *x, int *y)
{
    int x1;
    int y1;
    int d;

    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return (b);
    }
    d = gcd_expanded(b%a, a, &x1, &y1);
    *x = y1 - (b / a)*x1;
    *y = x1;
    return (d);
}

int fibonacci(int n)
{
    if (n <= 1)
        return (n);
    if (cache[n] != 0)
        return (cache[n]);
    return (cache[n] = fibonacci(n - 1) + fibonacci(n - 2));
}

int ring(int n)
{
    int i;
    int reversible;

    i = 1;
    reversible = 0;
    while (i < n)
    {
        if (fast_euclidus(i, n) == 1)
            reversible++;
        i++;
    }
    return (reversible);
}

