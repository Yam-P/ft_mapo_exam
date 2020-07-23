int	max(int *tab, unsigned int len)
{
	unsigned int	idx;
	int	max;
	
	// 조건에 따라 size가 0인 array를 받으면 0 출력
	if (len == 0)
		return (0);
	idx = 0;
	// 기본적으로 max를 array 첫 값을 기준으로.
	max = tab[idx++];
	while (idx < len) 
	{
		// loop를 돌며 max보다 큰 값이 있다면 값 갱신
		max = tab[idx] > max ? tab[idx] : max;
		++idx;
	}
	return (max);
}
