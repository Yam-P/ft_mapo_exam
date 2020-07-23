#include <stdio.h>
#include <stdlib.h>

int	find_div(int num1, int num2)
{
	int	div;
	// 둘 중 작은 값 부터 시작해서 점점 줄임
	// 줄이던 값이 두 수 모두에 나누어 떨어질때 공약수이며
	// 가장 처음 값이 최대 공약수임. 
	div = num1 >= num2 ? num1 : num2;
	while (div--)
	{
		if (num1 % div == 0 && num2 % div == 0)
		{
			return (div);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%d", find_div(atoi(argv[1]), atoi(argv[2])));
	}
	printf("\n");
	return (0);
}
