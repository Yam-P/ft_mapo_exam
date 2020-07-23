/*===============================================================
idea: 경유하는 인덱스를 지정하고 그 인덱스부터 화이트스페이스까지 
	  인덱스를 빼주고 다시 경유지를 갱신 후, 지금 인덱스부터 
	  아까 출발점까지를 출력. 이를 반복적으로 진행하기
================================================================*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	get_len(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\b' || c == '\t')
		return (1);
	return (0);
}

// 마지막 단어에서 띄어쓰기를 쓰지 않기위해 전체 단어 수 세기
int	word_cnt(char *str)
{
	int	ret;
	int	idx;

	ret = 0;
	idx = 0;
	while (str[idx])
	{
		while (str[idx] && is_space(str[idx]))
			++idx;	
		if (str[idx] && !is_space(str[idx]))
			++ret;
		while (str[idx] && !is_space(str[idx]))
			++idx;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	int	len;
	int	i;
	int	save;
	int	words;
	int	k;

	if (argc == 2)
	{
		len = get_len(argv[1]);		
		// 경유지를 정해두기
		save = len - 1;
		k = 0;
		words = word_cnt(argv[1]);
		while (i >= 0)
		{
			// 경유지 갱신
			i = save;
			while (!is_space(argv[1][i]) && i >= 0)
				--i;
			save = i - 1;
			// 경유지 다음 인덱스부터 출력하면 단어 하나가 통으로 나옴
			i += 1;
			while (!is_space(argv[1][i]) && argv[1][i])
			{
				write(1, &argv[1][i], 1);
				++i;
			}
			if (k < words - 1)
			{
				write(1, " ", 1);
				++k;
			}
		}
	}
	write(1, "\n", 1);

	return (0);
}
