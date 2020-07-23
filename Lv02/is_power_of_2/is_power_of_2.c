int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (1)
	{
		// 3. n이 2일때는 바로 탈출하기
		if (n == 2)
			return (1);
		// 1. 2의 거듭제곱은 2로 나눴을 때 나머지가 0이므로!
		if (n % 2 != (0))
			return (0);
		// 2. n이 2일때 2로 나누면 나머지가 1이 돼서 return 0이 되므로
		n /= 2;
	}
	return (1);
}
