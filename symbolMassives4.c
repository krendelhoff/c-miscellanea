#include <stdio.h>
#define MAXLINE 1000
int getLine(char s[], int lim);
void reverse(char line[]);
int main(void)
{
    char line[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("\n%s\n", line);
    }
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
    return i;
}
void reverse(char l[])
{
    int i = 0, j = 0;
    char c;
    while (l[i] != '\n')
        ++i;
    for (i; i >= j; --i)
    {
        c = l[j];
        l[j] = l[i];
        l[i] = c;
        ++j;
    }
}