#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define MAXLINES 5000
#define BUFFERSIZE 1000000
#define MAXLINE 1000
char *strcpy(char *destptr, const char *srcptr);
int  ft_strcmp(char *str1,  char *str2);
int  ft_rstrcmp(char *str1,  char *str2);
int  ft_rfstrcmp(char *str1,  char *str2);
int  ft_fstrcmp(char *str1,  char *str2);
int  ft_dstrcmp(char *str1, char *str2);
int  ft_rdstrcmp(char *str1, char *str2);
int  ft_fdstrcmp(char *str1, char *str2);
int  ft_rfdstrcmp(char *str1, char *str2);

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char buffer[], int fd);
void writelines(char *lineptr[], int nlines);

int ft_getchar(int fd);
int fft_getline(char *s, int lim, int fd);

void ft_qsort(void *lineptr[], int left, int right, int (*comp)(void *op1, void *op2));

int numcmp(char *str1, char *str2);
int rnumcmp(char *str1, char *str2);


int main(int argc, char *argv[])
{
    char buffer[BUFFERSIZE];
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;
    int directory = 0;
    int fd = 0;

    while (--argc)
    {
        ++argv;
        if (ft_strcmp(*argv, "-n") == 0)
            numeric = 1;
        else if (ft_strcmp(*argv, "-r") == 0)
            reverse = 1;
        else if (ft_strcmp(*argv, "-f") == 0)
            fold = 1;
        else if (ft_strcmp(*argv, "-d") == 0)
            directory = 1;
        else
            fd = open(*argv, O_RDONLY);
    }
    if (fd == -1)
    {
        printf("Error: can't open file.\n");
        return (1);
    }
    if ((nlines = readlines(lineptr, MAXLINES, buffer, fd)) >= 0)
    {
        if (numeric)
        {
            if (reverse)
                ft_qsort((void**)lineptr, 0, nlines - 1,
                        (int (*)(void*, void*))rnumcmp);
            else
                ft_qsort((void**)lineptr, 0, nlines - 1,
                        (int (*)(void*, void*))numcmp);
        }
        else
        {
            if (reverse)
            {
                if (fold)
                {
                    if (directory)
                        ft_qsort((void**)lineptr, 0, nlines - 1,
                                (int (*)(void*, void*))ft_rfdstrcmp);
                    else
                        ft_qsort((void**)lineptr, 0, nlines - 1,
                                (int (*)(void*, void*))ft_rfstrcmp);
                }
                else
                {
                    if (directory)
                        ft_qsort((void**)lineptr, 0, nlines - 1,
                                (int (*)(void*, void*))ft_rdstrcmp);
                    else
                        ft_qsort((void**)lineptr, 0, nlines - 1,
                                (int (*)(void*, void*))ft_rstrcmp);

                }
            }
            else
            {
                if (fold)
                {
                    if (directory)
                        ft_qsort((void**)lineptr, 0, nlines - 1,
                                (int (*)(void*, void*))ft_fdstrcmp);
                    else
                        ft_qsort((void**)lineptr, 0, nlines - 1,
                                (int (*)(void*, void*))ft_fstrcmp);
                }
                else
                {
                    if (directory)
                        ft_qsort((void**)lineptr, 0, nlines - 1,
                                (int (*)(void*, void*))ft_dstrcmp);
                    else
                        ft_qsort((void**)lineptr, 0, nlines - 1,
                                (int (*)(void*, void*))ft_strcmp);
                }
            }

        }
        writelines(lineptr, nlines);
        close(fd);
        return (0);
    }
    else
    {
        printf("Error: input too big to sort.\n");
        return (1);
    }
}

int ft_getchar(int fd)
{
    int c;

    if (read(fd, &c, 1) < 1)
        return (EOF);
    return (c);
}

int fft_getline(char *s, int lim, int fd)
{
    int i;
    int c;

    i = 0;
    while (i < lim - 1 && (c = ft_getchar(fd)) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return (i);
}

int ft_getline(char *s, int lim)
{
    int i;
    char c;

    i = 0;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return (i);
}

int readlines(char *lineptr[], int maxlines, char *buffer, int fd)
{
    int len, nlines;
    char line[MAXLINE];
    char *p;

    nlines = 0;
    p = buffer;
    while ((len = fft_getline(line, MAXLINE, fd)) > 0)
    {
        if (nlines >= maxlines || (buffer + BUFFERSIZE - p) < len + 1)
            return (-1);
        else
        {
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len + 1;
        }
    }
    return (nlines);
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    {
        printf("%s", *lineptr++);
    }
}

void swap(void *v[], int i, int j)
{
    void *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int ft_strcmp(char *s,  char *t)
{
    while (*s == *t)
    {
        if (*s == '\0')
            return (0);
        s++;
        t++;
    }
    return (*s - *t);
}

char low(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c - 'A' + 'a');
    else
        return (c);
}

int dircheck(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' || (c >= '0' && c <= '9'));
}

int ft_dstrcmp(char *s,  char *t)
{
    int d1, d2, d3;
    while (1)
    {
        if ((d1 = dircheck(*s)) && (d2 = dircheck(*t)) && (d3 = (*s != *t)))
            break;
        if (*s == '\0')
            return (0);
        s++;
        t++;
    }
    return (*s - *t);
}

int ft_rdstrcmp(char *s, char *t)
{
    return (-ft_dstrcmp(s, t));
}

int ft_fdstrcmp(char *s, char *t)
{
    while (1)
    {
        if (dircheck(low(*s)) && dircheck(low(*t)) && (low(*s) != low(*t)))
            break;
        if (*s == '\0')
            return (0);
        s++;
        t++;
    }
    return (low(*s) - low(*t));
}

int ft_rfdstrcmp(char *s, char *t)
{
    return (-ft_fdstrcmp(s, t));
}

int ft_fstrcmp(char *s, char *t)
{
    while (low(*s) == low(*t))
    {
        if (*s == '\0')
            return (0);
        s++;
        t++;
    }
    return (low(*s) - low(*t));
}

int ft_rstrcmp(char *s, char *t)
{
    return (-ft_strcmp(s, t));
}

int ft_rfstrcmp(char *s, char *t)
{
    return (-ft_fstrcmp(s, t));
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return (-1);
    else if (v1 > v2)
        return (1);
    else
        return (0);
}

int rnumcmp(char *s1, char *s2)
{
    return (-numcmp(s1, s2));
}

void ft_qsort(void *v[], int left, int right, int (*comp)(void *op1, void *op2))
{
    int i;
    int last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    i = left + 1;
    while (i <= right)
    {
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
        i++;
    }
    swap(v, left, last);
    ft_qsort(v, left, last - 1, comp);
    ft_qsort(v, last + 1, right, comp);
}
