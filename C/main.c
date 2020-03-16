#include "lib/algorithms.h"
#include "lib/myio.h"
#include "lib/mymath.h"
#define size 100

int main(void)
{
	int n;
	int i;
	int arr[size];

	i = 0;
	while (i < size)
	{
		arr[i] = size - 1 - i;
		i++;
	}
	print_arr(arr, 0, size - 1);
	ft_putchar('\n');
	insertion_sort(arr, 0, size - 1);
	print_arr(arr, 0, size - 1);
	ft_putchar('\n');
	return (0);
}
