/*=====================================================================
idea!: 첫 단어가 끝났을 때, flag를 켜고 인덱스 저장을 해둔다
	   그 외의 단어들은 white space는 지나가고 white space가 아니면 출력
	   출력 후에는 한칸씩 띄운다. 마지막 글자는 그 다음에 붙여서 쓴다.
======================================================================*/
#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\b')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	save;
	int	idx;
	int	first_word;

	if (argc == 2)
	{
		first_word = 0;
		idx = 0;
		while (argv[1][idx])
		{
			// space는 일단 무조건 넘기기
			while (is_space(argv[1][idx]) && argv[1][idx])
				++idx;
			// NULL이 아니고 space가 아닐 때까지 write하기
			while (!is_space(argv[1][idx]) && argv[1][idx])
			{
				if (first_word)
					write(1, &argv[1][idx], 1);
				else
				{
					// 첫 단어는 write하지 않돼, flag는 켜고 
					// 시작 idx 저장, 첫단어는 인덱스만 진행해서 건너뛰기
					save = idx;
					first_word = 1;
					while (!is_space(argv[1][idx]) && argv[1][idx])
						++idx;
				}
				++idx;
			}
			write(1, " ", 1);
		}
		// 첫 단어는 그대로 써주기
		while (argv[1][save] && !is_space(argv[1][save]))
		{
			write(1, &argv[1][save], 1);
			++save;
		}
	}
	write(1, "\n", 1);	

	return (0);
}
