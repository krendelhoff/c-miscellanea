#include <stdio.h>
#define MAXLINE 1000
int getLine(char s[], int lim);
int main(void)
{
    char line[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
        ;
    return 0;
}
int getLine(char s[], int lim)
{
    int i;
    char c;
    for (i = 0; i < lim - 1 && (c = getchar()) != '0' && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    int n = 0;
    putchar('\n');
    for (int j = 0; j < i; ++j)
    {
        if (s[j] == ' ')
        {
            ++n;
            if (n == 1)
            {
                putchar(s[j]);
            }
        }
        else
        {
            n = 0;
            putchar(s[j]);
        }
    }
    putchar('\n');
    return i;
}