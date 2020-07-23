#include <stdlib.h>
#include <stdio.h>///////////////////////////////

int		is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

char	cnt_words(char *str)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (str[idx] != '0')
	{
		if (is_space(str[idx]))
			++cnt;
		++idx;
	}	
	return (cnt);
}

char	**ft_split(char *str)
{
	char	**ret;
	char	num_words;
	int		idx;
	int		k;
	int		j;

	num_words = cnt_words(str);
	if (!(ret = (char **)malloc(sizeof(char *) * num_words + 1)))
		return (NULL);

	k = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (!is_space(str[idx]))
		{
			// 원래는 미리 각 단어의 길이를 세놓아야 하지만 매우 큰 수로.. 처리;;
			if (!(ret[k] = (char *)malloc(sizeof(char) * 4095)))
				return (NULL);
			// ret[k]의 인덱스 0부터 str[idx]의 값을 복사해오기
			j = 0;
			while (!is_space(str[idx]) && str[idx] != '\0')
			{
				ret[k][j] = str[idx];
				++idx;
				++j;
			}
			// 다음 white space를 만나면 k가 1 증가한 상태이므로
			++k;
		}
		++idx;
	}
	ret[k] = NULL;
	return (ret);
}
