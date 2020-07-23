#include <unistd.h>

int	mirror(char c)
{
	int		dist;
	char	dist_rev;
	char	beg;
	char	end;
	
	if (c >= 'a' && c <= 'z')
	{
		beg = 'a';
		end = 'z';
	}
	else if ( c >= 'A' && c <= 'Z')
	{
		beg = 'A';
		end = 'Z';
	}
	// 2. 알파벳이 아닌 경우 조건에 부합 안함
	else
	{
		return (0);
	}
	// 3. 시작지점으로부터의 거리를 계산해두었다가
	dist = (int)(c - beg);
	// 4. 끝점에서 그 거리를 빼기
	dist_rev = (char)(end - dist);
	write(1, &dist_rev, 1);
	return (1);
}

int	main(int argc, char **argv)
{
	int	idx;

	idx = 0;
	while (argc == 2 && argv[1][idx])
	{
		// 1. 조건에 부합하지 않으면 그대로 출력
		// 	  조건에 부합하면 함수 내부에서 출력
		if (!mirror(argv[1][idx]))
			write(1, &argv[1][idx], 1);
		++idx;
	}
	write(1, "\n", 1);
	return (0);
}
