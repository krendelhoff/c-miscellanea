#include "lib/algorithms.h"
#include "lib/myio.h"
#include "lib/mymath.h"

int main(void)
{
	int n;
	int mas[100] = {0};

	print_str("Print an integer: ");
	if (is_prime(n = scan_int()))
	{
		print_str("The number is prime\n");
		print_str("The first ");
		print_int(n);
		print_str(" prime numbers:\n") ;
		print_prime_numbers(n);
		ft_putchar('\n');
		sieve(mas, n);
	}
	else
	{
		print_str("The number is not prime\n");
		print_str("The number's factors: ");
		print_number_factors(n);
		ft_putchar('\n');
	}
		ft_putchar('\n');
	return (0);
}
