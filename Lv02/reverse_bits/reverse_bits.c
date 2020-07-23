unsigned char	reverse_bits(unsigned char octet)
{
	int n;
	unsigned char ret;

	n = 0;
	ret = 0;
	while (n < 8)
	{
		if (octet & (1 << n))
			ret |= 1 << (8 - n - 1);
		++n;
	}
	return (ret);
}
