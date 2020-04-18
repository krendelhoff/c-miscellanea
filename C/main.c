#include "mylib.h"

typedef enum e_sosi { LOL, HAHA } t_sosi;

int main(void)
{
    int i;
    t_sosi eblan;

    i = 0;
    print_int(eblan.LOL);
    while (i < 10)
    {
        ft_putchar('a');
        sleep(1);
        ft_putchar('b');
        sleep(1);
        ft_putchar('\r');
        sleep(1);
        ft_putchar('s');
        sleep(1);
        ft_putchar('o');
        sleep(1);
        ft_putchar('s');
        sleep(1);
        ft_putchar('i');
        sleep(1);
        ft_putchar('\v');
        sleep(1);
    }
    return (0);
}
