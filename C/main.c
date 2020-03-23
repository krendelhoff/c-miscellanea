#include "algorithms.h"
#include "myio.h"
#include "mymath.h"
# define N 45


int main(void)
{
	int n;
	int i;

	i = N;
	print_str("Enter the number of the fibonacci term: ");
	n = scan_int();
	print_int(n);
	ft_putchar('\n');
	while (i > 0)
	{
		print_str("The ");
		print_int(N - i + 1);
		print_str(" number of fibonacci is ");
		print_int(fibonacci(N - i + 1));
		ft_putchar('\n');
		i--;
	}
	ft_putchar('\n');
	return (0);
}
