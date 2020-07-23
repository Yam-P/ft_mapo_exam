#include <unistd.h>

int	ch_alpha(char c)
{
	char tmp;

	// 3. 대문자면 소문자로, 소문자면 대문 바꾸기
	if (c >= 'a' && c <= 'z')
	{
		tmp = c + ('A' - 'a');
		write(1, &tmp, 1);	
		return (1);
	}
	else if (c >= 'A' && c <= 'z')
	{
		tmp = c + ('a' - 'A');
		write(1, &tmp, 1);	
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	idx;

	idx = 0;
	// 1. 매개변수가 하나인 경우에만 while문에 들어감
	while (argc == 2 && argv[1][idx])
	{
		// 2. 조건에 부합하지 않으면 그대로 출력
		//	  부합하면 ch_alpha에서 출력
		if (!ch_alpha(argv[1][idx]))
			write(1, &argv[1][idx], 1);
		++idx;
	}
	write(1, "\n", 1);

	return (0);
}
