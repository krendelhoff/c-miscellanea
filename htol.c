#include <stdio.h>
#include <math.h>
#define MAXLINE 1000
int getLine(char s[], int lim);
int hTol(char s[]);
int main(void)
{
    char line[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
        printf("\n%d\n\n", hTol(line));
    return 0;
}
int getLine(char s[], int lim)
{
    int i;
    char c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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
int hTol(char s[])
{
    char c;
    int i = 0, j = 0, n, sum = 0;
    while (s[i] != '\n')
        ++i;
    --i;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        for (i; i > 1; i--)
        {
            if( s[i] >= 'A' && s[i] <= 'F') {
                n = s[i] - 'A' + 10;
            } else if (s[i] >= 'a' && s[i] <= 'f') {
                n = s[i] - 'a' + 10;
            } else if (s[i] >= '0' && s[i] <= '9') {
                n = s[i] - '0';
            }
            sum = sum + n * pow(16, j);
            ++j;
        }
    }
    return sum;
}