#ifndef LIBRARY_H
#define LIBRARY_H
#include <limits.h>
#include <ctype.h>
#include <math.h>
#define MAXLINE 1000
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
                }
                else
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
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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
        if (x <= s[mid])
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
int getbits(int x, int p, int n)
{
    return (x >> (p - n + 1)) & ~(~0 << n);
}
int invert(int x, int p, int n)
{
    int bits = (~(getbits(x, p, n)) & ~(~0 << n)) << (p - n + 1);
    x = x & ~(~(~0 << n) << (p - n + 1));
    x = x | bits;
    return x;
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
    int j = 0, n, sum = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        for (int i = length(s) - 1; i > 1; i--)
        {
            if (s[i] >= 'A' && s[i] <= 'F')
            {
                n = s[i] - 'A' + 10;
            }
            else if (s[i] >= 'a' && s[i] <= 'f')
            {
                n = s[i] - 'a' + 10;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
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
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 'a' : s[i];
}
void shellsort(int s[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++)
            for (int j = i - gap; j >= 0 && s[j] > s[j + gap]; j -= gap)
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
void reverse(char s[])
{
    int len = length(s);
    char temp;
    for (int i = 0, j = len - 1; i < j; i++, j--)
        temp = s[i], s[i] = s[j], s[j] = temp;
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
int any(char s[], char ss[])
{
    for (int i = 0; ss[i] != '\0'; i++)
    {
        for (int j = 0; s[j] != '\0'; j++)
        {
            if (s[j] == ss[i])
                return j;
        }
    }
    return -1;
}
void itoa(int n, char s[])
{
    int i, sign;
    if (n > INT_MIN)
    {
        if ((sign = n) < 0)
            n = -n;
        i = 0;
        do
        {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);
        if (sign < 0)
            s[i++] = '-';
    }
    else
    {
        long int nl = n;
        nl = -nl;
        do
        {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
void moveright(char s[], int n, int p)
{
    for (int jj = 0; jj < n; jj++)
        for (int i = jj + length(s); i >= p + jj; i--)
            s[i + 1] = s[i], s[i] = ' ';
}
void moveright_v2(char s[], int n, int p)
{
    for (int i = length(s); i >= p; i--)
        s[i + n] = s[i], s[i] = ' ';
}
void itob(char s[], int n, int b)
{
    int i, j = 0;
    do
    {
        i = n % b;
        if (i >= 10)
            s[j] = i + 'A' - 10;
        else
            s[j] = (n % b) + '0';
        j++;
        n = n / b;
    } while (n >= b);
    if (n >= 10)
        s[j++] = n + 'A' - 10;
    else
        s[j++] = n + '0';
    s[j] = '\0';
    reverse(s);
    if (length(s) < 10)
        moveright_v2(s, 10 - length(s), 0);
}
int strindexf(char s[], char ss[])
{
    int k, i, jj;
    for (i = 0; i < length(s); i++)
    {
        for (jj = i, k = 0; ss[k] != '\0' && s[jj] == ss[k]; jj++, k++)
            ;
        if (k > 0 && ss[k] == '\0')
            return i;
    }
    return -1;
}
int strindexl(char s[], char ss[])
{
    int k, i, jj, m = 0, state = 0, el;
    char line[MAXLINE];
    for (i = 0; i < length(s); i++)
    {
        for (jj = i, k = 0; ss[k] != '\0' && s[jj] == ss[k]; jj++, k++)
            ;
        if (k > 0 && ss[k] == '\0')
        {
            state = 1;
            line[m++] = i;
        }
    }
    line[m] = '\0';
    if (state == 1)
        return el = line[length(line) - 1];
    return -1;
}
/*double atof(char s[])
{
    int i, sign, prik = 0, k;
    double val, power;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if ((s[i] == 'e' || s[i] == 'E') && (s[i + 1] == '-' || s[i + 1] == '+' || isdigit(s[i + 1])))
        for (k = i + 2 - isdigit(s[i + 1]); isdigit(s[k]); k++)
            prik = 10 * prik + (s[k] - '0');
    if (s[i + 1] == '-')
        return sign * val / power / pow(10, prik);
    else
        return sign * val / power * pow(10, prik);
}*/
int calc(char s[])
{
    int line[MAXLINE], i, k, num = 0, jj = -1, sign;
    for (i = 0; i < length(s); i++)
    {
        if (isdigit(s[i]))
        {
            sign = (s[i - 1] == '-') ? -1 : 1;
            for (k = i; isdigit(s[k]); k++)
                num = 10 * num + (s[k] - '0');
            i += (k - i);
            line[++jj] = sign * num;
            num = 0;
        }
        switch (s[i])
        {
        case '-':
            if (isspace(s[i - 1]) && isspace(s[i + 1]))
            {
                jj--;
                line[jj] -= line[jj + 1];
            }
            break;
        case '+':
            jj--;
            line[jj] += line[jj + 1];
            break;
        case '/':
            jj--;
            line[jj] /= line[jj + 1];
            break;
        case '*':
            jj--;
            line[jj] *= line[jj + 1];
            break;
        }
    }
    return line[jj];
}
#endif
