#include "libft.h"

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
