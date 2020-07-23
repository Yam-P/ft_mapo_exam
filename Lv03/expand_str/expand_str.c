#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\t' || c == '\f' || c == '\b')
		return (1);
	return (0);
}

char	*find_next_word(char *str)
{
	while (is_space(*str) && *str != '\0')
		++str;
	return (str);
}

int	main(int argc, char **argv)
{
	// 현재 가리키고 있는 단어와 다음 가리킬 단어를 설정하기.
	char	*beg_word;
	char	*next_word;

	beg_word = argv[1];
	next_word = argv[1];
	if (argc == 2)
	{
		// 현재 가리키고 있는 단어가 끝이 될 때까지 나오지 않기
		while (*beg_word != '\0')
		{
			// 만약 white space를 만난다면, 얘가 끝날 때까지 가두기
			if (is_space(*beg_word))
			{
				// white space가 끝나고 새로운 word가 시작되는 시점을 반환
				next_word = find_next_word(beg_word);
				// white space가 끝나는 시점이 null 이라면 바로 나오기
				if (*next_word == '\0')
					break ;
				write(1, "   ", 3);
				// white space가 끝나는 시점을 새로운 beg_word로 갱신하기
				beg_word = next_word;
			}
			write(1, beg_word, 1);
			++beg_word;
		}
	}
	write(1, "\n", 1);
	return (0);
}
