#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
int strcmp ( const char * str1, const char * str2 );

struct key
{
    char *word;
    int count;
} keytab[] = { {"auto", 0},
               {"bosi_soska", 0},
               {"break", 0},
               {"case", 0},
               {"char", 0},
               {"const", 0},
               {"continue", 0},
               {"default", 0},
               {"define", 0},
               {"getword", 0},
               {"include", 0},
               {"if", 0},
               {"int", 0},
               {"struct", 0},
               {"sizeof", 0},
               {"unsigned", 0},
               {"void", 0},
               {"volatile", 0},
               {"while", 0}
             };

int getword(char *, int);
int binsearch(char *, struct key *, int);

#define NKEYS (sizeof keytab / sizeof (struct key))

int main(void)
{
    unsigned long n;
    char word[MAXWORD];
    // bosi_soska if if if

    while (getword(word, MAXWORD) != EOF)
        if(isalpha(*word))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    n = 0;
    while (n < NKEYS)
    {
        if (keytab[n].count > 0)
            printf("%4d %s\n",
                    keytab[n].count, keytab[n].word);
        n++;
    }
    return (0);
}

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return (mid);
    }
    return (-1);
}

int isvalid(int c)
{
    return (c == '_');
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (c == '"')
        while ((c = getch()) != '"')
            ;
    else if (c == '/')
    {
        if ((c = getch()) == '/')
            while ((c = getch()) != '\n')
                ;
        else
            ungetch(c);
    }
    else if (c == '#')
        while ((c = getch()) != '\n')
            ;
    if (!isalpha(c))
    {
        *w = '\0';
        return (c);
    }
    while (--lim > 0)
    {
        if (!isalnum(*w = getch()) && !isvalid(*w))
        {
            ungetch(*w);
            break;
        }
        w++;
    }
    *w = '\0';
    return (word[0]);
}

