#define BUFSIZE 100000
#include <stdio.h>
char buf[BUFSIZE];
char *bufp = buf;

int getch(void)
{
    if (bufp - buf > 0)
        return (*(--bufp));
    else
        return (getchar());
}

void ungetch(int c)
{
    if (bufp - buf >= BUFSIZE)
    {
        printf("error: stack is full\n");
    }
    else
        *bufp++ = c;
}
