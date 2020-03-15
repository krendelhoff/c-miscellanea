#include "../C/lib/myio.h"
#include "../C/lib/algorithms.h"
#define N 7

int main(void)
{
	int arr[N];
	int i;
	int k;
	int j; /* flag */

	scan_arr(arr);
	i = k = 0;
	j = 1;
	while (i < N)
	{
		if (j && arr[i] > 100 && arr[i] % 5 == 0)
			k++;
		i++;
		if (j && i == N)
			i = j = 0;
		if (!j && arr[i] > 100 && arr[i] % 5 == 0)
			arr[i] = k;
	}
	print_arr(arr, 0, N - 1);
	return (0);
}
