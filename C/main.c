#include "mylib.h"

enum e_sosi { LOL, HAHA };

int main(void)
{
    char s[] = "Ahahohohoho";
    char t[] = "ao";

    ft_extended_squeeze(s, t);
    print_str(s);
    ft_putchar('\n');
    return (0);
}
