#include "libft.h"
#include <stdio.h>

int ft_strlen2(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

void expand(char *s, char *t)
{
    int i;
    int j;
    int k;
    int m;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        if (i > 0 && s[i] == '-' && s[i + 1] - s[i - 1] >= 0)
        {
            if (s[i - 1] >= '0' && s[i - 1] <= '9' &&
                s[i + 1] >= '0' && s[i + 1] <= '9' &&
                (k = s[i + 1] - s[i - 1]) >= 0)
            {
                m = k;
                while (k > 0)
                {
                    t[j++] = s[i - 1] + (m - k + 1);
                    k--;
                }
                i++;
            }
            else if (s[i - 1] >= 'a' && s[i - 1] <= 'z' &&
                s[i + 1] >= 'a' && s[i + 1] <= 'z' &&
                (k = s[i + 1] - s[i - 1]) >= 0)
            {
                m = k;
                while (k > 0)
                {
                    t[j++] = s[i - 1] + (m - k + 1);
                    k--;
                }
                i++;
            }
            else if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' &&
                s[i + 1] >= 'Z' && s[i + 1] <= 'Z' &&
                (k = s[i + 1] - s[i - 1]) >= 0)
            {
                m = k;
                while (k > 0)
                {
                    t[j++] = s[i - 1] + (m - k + 1);
                    k--;
                }
                i++;
            }
            else
                t[j++] = s[i];

        }
        else
            t[j++] = s[i];
        i++;
    }
    t[j] = '\0';
}

void escape(char *s, char *t)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        if (s[i] != '\n' && s[i] != '\t')
            t[j++] = s[i];
        else
        {
            t[j++] = '\\';
            if (s[i] == '\n')
                t[j++] = 'n';
            else
                t[j++] = 't';
        }
        i++;
    }
    t[j] = '\0';
}

void ft_strcat2(char s[], char t[])
{
    int i;
    int j;
    int l;

    j = 0;
    i = ft_strlen(s);
    while ((s[i] = t[j]) != '\0')                                    /* while ((s[i++] = t[j++]) != '\0'); possible */
    {
        i++;
        j++;
    }
}

void ft_squeeze(char s[], int c)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}

void reverse(char s[])
{
    int first;
    int last;

    first = 0;
    last = ft_strlen(s) - 1;
    while (last > first)
    {
        cswap(&s[first], &s[last]);
        first++;
        last--;
    }
}

void cyclic_shift_left_str(char s[])
{
    int temp;
    int i;

    temp = s[0];
    i = 0;
    while (i < ft_strlen(s) - 1)
    {
        s[i] = s[i + 1];
        i++;
    }
    s[i] = temp;
}

void cyclic_shift_right_str(char s[])
{
    int temp;
    int i;

    temp = s[ft_strlen(s) - 1];
    i = ft_strlen(s) - 1;
    while (i > 0)
    {
        s[i] = s[i - 1];
        i--;
    }
    s[0] = temp;
}

void   remove_trailing_spaces(char s[])
{
    int i;
    int k;

    k = i = 0;
    while (s[i] == ' ')
    {
        remove_term(s, i);
    }
    while (i < ft_strlen(s))
    {
        if (s[i] == ' ')
            k++;
        else
            k = 0;
        if (k > 1)
        {
            remove_term(s, i);
            k--;
            print_str(s);
            continue;
        }
        i++;
    }
}

void ft_extended_squeeze(char s[], char t[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (find_char(t, s[i]))
            ft_squeeze(s, s[i]);
        i++;
    }
}

void remove_term(char s[], int index)
{
    int i;

    while(index < ft_strlen(s))
    {
        s[index] = s[index + 1];
        index++;
    }
}

void cprepend(char s[], char c)
{
    int i;
    int l;

    l = ft_strlen(s);
    i = 0;
    while (l >= 0)
    {
        s[l + 1] = s[l];
        l--;
    }
    s[0] = c;
}

void rreverse(char *s, int pos)
{
    static int length;

    length = ft_strlen(s);
    if (pos >= length / 2)
        return;
    rreverse(s, pos + 1);
    cswap(&s[pos], &s[length - pos - 1]);
}

void ft_strcpy4(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void ft_strcpy2(char *s, char *t)    // пример как можно увеличивать указатели
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

void ft_strcpy3(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

void ft_strcpy(char *s, char *t)
{
    while ((*s++ = *t++))
        ;
}

int ft_strlen(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++;
    return (p - s);
}

int ft_strcmp2(char *s, char *t)
{
    int i;

    i = 0;
    while (s[i] == t[i])
    {
        if (s[i] == '\0')
            return (0);
        i++;
    }
    return (s[i] - t[i]);
}

int ft_strcmp(char *s, char *t)
{
    while (*s == *t)
    {
        if (*s == '\0')
            return (0);
        s++;
        t++;
    }
    return (*s - *t);
}

void ft_strcat(char *s, char *t)
{
    while (*s)          /* здесь тоже */
        s++;
    while ((*s++ = *t++))
        ;
}

int strend(char *s, char *t)
{
    char *p;
    int   length;
    int i;

    p = t;
    while (*p)          /* позже пойми почему while (*p++) ; двигается на один */
        p++;            /*  больше чем надо */
    length = p - t;
    i = 0;
    while (i++ < length - 1)
        s++;
    return (!ft_strcmp(s, t));
}

void ft_strncpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) && (--n > 0))
        ;
    *s = '\0';
}

int ft_strncmp(char *s, char *t, int n)
{
    while (*s == *t && --n > 0)
    {
        if (*s == '\0')
            return (0);
        s++;
        t++;
    }
    return (*s - *t);
}

void ft_strncat(char *s, char *t, int n)
{
    while (*s)
        s++;
    while ((*s++ = *t++) && --n > 0)
        ;
}

void preverse(char *s)
{
    char *p;

    p = s;
    while (*p)
        p++;
    p--;
    while (p - s > 0)   /* так же равноценно можно отправлять вместо */
        cswap(p--, s++); /* cswap(&s[i], &s[j]) вот так cswap(s + i, s + j); */
}
