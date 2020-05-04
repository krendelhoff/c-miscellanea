#include "expr.h"

char buffer[N];
char *bufp = buffer;

int getch(void)
{
    if (bufp > buffer)
        return (*(--bufp));
    else
        return (ft_getchar());
}

void ungetch(char c)
{
    if (bufp < buffer + N)
        *bufp++ = c;
    else
        print_str("Character buffer overflow.\n");
}

void ungets(char *s)
{
    char *t;

    t = s;
    while (*t)
        t++;
    while (t >= s)
        ungetch(*t--);
}

int getop(char *s)
{
    char c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(++s) = '\0';
    --s;
    if ((c < '0' || c > '9') && c != '-' && c != '.')
        return (c);
    if (c == '-')
    {
        if (((c = getch()) >= '0' && c <= '9') || c == '.')
            *(++s) = c;
        else
        {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (c >= '0' && c <= '9')
        while ((c = *(++s) = getch()) >= '0' && c <= '9')
            ;
    if (c == '.')
        while ((c = *(++s) = getch()) >= '0' && c <= '9')
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return (NUMBER);
}
