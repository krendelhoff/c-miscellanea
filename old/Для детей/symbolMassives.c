#include <stdio.h>
#define MAXLINE 10
#define MORE 1
#define LESS 0
int getLine(char h[], int m);
void copy(char s[], char m[]);
int main(void)
{
    char line[MAXLINE], longest[MAXLINE], temp[MAXLINE];
    int len, max = 0, state = LESS, iNt = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (line[len - 1] != '\n')
        {
            if (state == LESS)
            {
                copy(temp, line);
            }
            iNt = iNt + len;
            state = MORE;
        }
        else
        {
            if (state == MORE)
            {
                if (max < len + iNt)
                {
                    max = len + iNt;
                    copy(longest, temp);
                }
                state = LESS;
            }
            else if (len > max)
            {
                max = len;
                copy(longest, line);
            }
        }
    }
    if (max > 0)
    {
        printf("Самая длинная строка:%s\n", longest);
        printf("Длина самой длинной строки:%d\n", max);
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
void copy(char to[], char from[])
{
    for (int i = 0; (to[i] = from[i]) != '\0'; ++i)
        ;
}