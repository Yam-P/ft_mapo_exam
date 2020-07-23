unsigned int	hcf(unsigned int a, unsigned int b)
{
	int	ret;

	ret = a < b ? a : b;
	while (ret >= 1)
	{
		if (a % ret == 0 && b % ret == 0)
			return (ret);	
		--ret;
	}
	return (1);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	return (a * b / hcf(a, b));
}
