#include <unistd.h>

// 
int	ft_atoi(char *str)
{
	int	ret;

	ret = 0;
	while (*str != '\0')
	{
		ret = ret * 10 + (int)(*str - '0');
		++str;
	}
	return (ret);
}

// prime num인지 check하는 코드
int	check_prime(int num)
{
	int	j;

	j = 2;
	while (j < num)
	{
		if (num % j == 0)
			return(0) ;
		++j;
	}
	return (1);
}

int	add_prime_sum(int num)
{
	int	ret;
	int i;

	ret = 0;
	// i는 num까지의 모든 수
	i = 2;
	while (i <= num)
	{
		// i가 소수인지 확인하는 코드
		// 소수라면 ret에 누적해서 합하기
		if (check_prime(i))
			ret += i;
		++i;
	}
	return (ret);
}

void	print_nbr(int nbr)
{
	char	print;

	if (nbr >= 10)
	{
		print_nbr(nbr / 10);
		print = (char)(nbr % 10) + '0';
		write(1, &print, 1);
	}
	else
	{
		print = (char)(nbr % 10) + '0';
		write(1, &print, 1);
	}
}

int	main(int argc, char **argv)
{
	int	num;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		if (num > 0)
		{
			print_nbr(add_prime_sum(num));
		}
	}	
	else
		write(1, "0", 1);
	write(1, "\n", 2);
	return (0);
}
