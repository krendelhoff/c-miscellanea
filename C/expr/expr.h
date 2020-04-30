#ifndef EXPR_H

# define EXPR_H
# include "libft.h"
# define NUMBER '0'
# define MAXOP 100

double pop(void);
void   push(double n);
int    getch(void);
void   ungetch(char c);
void   ungets(char *s);
int    getop(char *s);

#endif
