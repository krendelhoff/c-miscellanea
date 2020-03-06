#include <stdio.h>
#include "algorithms.h"
#include "myio.h"
#include "buffer_size.h"

char g_buffer[BUFFER_SIZE];

int main(void)
{
	int arr[] = {5, 3, 4, 1, 2, 98, 23, 56, 7, 8, 0, '@'};
	char m;
	int i;

	/*i = 0;
	m = 'm';
	insertion_sort(arr);
	printarr(arr);
	printf("Position number of 4 is: %d\n",
		   binary_search(arr, arrlen(arr), 0, 4));
	printf("%d\n", arrlen(arr));
	printstr("sosi daun\n");*/
	getbuffer();
	printstr(g_buffer);
	return (0);
}
