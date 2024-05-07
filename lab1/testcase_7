int main()
{
	int a[10], i = 0, j = 0;
	while (i < 10)
	{
		a[i] = 50 - i * 2;
		i = i + 1;
	}
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < i)
		{
			if (a[i] < a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	i = 0;
	while (i < 10)
	{
		write(a[i]);
		i = i + 1;
	}
}
