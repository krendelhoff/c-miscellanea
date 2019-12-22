#include <stdio.h>
#define MAXLINE 1000
int getLine(char s[], int lim);
void loWer(char s[]);
int main(void)
{
    char line[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        loWer(line);
        printf("\n%s\n", line);
    }
    return 0;
}
int getLine(char s[], int lim)
{
    int i;
    char c;
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
void loWer(char s[])
{
    for(int i = 0; s[i] != '\0'; i++)
    s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 'a': s[i];
}