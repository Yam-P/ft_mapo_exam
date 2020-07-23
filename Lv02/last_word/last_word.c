#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

// 현재 위치를 가리키는 포인터의 값이 alpha일 때 증가
// white space일 때 증가시키므로 반환하는 pos는
// 다음 단어의 시작 혹은 null이 될 것임.
char *next_word(char *str)
{
	char	*pos;
	pos = str;
	while (is_alpha(*pos))
		++pos;
	while (is_space(*pos))
		++pos;
	return (pos);
}

int	main(int argc, char **argv)
{
	char	*next_pos;
	char	*word_beg;

	word_beg = argv[1];
	if (argc == 2)
	{
		while (*word_beg)
		{
			next_pos = next_word(word_beg);
			// 다음 단어를 가리키는 pos가 널일 때
			if (*next_pos == '\0')
			{
				// 알파벳인 경우까지만 출력
				while (is_alpha(*word_beg))
				{
					write(1, word_beg, 1);
					++word_beg;
				}
				write(1, "\n", 1);
				return (0);
			}
			// 현재 단어의 시작을 다음 단어의 시작으로 갱신
			word_beg = next_pos;
		}
	}
	write(1, "\n", 1);
	return (0);
}
