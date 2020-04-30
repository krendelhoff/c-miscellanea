#include "expr.h"

int main(int argc, char *argv[])
{
    double op2;
    char s[MAXOP];
    int c;

    if (argc == 1)
        print_str("Usage: ./expr <expression>\n");
    while (--argc > 0)
    {
        ungets(*(++argv));
        c = getop(s);
        if (c == NUMBER)
            push(ft_atof(s));
        else if (c == '+')
            push(pop() + pop());
        else if (c == '-')
        {
            op2 = pop();
            push(pop() - op2);
        }
        else if (c == '*')
            push(pop() * pop());
        else if (c == '/')
        {
            op2 = pop();
            push(pop() / op2);
        }
        else if (c == '%')
        {
            op2 = pop();
            if (op2 > 0.0)
                push((int)pop() % (int)op2);
            else
                print_str("Division by zero is restricted.\n");
        }
        else
        {
            print_str("Unknown command.\n");
            argc = 1;
        }
    }
    print_float(pop(), 5);
    ft_putchar('\n');
    return (0);
}
