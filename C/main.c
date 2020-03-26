#include "mylib.h"

int main(void)
{
	int n;
	char s[]="       I       love            you    ti     suka! !!";

	remove_trailing_spaces(s);
	print_str(s);
	ft_putchar('\n');
	return (0);
}
