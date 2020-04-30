#include "libft.h"

int scan_line(char s[], int lim)
{
    int i;
    char c;

    i = 0;
    while (i < lim - 1 && (c = getbufchar()) != EOF && c != '\n')
    {
        s[i] = c;
        i++;
    }
    if (c == '\n')
    {
        s[i] = '\n';
        i++;
    }
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

char buf[BUFSIZE];
int  bufp;

char getch(void)
{
    if (bufp > 0)
        return (buf[--bufp]);
    return (ft_getchar());
}

void ungetch(char c)
{
    if (bufp >= BUFSIZE)
        print_str("Too many characters. Failed to ungetch.\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn)
{
    int c;
    int sign;

    while ((c = getch()) == ' ')
        ;
    if (!(c >= '0' && c <= '9') && c != EOF && c != '+' && c != '-')
    {
        //ungetch(c);                   имеет право на существование, tho.
        return (0);
    }
    if (c == '-')
        sign = -1;
    else
        sign = 1;
    if (c == '+' || c == '-')
        c = getch();
    if (c >= '0' && c <= '9')
    {
        *pn = 0;
        while (c >= '0' && c <= '9')
        {
            *pn = 10 * *pn + (c - '0');
            c = getch();
        }
        *pn *= sign;
        if (c != EOF)
            ungetch(c);
        return (c);
    }
    else
    {
        ungetch(c);
        return (0);
    }
}

int getfloat(double *pn)
{
    int c;
    int sign;
    int power;

    while ((c = getch()) == ' ')
        ;
    if (!(c >= '0' && c <= '9') && c != EOF && c != '+' && c != '-')
    {
        //ungetch(c);
        return (0);
    }
    if (c == '-')
        sign = -1;
    else
        sign = 1;
    if (c == '+' || c == '-')
        c = getch();
    if (c >= '0' && c <= '9')
    {
        *pn = 0;
        while (c >= '0' && c <= '9')
        {
            *pn = 10.0 * *pn + (c - '0');
            c = getch();
        }
        if (c == '.')
            c = getch();
        power = 1;
        while (c >= '0' && c <= '9')
        {
            *pn = 10.0 * *pn + (c - '0');
            c = getch();
            power *= 10;
        }
        *pn = sign * *pn / (double)power;
        if (c != EOF)
            ungetch(c);
        return (c);
    }
    else
    {
        ungetch(c);
        return (0);
    }
}
