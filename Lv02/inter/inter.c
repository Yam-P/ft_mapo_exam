#include <stdio.h>
#include <unistd.h>

char	prev_char;

void	make_unique(char *str)
{
	int	char_
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[j] != '\0')
		{

		}
		while (str[idx
		++i;
	}

}

void	compare(char c, char *str)
{
	int idx;

	idx = 0;
	// 3. argv[1]의 index 요소 하나하나를 비교해보기
	while (str[idx] != '\0')
	{
		// 4. 이 전에 prev_char에 담아둔 요소가 지금 c와 다를 때
		// 출력하기 (중복을 없애기 위한 전략)
		if (c == str[idx] && c != prev_char)
		{
			write(1, &c, 1);
			// 5. 지금 값을 나중에는 출력하지 않기 위해
			// 	  값을 갱신하기
			prev_char = c;
		}
		++idx;
	}

}

int		main(int argc, char **argv)
{
	int	idx;

	idx = 0;
	// 1. 핵심: 중복을 막기 위한 전역변수!
	prev_char = 0;
	// 2. argv[1] 각 요소가 argv[2] 각요소 안에 있는지 
	// 	  루프 돌면서 확인하기
	while (argc == 3 && argv[1][idx] != '\0')
	{
		compare(argv[1][idx], argv[2]);
		++idx;
	}
	write(1, "\n", 1);	
	return (0);
}
