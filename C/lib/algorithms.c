#include "mymath.h" /* my lib with simple algorithms */
#include "myio.h"

int cache[100] = {0};

void swap_int(int arr[], int b, int f)
{
	int temp;

	temp = arr[b];
	arr[b] = arr[f];
	arr[f] = temp;
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

void selection_sort(int arr[], int first, int last)
{
	int current;
	int min_index;
	int i;

	current = first;
	while (current <= (last - 1))
	{
		min_index = current;
		i = current + 1;
		while (i <= last)
		{
			if (arr[i] < arr[min_index])
				min_index = i;
			i++;
		}
		swap_int(arr, current, min_index);
		current++;
	}
}

void insertion_sort(int arr[], int first, int last)
{
	int current;
	int i;

	current = first + 1;
	while (current <= last)
	{
		i = current;
		while (i > 0 && arr[i - 1] > arr[i])
		{
			swap_int(arr, i - 1, i);
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

int is_prime(int n)
{
	int divisor;

	divisor = 2;
	while (power(divisor, 2) <= n)
	{
		if (n % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
}

void print_prime_numbers(int n)
{
	int i;

	i = 2;
	while (n >= 0)
	{
		if (is_prime(i))
		{
			print_int(i);
			ft_putchar(' ');
			n--;
		}
		i++;
	}
}

void print_number_factors(int n)
{
	int divisor;
	int original;

	divisor = 2;
	original = n;
	while (n != 1)
	{
		while (n % divisor == 0)
		{
			n /= divisor;
			print_int(divisor);
			print_str(" ");
		}
		divisor++;
	}
}

void sieve(int arr[], int n)
{
	int i;
	int k;

	i = 2;
	while (i*i < n)
	{
		k = i*i;
		if (arr[i] == 0)
			while (k < n)
			{
				arr[k] = 1;
				k += i;
			}
		i++;
	}
	print_arr(arr, 0, n);
}

void initialize_by_zero(int arr[], int length)
{
	int i;

	i = 0;
	while (i < length)
		arr[i++] = 0;
}

void reverse_arr(int arr[], int first, int last)
{
	while (first <= (first + last)/2)
	{
		swap_int(arr, first, last);
		first++;
		last--;
	}
}

void swap_char(char s[], int b, int f)
{
	int temp;

	temp = s[b];
	s[b] = s[f];
	s[f] = temp;
}

void reverse_str(char s[])
{
	int first;
	int last;

	first = 0;
	last = strlength(s) - 1;
	while (last > first)
	{
		swap_char(s, first, last);
		first++;
		last--;
	}
}

void cyclic_shift_left_str(char s[])
{
	int temp;
	int i;

	temp = s[0];
	i = 0;
	while (i < strlength(s) - 1)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[i] = temp;
}

void cyclic_shift_right_str(char s[])
{
	int temp;
	int i;

	temp = s[strlength(s) - 1];
	i = strlength(s) - 1;
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	s[0] = temp;
}

int fibonacci(int n)
{
	if (n <= 1)
		return (n);
	if (cache[n] != 0)
		return (cache[n]);
	return (cache[n] = fibonacci(n - 1) + fibonacci(n - 2));
}
