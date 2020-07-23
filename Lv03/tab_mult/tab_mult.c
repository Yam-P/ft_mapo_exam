#include <unistd.h>
#include <stdio.h>

void	put_nbr(int nbr)
{
	char	print;

	// nbr이 10보다 크면 재귀
	if (nbr > 10)
	{
		put_nbr(nbr / 10);
		print = (char)(nbr % 10) + '0';
		write(1, &print, 1);
	}
	// nbr이 10보다 작은 경우 더 이상 나눌 수가 없으므로 출력하며 빠져나옴
	else
	{
		print = nbr % 10 + '0';
		write(1, &print, 1);
	}
}

int		ft_atoi(char *nbr)
{
	int	ret;

	ret = 0;
	while (*nbr != '\0')
	{
		// 기존 수에 10을 곱하고 끝자리를 더하는 식으로
		// 누적해서 각 자릿수를 만들어가기.
		ret = 10 * ret + (int)(*nbr - '0');
		++nbr;
	}
	return (ret);
}

void	tab_mult(int nbr, int idx)
{
	char	print;

	print = idx + '0';
	write(1, &print, 1);
	write(1, " x ", 3);
	put_nbr(nbr);
	write(1, " = ", 3);
	put_nbr(nbr * idx);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	idx;

	if (argc == 2)
	{
		idx = 0;
		while (++idx < 10)
			// 곱하게 되는 수를 idx. 차례로
			tab_mult(ft_atoi(argv[1]), idx);
	}
	else
		write (1, "\n", 1);	

	return (0);
}
