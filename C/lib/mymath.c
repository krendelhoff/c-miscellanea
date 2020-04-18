/* my math lib */

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
