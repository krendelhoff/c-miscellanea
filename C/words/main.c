#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int strcmp ( const char * str1, const char * str2 );

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
char *strdup(const char *str);

int main(void)
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(*word))
            root = addtree(root, word);
    treeprint(root);
    return (0);
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
    if (!isalpha(c))
    {
        *w = '\0';
        return (c);
    }
    while (--lim > 0)
    {
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
        w++;
    }
    *w = '\0';
    return (word[0]);
}

struct tnode *talloc(void);
//char *strdup(char *);
#include <stdlib.h>

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return (p);
}

void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}


struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/*char *strdup(char *s)
{
    char *p;

    p = (char *)malloc(strlen(s) + 1);*/ /* +1 for '\0' */
/*    if (p != NULL)
        strcpy(p, s);
    return (p);
}*/
