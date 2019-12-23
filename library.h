#ifndef LIBRARY_H
#define LIBRARY_H
int length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
void expand(char s[], char ss[])
{
    int len = length(s), k = 0;
    for (int i = 0; i < len; i++)
    {
        int dec = s[i + 1] - s[i - 1];
        if (s[i] == '-')
        {
            if (dec >= 0)
            {
                if ((s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9') ||
                (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z') ||
                (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z'))
                {
                    for (int jj = 0; jj < dec - 2; jj++)
                    {
                        for (int m = k + len + jj; m > i + 2 + jj + k; m--)
                        {
                            int f = m + 1;
                            ss[f] = ss[m];
                        }
                    }
                    for (int jj = i - 1 + k, t = 0; jj <= i - 1 + dec + k; jj++, t++)
                        ss[jj] = s[i - 1] + t;
                    k = k + dec - 2;
                    i++;
                } else 
                    ss[k + i] = s[i];
            }
            else
                ss[k + i] = s[i];
        }
        else
            ss[k + i] = s[i];
    }
}
int getLine(char s[], int lim)
{
    char c;
    int i;
    for (i = 0; i < lim - 1 && (c = getchar()) != '<' && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
int binsearch(int x, int s[], int n)
{
    int high = --n, low = 0, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (s[mid] > x)
        {
            high = mid - 1;
        }
        else if (s[mid] < x)
        {
            low = mid + 1;
        }
        else
            return mid;
    }
    return -1;
}
int binsearchv(int x, int s[], int n)
{
    int low = 0, high = --n, mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (x <= s[low])
            high = mid;
        else
            low = mid + 1;
    }
    return (x == s[low]) ? low : -1;
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
void escape(char s[])
{
    int i = 0;
    char c;
    while (s[i] != '\0')
        i++;
    for (int k = 0; k < i; k++)
    {
        switch (s[k])
        {
        case '\n':
            for (int m = --i; m > k; m--)
            {
                int f = m + 1;
                s[f] = s[m];
            }
            s[k] = '\\';
            s[++k] = 'n';
            break;
        }
    }
}
void escapeback(char s[])
{
    int i = 0, f;
    while (s[i] != '\0')
        i++;
    for (int k = 0; k < i; k++)
    {
        if (s[k] == '\\' && s[k + 1] == 'n')
        {
            for (int m = k + 1; m < i; m++)
            {
                f = m + 1;
                s[m] = s[f];
            }
            s[k] = '\n';
        }
    }
}
int hTol(char s[])
{
    char c;
    int i = 0, j = 0, n, sum = 0;
    while (s[i] != '\n')
        ++i;
    --i;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        for (i; i > 1; i--)
        {
            if( s[i] >= 'A' && s[i] <= 'F') {
                n = s[i] - 'A' + 10;
            } else if (s[i] >= 'a' && s[i] <= 'f') {
                n = s[i] - 'a' + 10;
            } else if (s[i] >= '0' && s[i] <= '9') {
                n = s[i] - '0';
            }
            sum = sum + n * pow(16, j);
            ++j;
        }
    }
    return sum;
}
void lower(char s[])
{
    for(int i = 0; s[i] != '\0'; i++)
    s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 'a': s[i];
}
void shellsort(int s[], int n)
{
    for(int gap = n / 2; gap > 0; gap /= 2)
        for(int i = gap; i < n; i++)
            for(int j = i - gap; j >= 0 && s[j] > s[j + gap]; j -= gap)
            {
                int temp = s[j];
                s[j] = s[j + gap];
                s[j + gap] = temp;
            }
}
void copy(char to[], char from[])
{
    for (int i = 0; (to[i] = from[i]) != '\0'; ++i)
        ;
}
void reverse(char l[])
{
    int i = 0, j = 0;
    char c;
    while (l[i] != '\n')
        ++i;
    for (i; i >= j; --i)
    {
        c = l[j];
        l[j] = l[i];
        l[i] = c;
        ++j;
    }
}
void squeeze(char s[], char ss[])
{
    int i, j, z;
    for (z = 0; ss[z] != '\0'; z++)
    {
        for (i = j = 0; s[i] != '\0'; i++)
            if (s[i] != ss[z])
                s[j++] = s[i];
        s[i] = '\0';
    }
}
void any(char s[], char ss[])
{
    for(int i = 0; ss[i] != '\0'; i++) {
        for(int j = 0; s[j] != '\0'; j++) {
            if (s[j] == ss[i]) 
                return j;
        }
    }
    return -1;
}
#endif