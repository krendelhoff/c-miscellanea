#include <stdio.h>
#define MAXLINE 1000
int getLine(char s[], int lim);
void escape(char s[]);
void escapeback(char s[]);
int main(void)
{
    int len;
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        escape(line);
        printf("%s\n", line);
    }
    return 0;
}
int getLine(char s[], int lim)
{
    char c;
    int i;
    for (i = 0; i < lim - 1 && (c = getchar()) != '0' && c != '\n'; ++i)
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
