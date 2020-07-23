#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\b' || c == '\t')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	idx;
	int	save;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	idx = 0;
	while (argv[1][idx])
	{
		// white space부터 있으면 넘기기
		while (argv[1][idx] && is_space(argv[1][idx]))
			++idx;
		save = idx;
		// word의 시작을 기억해두기
		while (argv[1][idx] && !is_space(argv[1][idx]))
			++idx;
		// 끝의 white space 넘기기
		while (argv[1][idx] && is_space(argv[1][idx]))
			++idx;
		// NULL이어서 끝난 경우.  word만 출력하기
		if (argv[1][idx] == '\0')
		{
			while (argv[1][save])
			{
				if (!is_space(argv[1][save]))
					write(1, &argv[1][save], 1);
				++save;
			}
		}
	}
	return (0);
}
