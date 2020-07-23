#include <unistd.h>

int	ch_alpha(char c)
{
	char	tmp;

	// 2. z보다 작을때 까지는 +1
	if ((c >= 'a' && c < 'z') 
		|| (c >= 'A' && c < 'Z'))
	{
		tmp = c + 1;
		write(1, &tmp, 1);
		return (1);
	}
	// 3. z이면 a로 
	else if (c == 'z' || c == 'Z')
	{
		tmp = c - 25;
		write(1, &tmp, 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int 	idx;

	idx = 0;
	while (argc == 2 && argv[1][idx] != '\0')
	{
		// 1. 조건에 부합하면 함수 안에서 write
		//    조건에 부합하지 않으면 if 안에서 write
		if (!ch_alpha(argv[1][idx]))
			write(1, &argv[1][idx], 1);
		++idx;
	}
	write(1, "\n", 1);

	return 0;
}
