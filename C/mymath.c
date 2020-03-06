int power(int a, int k)
{
	int n;
	int i;

	n = 1;
	i = 0;
	while (i < k)
	{
		n *= a;
		i++;
	}
	return (n);
}
