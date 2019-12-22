#include <stdio.h>
#define MAXLINE 1000
void squeeze(char s[], char ss[]);
int getLine(char s[], int lim);
int main(void)
{
    char line[MAXLINE], line1[MAXLINE];
    int len, i = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        i++;
        printf("\n%d\n\n", hTol(line));
    }
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
void squeeze(char s[], char ss[])
{
    int i, j, z;
    for (z = 0; ss[z] != '\0'; z++)
    {
        for (i = j = 0; s[i] != '\0'; i++)
            if (s[i] != ss[z])
                s[j++] = s[i];
        s[i] = '\0';
    }
}
void any(char s[], char ss[])
{
    for(int i = 0; ss[i] != '\0'; i++) {
        for(int j = 0; s[j] != '\0'; j++) {
            if (s[j] == ss[i]) 
                return j;
        }
    }
    return -1;
}