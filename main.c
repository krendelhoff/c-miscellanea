#include <stdio.h>
#include "proto-header.h"

int main(void)
{
	int arr[] = {5, 3, 4, 1, 2, 98, 23, 56, 7, 8, 0, '\0'};
	char m;

	insertion_sort(arr);
	printarr(arr);
	printf("Position number of 4 is: %d\n",
		   binary_search(arr, arrlen(arr), 0, 4));
	printf("%d\n", arrlen(arr));
	ft_putchar('p');
	ft_putchar('\n');
	m = ft_getchar();
	ft_putchar(m);
	ft_putchar('\n');
	return 0;
}
