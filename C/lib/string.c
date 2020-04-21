#include "libft.h"

int ft_strlen(char s[])
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

void ft_strcat(char s[], char t[])
{
    int i;
    int j;
    int l;

    j = 0;
    i = strlength(s);
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
    last = strlength(s) - 1;
    while (last > first)
    {
        swap_char(s, first, last);
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
    while (i < strlength(s) - 1)
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

    temp = s[strlength(s) - 1];
    i = strlength(s) - 1;
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
    while (i < strlength(s))
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

    while(index < strlength(s))
    {
        s[index] = s[index + 1];
        index++;
    }
}
