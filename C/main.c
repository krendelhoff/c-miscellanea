#include "lib/algorithms.h"
#include "lib/myio.h"
#include "lib/mymath.h"

int main(void)
{
	int n;
	int arr[100];
	char s[100] = "123456789";

	print_arr(arr, 0, scan_arr(arr) - 1);
	ft_putchar('\n');
	return (0);
}
