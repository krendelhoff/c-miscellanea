#include <unistd.h>
#include "buffer_size.h"

char g_buf;
char g_buffer[BUFFER_SIZE];

void ft_putchar(char c)
{
	write(1, &c, 1);
}

char ft_getchar(void)
{
	read(2, &g_buf, 1);
	return (g_buf);
}

void getbuffer(void)
{
	read(2, g_buffer, BUFFER_SIZE);
}

void printint(int n)
{
	int arr[10];
	int i;
	char c;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = n*(-1);
	}
	while (n >= 0)
	{
		arr[i] = n % 10;
		n = n / 10;
		if (n == 0)
			break;
		i++;
	}
	while (i >= 0)
	{
		c = arr[i] + '0';
		ft_putchar(c);
		i--;
	}
}

void printarr(int arr[])
{
	int i = 0;
	char c;

	while (arr[i] != '@')
		{
			printint(arr[i]);
			ft_putchar(' ');
			i++;
		}
	ft_putchar('\n');
}

void printstr(char s[])
{
	int i;
	char c;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
