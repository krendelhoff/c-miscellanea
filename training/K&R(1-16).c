#include "mylib.h"
#define LIM 10

int main(void)
{
    int n;
    int sum;
    char s[BUFFER_SIZE];

    while ((n = scan_line(s, LIM)) > 0)
    {
        sum = 0;
        print_str("Line: ");
        while (n == (LIM - 1) && s[LIM - 2] != '\n')
        {
            print_str(s);
            sum += n;
            n = scan_line(s, LIM);
        }
        print_str(s);
        sum += n;
        print_str("Number of chars: ");
        print_int(sum - 1);
        ft_putchar('\n');
    }
    ft_putchar('\n');
    return (0);
}
