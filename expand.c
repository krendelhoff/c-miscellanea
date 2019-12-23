#include <stdio.h>
#define MAXLINE 1000
int getLine(char h[], int m);
void expand(char s[], char ss[]);
int length(char s[]);
int main(void)
{
    char line[MAXLINE], line1[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        expand(line, line1);
        printf("%s", line1);
        break;
    }
    return 0;
}
int getLine(char s[], int lim)
{
    char c;
    int i;
    for (i = 0; i < lim - 1 && (c = getchar()) != '<' && c != '\n'; ++i)
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
void expand(char s[], char ss[])
{
    int len = length(s), k = 0;
    for (int i = 0; i < len; i++)
    {
        int dec = s[i + 1] - s[i - 1];
        if (s[i] == '-')
        {
            if (dec >= 0)
            {
                if ((s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9') ||
                (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z'))
                {
                    for (int jj = 0; jj < dec - 2; jj++)
                    {
                        for (int m = k + len + jj; m > i + 2 + jj + k; m--)
                        {
                            int f = m + 1;
                            ss[f] = ss[m];
                        }
                    }
                    for (int jj = i - 1 + k, t = 0; jj <= i - 1 + dec + k; jj++, t++)
                        ss[jj] = s[i - 1] + t;
                    k = k + dec - 2;
                    i++;
                } else 
                    ss[k + i] = s[i];
            }
            else
                ss[k + i] = s[i];
        }
        else
            ss[k + i] = s[i];
    }
}
int length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}