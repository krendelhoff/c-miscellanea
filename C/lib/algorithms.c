#include "mylib.h" /* my lib with simple algorithms */
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

void remove_term(char s[], int index)
{
	int i;

	while(index < strlength(s))
	{
		s[index] = s[index + 1];
		index++;
	}
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
        else
            mid = (lo + hi)/2 + 1;
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

void   remove_trailing_spaces(char s[])
{
	int i;
	int k;

	k = i = 0;
	while (s[i] == ' ')
        {
            remove_term(s, i);
        }
        while (i < strlength(s))
        {
            if (s[i] == ' ')
                k++;
            else
                k = 0;
            if (k > 1)
            {
                remove_term(s, i);
                k--;
                print_str(s);
                continue;
            }
            i++;
        }
}

int euclidus(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return (a);
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
int fast_euclidus(int a, int b)
{
    int tmp;

    if (b > a)
        swap(&a, &b);
    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return (a);
}

int gcd_expanded(int a, int b, int *x, int *y)
{
    int x1;
    int y1;
    int d;

    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return (b);
    }
    d = gcd_expanded(b%a, a, &x1, &y1);
    *x = y1 - (b / a)*x1;
    *y = x1;
    return (d);
}

void merge(int arr[], int left, int middle, int right)
{
    int i;
    int j;
    int k;
    int L[middle - left + 1];
    int R[right - middle];

    int n1;
    int n2;

    n1 = middle - left + 1;
    n2 = right - middle;
    i = 0;
    while (i < n1)
    {
        L[i] = arr[left + i];
        i++;
    }
    i = 0;
    while (i < n2)
    {
        R[i] = arr[middle + 1 + i];
        i++;
    }
    i = j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    int middle;

    if (left < right)
    {
        middle = (left + right) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int partition(int *arr, int left, int right)
{
    int pivot;
    int i;
    int j;

    i = left - 1;
    pivot = arr[right];
    j = left;
    while (j <= right - 1)
    {
        if (arr[j] < pivot)
            i++;
        j++;
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quick_sort(int *arr, int left, int right)
{
    int pivot;

    if (left < right)
    {
        pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

int ft_atoi(char s[])
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (s[i] >= '0' && s[i] <= '9')
    {
        ft_putchar(s[i]);
        ft_putchar(' ');
        n = 10 * n + (s[i] - '0');
        print_int(n);
        ft_putchar('\n');
        i++;
    }
    return (n);
}

int hex(char c)
{
    if (c >= '0' && c <= '9')
    {
        return (c - '0');
    }
    else if (c == 'A' || c == 'a')
    {
        return (10);
    }
    else if (c == 'B' || c == 'b')
    {
        return (11);
    }
    else if (c == 'C' || c == 'c')
    {
        return (12);
    }
    else if (c == 'D' || c == 'd')
    {
        return (13);
    }
    else if (c == 'E' || c == 'e')
    {
        return (14);
    }
    else if (c == 'F' || c == 'f')
    {
        return (15);
    }
    else
    {
        print_str("Wrong number!\n");
        exit(1);
    }
}

int ft_htoi(char s[])
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (s[i] != '0' && (s[i + 1] != 'x' || s[i + 1] != 'X'))
    {
        print_str("Error!\n");
        exit(1);
    }
    i += 2;
    while (s[i] != '\0')
    {
        n = hex(s[i]) + 16 * n;
        i++;
    }
    return (n);
}

void ft_squeeze(char s[], int c)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}

void ft_strcat(char s[], char t[])
{
    int i;
    int j;
    int l;

    j = 0;
    i = strlength(s);
    while ((s[i] = t[j]) != '\0')                                    /* while ((s[i++] = t[j++]) != '\0'); possible */
    {
        i++;
        j++;
    }
}

int find_char(char s[], char c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (TRUE);
        i++;
    }
    return (FALSE);
}

void ft_extended_squeeze(char s[], char t[])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        if (find_char(t, s[i]))
            ft_squeeze(s, s[i]);
        i++;
    }
}
