#include <unistd.h>
#include "algorithms.h"
#include "mymath.h"
#include "myio.h"

char g_buf;
char g_buffer[BUFFER_SIZE];
int  g_i = -1;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

char ft_getchar(void)
{
	read(2, &g_buf, 1);
	return (g_buf);
}

char getbufchar(void)
{
	char c;

	if (g_i < 0)
		return (ft_getchar());
	else
		{
			c = g_buffer[g_i];
			g_i--;
			return (c);
		}
}

void putinbuf(char c)
{
	g_i++;
	g_buffer[g_i] = c;
}

int scan_line(char s[])
{
	int i;
	char c;

	i = 0;
	while ((c = ft_getchar()) != '\n' && i < BUFFER_SIZE)
	{
		s[i] = c;
		i++;
	}
	if (c == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (i);
}

int scan_word(char s[])
{
	int i;
	char c;

	i = 0;
	while ((c = ft_getchar()) != ' ' && c != '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return (i);
}

int scan_int(void)
{
	char c;
	int sign;
	int i;
	char s[100];

	i = 0;
	while (((c = getbufchar()) >= '0' && c <= '9') ||
		   c == '-')
		{
			s[i] = c;
			i++;
		}
	s[i] = '\0';
	if (c == '\n')
		putinbuf(c);
    return (str_to_int(s));
}

int scan_arr(int arr[])
{
	int i;
	char c;

	i = 0;
	while ((c = getbufchar()) != '\n')
	{
		putinbuf(c);
		arr[i] = scan_int();
		i++;
	}
	return (i);
}

void print_int(int n)
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

void print_arr(int arr[], int first, int last)
{
	int i = 0;
	char c;

	i = first;
	while (i <= last)
		{
			print_int(arr[i]);
			ft_putchar(' ');
			i++;
		}
	ft_putchar('\n');
}

void print_str(char s[])
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
