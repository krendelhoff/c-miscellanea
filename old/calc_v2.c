#include <stdio.h>
#include <stdlib.h>
#include "calclib.h"
#include <string.h>
#include <math.h>
#define COMMAND '1'
#define NUMBER '0'
#define VARIABLE '2'
#define MAXOP 100
int main(void)
{
    char s[MAXOP], type;
    double op2, op1, sorry;
    int state = 0;
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("ошибка: деление на нуль\n");
            break;
        case '%':
            op2 = pop();
            op1 = pop();
            if (op2 != 0.0)
                if ((int)op2 == op2 && (int)op1 == op1)
                    push((int)op1 % (int)op2);
                else
                    printf("ошибка: не целые операнды\n");
            else
                printf("ошибка: деление на нуль\n");
            break;
        case '\n':
            if (state)
            {
                state = 0;
                continue;
            }
            else
                printf("\t%.8g\n", sorry = pop());

            break;
        case COMMAND:
            if (checkcom(s, "sin"))
                push(sin(pop()));
            if (checkcom(s, "last"))
                push(sorry);
            if (checkcom(s, "exp"))
                push(exp(pop()));
            if (checkcom(s, "pow"))
            {
                op2 = pop();
                push(pow(pop(), op2));
            }
            if (checkcom(s, "topel"))
            {
                printf("Верхний элемент стека: %g\n", topel());
                state = 1;
            }
            if (checkcom(s, "stack"))
            {
                printstack();
                state = 1;
            }
            if (checkcom(s, "copytop"))
            {
                copytop();
                state = 1;
            }
            if (checkcom(s, "result"))
            {
                printf("Result: %g\n", result());
                state = 1;
            }
            if (checkcom(s, "clear"))
            {
                clear();
                state = 1;
            }
            if (checkcom(s, "changetop"))
            {
                changetop();
                state = 1;
            }
            if (1)
            {
                if (checkcom(s, "a"))
                    push(var[0]);
                if (checkcom(s, "b"))
                    push(var[1]);
                if (checkcom(s, "c"))
                    push(var[2]);
                if (checkcom(s, "d"))
                    push(var[3]);
                if (checkcom(s, "e"))
                    push(var[4]);
                if (checkcom(s, "f"))
                    push(var[5]);
                if (checkcom(s, "g"))
                    push(var[6]);
                if (checkcom(s, "h"))
                    push(var[7]);
                if (checkcom(s, "i"))
                    push(var[8]);
                if (checkcom(s, "j"))
                    push(var[9]);
                if (checkcom(s, "k"))
                    push(var[10]);
                if (checkcom(s, "l"))
                    push(var[11]);
                if (checkcom(s, "m"))
                    push(var[12]);
                if (checkcom(s, "n"))
                    push(var[13]);
                if (checkcom(s, "o"))
                    push(var[14]);
                if (checkcom(s, "p"))
                    push(var[15]);
                if (checkcom(s, "q"))
                    push(var[16]);
                if (checkcom(s, "r"))
                    push(var[17]);
                if (checkcom(s, "s"))
                    push(var[18]);
                if (checkcom(s, "t"))
                    push(var[19]);
                if (checkcom(s, "u"))
                    push(var[20]);
                if (checkcom(s, "v"))
                    push(var[21]);
                if (checkcom(s, "w"))
                    push(var[22]);
                if (checkcom(s, "x"))
                    push(var[23]);
                if (checkcom(s, "y"))
                    push(var[24]);
                if (checkcom(s, "z"))
                    push(var[25]);
            }
            break;
        case '$':
            state = 1;
            continue;
        default:
            printf("ошибка: неизвестная операция %s\n", s);
            break;
        }
    }
    return 0;
}
