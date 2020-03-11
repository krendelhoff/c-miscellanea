#include "mymath.h"
#include "myio.h"

/* my lib with simple algorithms */
 * meow */
void swap(int arr[], int b, int f)
{
	int temp;

	temp = arr[b];
	arr[b] = arr[f];
	arr[f] = temp;
}

int arrlen(int arr[])
{
	int i;

	i = 0;
	while (arr[i] != '@')
		i++;
	return (i);
}

int strlength(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int find(char s[], char c)
{
	int i;
	int state;

	i = state = 0;
	if (s[i] == '-')
		{
			i++;
			state = -1;
		}
	while (s[i] != c && i < strlength(s))
		i++;
	return (i + state);
}
int str_to_int(char s[])
{
	int length;
	int i;
	int n;
	int sign;

	n = i = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	length = find(s, '.');
	while (i < strlength(s))
		{
			n += (s[i] - '0')*power(10, --length);
			i++;
		}
	return (sign*n);
}

double str_to_float(char s[])
{
	int length;
	int i;
	double n;
	int sign;

	n = i = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	length = find(s, '.');
	while (s[i] != '.' && i < strlength(s))
	{
		n = n + (s[i] - '0')*power(10, --length);
		i++;
	}
	length = i++;
	while (i < strlength(s))
	{
		n += (s[i] - '0')*power(10, length - i);
		i++;
	}
	return (n*sign);
}

int binary_search(int arr[], int hi, int lo, int n)
{
	int mid;

	while (lo <= hi)
	{
		if ((lo + hi) % 2 == 0)
			mid = (lo + hi)/2;
		else mid = (lo + hi)/2 + 1;
		if (n == arr[mid])
			return (mid);
		if (n > arr[mid])
			lo = mid + 1;
		if (n < arr[mid])
			hi = mid - 1;
	}
	return (-1);
}

void selection_sort(int arr[])
{
	int current;
	int min_index;
	int i;

	current = 0;
	while (current <= (arrlen(arr) - 2))
	{
		min_index = current;
		i = current + 1;
		while (i <= arrlen(arr) - 1)
		{
			if (arr[i] < arr[min_index])
				min_index = i;
			i++;
		}
		swap(arr, current, min_index);
		current++;
	}
}

void insertion_sort(int arr[])
{
	int current;
	int i;

	current = 1;
	while (current < arrlen(arr))
	{
		i = current;
		while (i > 0 && arr[i - 1] > arr[i])
		{
			swap(arr, i - 1, i);
			i--;
		}
		current++;
	}
}

int factorial(int n)
{
	int m;

	m = 1;
	while (n > 0)
		m *= (n--);
	return m;
}
