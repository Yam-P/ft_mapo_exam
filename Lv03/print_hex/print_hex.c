#include <unistd.h>

// str을 10진수로 바꾸는 함수
int	ft_atoi(char *str)
{
	int		ret;
	int		idx;
	
	ret = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		// 10씩 곱하며 더해주므로써 10의 자리 숫자를 만들기
		ret = ret * 10 + (int)(str[idx] - '0');
		++idx;
	}
	return (ret);
}

// 10진수를 16진수로 바꾸는 함수
void	ch_hex(int ret)
{
	char	print;
	int		tmp;

	// 16보다 크다면 재귀함수를 수행하여 더 쪼개기
	if (ret > 16)
	{
		ch_hex(ret / 16);
		// print할 숫자가 10이상인 경우 알파벳을 프린트
		tmp = ret % 16;
		print = tmp > 9 ? tmp - 10 + 'a' : tmp + '0';
		write(1, &print, 1); 
	}	
	else
	{
		tmp = ret % 16;
		print = tmp > 9 ? tmp - 10 + 'a' : tmp + '0';
		write(1, &print, 1); 
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ch_hex(ft_atoi(argv[1]));
	}	
	write(1, "\n", 1);
	return (0);
}
