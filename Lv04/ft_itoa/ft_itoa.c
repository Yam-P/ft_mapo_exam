#include <stdlib.h>
#include <stdio.h>

int		get_size(int nbr)
{
	int	cnt;

	cnt = 0;
	while (nbr >= 1)
	{
		++cnt;
		nbr /= 10;
	}	
	return (cnt);
}

char	*ft_itoa(int nbr)
{
	char			*str;
	int				sign;
	unsigned int	nbr_tmp;
	int				arr_size;
	int				idx;

	sign = 0;
	// -~8의 경우, -를 곱하면 int형에서는 overflow이므로 unsigned int로 받기
	if (nbr < 0)
	{
		nbr_tmp = -nbr;
		sign = 1;
	}
	else
		nbr_tmp = nbr;
	// arr_size는 음수인 경우, -를 붙여줄 공간이 필요
	arr_size = sign ? get_size(nbr_tmp) + 1 : get_size(nbr_tmp);
	// 중요한 테크닉!! 할당 가능한 경우, 할당한다.
	if (!(str = (char *)malloc(sizeof(char) * arr_size + 1)))
		return (NULL);
	// 마지막 값을 미리 null로 채워두기!
	str[arr_size] = '\0';
	if (nbr < 0)
		str[0] = '-';
	idx = arr_size - 1;
	while (idx >= sign)
	{
		str[idx] = nbr_tmp % 10 + '0';
		nbr_tmp /= 10;			
		--idx;
	}
	return (str);
}
