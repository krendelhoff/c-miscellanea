#ifndef CALCLIB_H
#define CALCLIB_H
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "library.h"
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'
#define COMMAND '1'
#define VARIABLE '2'
double var[26];
char buf[BUFSIZE];
int bufp = 0;
int sp = 0;
int buf_one = 0;
double val[MAXVAL];
void push(double f)
{
    	if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ошибка: стек полон, %g не помещается\n", f);
}
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("ошибка: стек пуст\n");
        return 0.0;
    }
}
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int ch)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = ch;
}
/*void ungetch_one(int c)
{
    buf_one = c;
}*/
int getch_one(void)
{
    int k = buf_one;
    if (buf_one)
    {
        buf_one = 0;
        return k;
    }
    else return getchar();
}
void ungets(char s[])
{
    for (int i = length(s) - 1; i >= 0; i--)
        ungetch(s[i]);
}
void setVar(char s[], char c)
{
    s[0] = c;
    var[s[0] - 'a'] = val[sp];
    s[1] = '\0';
}
int topp(void)
{
    int i = 0;
    while (val[i])
        i++;
    return i - 1;
}
double topel(void)
{
    return val[topp()];
}
double result(void)
{
    return val[sp];
}
void copytop(void)
{
    int p = topp();
    val[p + 1] = val[p];
    sp++;
}
void clear(void)
{
    int i = 0;
    while (val[i])
    {
        val[i++] = 0;
    }
}
void changetop(void)
{
    double temp;
    int p = topp();
    temp = val[p];
    val[p] = val[p - 1];
    val[p - 1] = temp;
}
void printstack(void)
{
    for (int i = 0; i < 10; i++)
        printf("%g ", val[i]);
    putchar('\n');
}
void getcom(char s[])
{
    int i;
    char c;
    for (i = 1; !isspace(c = getchar());)
    {
        s[i++] = c;
    }
    s[i] = '\0';
    ungetch(c);
}
int checkcom(char s[], char ss[])
{
    int i;
    // printf("%d %d ", length(s), length(ss));
    for (i = 0; i < length(ss) && s[i] == ss[i]; i++)
        // printf("%d ", i);
        ;
    //putchar('\n');
    if ((length(s) == length(ss)) && i == length(ss))
        return 1;
    else
        return 0;
}
int getop(char s[])
{
    int i, c;
    char sign;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '$')
    {
        c = getch();
        setVar(s, c);
        return '$';
    }
    if (c >= 'a' && c <= 'z')
    {
        getcom(s);
        return COMMAND;
    }
    i = 0;
    if (c == '-')
    {
        if (isdigit(sign = getch()))
        {
            s[i++] = '-';
            s[i] = sign;
            c = sign;
        }
        else
        {
            ungetch(sign);
            return c;
        }
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    i++;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
#endif
