#include "libft.h"

int find(char s[], char c)
{
    int i;
    int state;

    i = state = 0;
    if (s[i] == '-')
    {
        i++;
        state = -1;
    }
    while (s[i] != c && i < ft_strlen(s))
        i++;
    return (i + state);
}

int find_char(char s[], char c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (TRUE);
        i++;
    }
    return (FALSE);
}

int any(char s[], char t[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (find_char(t, s[i]))
            return (i);
        i++;
    }
    return (-1);
}

int ft_bsearch(int *arr, int x, int low, int high)
{
    int mid;


    while (low < high)
    {
        mid = (low + high) / 2;
        if (x <= arr[mid])
            high = mid;
        else
            low = mid + 1;
    }
    if (arr[low] == x)
        return (low);
    return (-1);
}

int strindex(char s[], char t[])
{
    int i;
    int j;
    int k;

    i = 0;
    while (s[i] != '\0')
    {
        j = 0;
        k = i;
        while (t[j] != '\0' && s[k] == t[j])
        {
            k++;
            j++;
        }
        if (j > 0 && t[j] == '\0')
            return (i);
        i++;
    }
    return (-1);
}

int strindex1(char s[], char t[])
{
    int i;
    int j;
    int k;
    int ix;

    i = 0;
    ix = 0;
    while (s[i] != '\0')
    {
        j = 0;
        k = i;
        while (t[j] != '\0' && s[k] == t[j])
        {
            k++;
            j++;
        }
        if (j > 0 && t[j] == '\0')
            ix = i;
        i++;
    }
    if (ix != 0)
        return (ix);
    return (-1);
}
