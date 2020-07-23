#include <stdio.h>
#include <stdlib.h>

// nbr이 prime인지 확인하는 함수
int	get_prime(int nbr)
{
	int	prime;

	prime = 2;
	while (prime < nbr / prime + 1)
	{
		if (nbr % prime == 0)
			return (0);
		++prime;
	}
	return (1);
}

int	next_prime(int nbr, int max)
{
	int	next;

	next = nbr;
	// nbr 다음 수부터 max까지 소수가 있는지 확인
	while (++next <= max)
	{
		if (get_prime(next))
			return (next);
	}
	// 만약 max까지 소수가 없다면 return -1
	return (-1);
}

int	main(int argc, char **argv)
{
	int num;
	int	prime;

	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num == 1)
		{
			printf("1\n");
			return (0);
		}
		prime = 2;
		// num이 1이 될때까지 연산을 수행
		while (num >= 1)
		{
			// 만약 prime으로 나누어 떨어진다면
			// 이 prime을 일단 유지하고 나눈 값을 다시 넣기
			if (num % prime == 0)
			{
				printf("%d", prime);
				num /= prime;
				// 만약 num이 1이되면 다 나뉘어진 것이므로 탈출
				// 이 조건은 마지막에 *을 쓰지 않기 위해.. 이 위치에만!
				if (num == 1)
					break ;
				printf("*");
			}
			// 만약 이 prime으로는 안나눠 진다면
			// 다음 prime 찾아서 갱신하기
			else
			{
				if (next_prime(prime, num) != -1)
				{
					prime = next_prime(prime, num);
				}
			}
		}
	}
	printf("\n");

	return (0);
}
