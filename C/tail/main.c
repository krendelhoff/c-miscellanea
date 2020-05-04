#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1000000
#define MAXSIZE 1000
#define MAXLINE 100
int ft_getline(char *s, int lim);
char *strcpy(char *s, const char *t);

int main(int argc, char *argv[])
{
    int n;
    char buffer[BUFSIZE];
    char *lineptr;
    char s[MAXSIZE];
    char *lines[MAXLINE];
    int len;
    int i;
    int k;

    lineptr = buffer;
    i = 0;
    if (argc == 1)
    {
        printf("Usage: tail -n <file>\n");
        return (1);
    }
    else
    {
        while (--argc)
        {
            ++argv;
            if (**argv == '-')
                n = atoi(*argv + 1);
        }
        while ((len = ft_getline(s, MAXSIZE)) != 0)
        {
            strcpy(lineptr, s);
            lines[i++] = lineptr;
            lineptr += len + 1;
        }
        if (n >= i)
        {
            k = 0;
            while (k < i)
                printf("%s", lines[k++]);
        }
        else
        {
            k = i - n;
            while (k < i)
                printf("%s", lines[k++]);
        }
    }
    return (0);
}

int ft_getline(char *s, int lim)
{
    char c;
    int i;

    i = 0;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return (i);
}
