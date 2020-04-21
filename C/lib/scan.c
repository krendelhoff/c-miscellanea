#include "libft.h"

int scan_line(char s[], int lim)
{
    int i;
    char c;

    i = 0;
    while ((c = getbufchar()) != '\n' && i < lim - 1)
    {
        s[i] = c;
        i++;
    }
    if (c == '\n')
    {
        s[i] = '\n';
        i++;
    }
    else
        putinbuf(c);
    s[i] = '\0';
    return (i);
}

int scan_word(char s[])
{
    int i;
    char c;

    i = 0;
    while ((c = ft_getchar()) != ' ' && c != '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return (i);
}

int scan_int(void)
{
    char c;
    int sign;
    int i;
    char s[100];

    i = 0;
    while (((c = getbufchar()) >= '0' && c <= '9') || c == '-')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    putinbuf(c);
    return (str_to_int(s));
}

int scan_arr(int arr[])
{
    int i;
    char c;

    i = 0;
    while ((c = getbufchar()) != '\n')
    {
        if ((c >= '0' && c <= '9') || c == '-')
            putinbuf(c);
        arr[i] = scan_int();
        i++;
    }
    return (i);
}
