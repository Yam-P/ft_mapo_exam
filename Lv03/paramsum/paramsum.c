#include <unistd.h>

void	put_nbr(int nbr)
{
	char	print;

	// 10보다 큰 경우 한 10으로 나눌 수 있으므로 재귀함수 사용
	if (nbr > 10)
	{
		put_nbr(nbr / 10);
		// nbr의 가장 낮은 자리 수부터 연산하며 출력
		print = (char)(nbr % 10) + '0';
		write(1, &print, 1);
	}
	// 10보다 작은 경우 가장 높은 자리 수로 간주하고 출력
	else
	{
		print = (char)(nbr % 10) + '0';
		write(1, &print, 1);
	}

}

int	main(int argc, char **argv)
{
	(void)(argv);
	if (argc > 0)
		put_nbr(argc - 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
