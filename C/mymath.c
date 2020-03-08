double power(int a, int k)
{
	double n;
	int i;

	n = 1;
	i = 0;
	if (k >= 0)
		while (i < k)
		{
			n *= a;
			i++;
		}
	else
		while (i > k)
		{
			n /= a;
			i--;
		}
	return (n);
}
