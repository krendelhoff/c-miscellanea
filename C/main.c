#include "algorithms.h"
#include "myio.h"
#include "mymath.h"

int main(void)
{
	int mas[100];
	int length;

	print_int(length = scan_arr(mas));
	ft_putchar('\n');
	print_arr(mas, 0, length - 1);
	ft_putchar('\n');
	return (0);
}
