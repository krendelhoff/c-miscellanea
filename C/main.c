#include "mylib.h"

int main(void)
{
	int n;
	int i;
	int m;

	i = 25;
	n = 22;
	m = n ^ i;
	print_int(m);
	ft_putchar('\n');
	return (0);
}
