#include "lib/algorithms.h"
#include "lib/myio.h"
#include "lib/mymath.h"

int main(void)
{
	int n;
	int arr[100];
	char s[100] = "123456789";

	print_str(s);
	ft_putchar('\n');
	cyclic_shift_right_str(s);
	print_str(s);
	ft_putchar('\n');
	cyclic_shift_right_str(s);
	print_str(s);
	ft_putchar('\n');
	cyclic_shift_right_str(s);
	print_str(s);
	ft_putchar('\n');
	cyclic_shift_right_str(s);
	print_str(s);
	ft_putchar('\n');
	return (0);
}
