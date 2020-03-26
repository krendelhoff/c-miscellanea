#include "mylib.h"

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

int scan_line(char s[], int lim)
{
	int i;
	char c;

	i = 0;
	while ((c = getbufchar()) != '\n' &&
		   i < lim - 1)
	{
		s[i] = c;
		i++;
	}
	if (c == '\n')
	{
		s[i] = '\n';
		i++;
	}
	else
		putinbuf(c);
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
		if ((c >= '0' && c <= '9') || c == '-')
			putinbuf(c);
		arr[i] = scan_int();
		i++;
	}
	return (i);
}

void print_int(int n)
{
	int i;
	char c;
	int arr[10];

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
		ft_putchar(arr[i] + '0');
		i--;
	}
}

void print_arr(int arr[], int first, int last)
{
	int i;
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

void print_float(double n, int signs)
{
	int i;
	double k;
	int state;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = n*(-1);
	}
	print_int((int) n);
	ft_putchar('.');
	k = n - (int) n;
	if (n != (int) n)
		while (i < signs)
		{
			k *= 10;
			print_int((int) k);
			i++;
			k -= (int) k;
		}
	else
		while (i++ < signs)
			print_int(0);
}
