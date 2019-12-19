#include <stdio.h>
#define MAXLINE 1000
#define N 5
void printLineN(char s[]);
int getLine(char s[], int lim);
int main(void)
{
    char line[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
        printLineN(line);
    return 0;
}
int getLine(char s[], int lim)
{
    char c;
    int i;
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
void printLineN(char s[])
{
    int i = 0;
    while (s[i] != '\n')
        ++i;
    putchar('\n');
    for(int j = 0; j < i; ++j) {
        putchar(s[j]);
        if (((j + 1) % N) == 0) {
            putchar('\n');
        }
    }
    putchar('\n');
}