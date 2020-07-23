#include <unistd.h>

int	main(int argc, char **argv)
{
	int cnt;
	int	len;

	cnt = 0;
	if (argc == 3)
	{
		// 찾고자하는 문자열의 길이 구해두기
		while (argv[1][len] != '\0')
			++len;
		while (*argv[2] != '\0')
		{
			// 매칭 된다면, cnt증가 시키고, 찾고자하는 문자열 pos증가
			if (*argv[1] == *argv[2])
			{
				++cnt;
				++argv[1];
			}
			++argv[2];
		}
		if (cnt == len)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
