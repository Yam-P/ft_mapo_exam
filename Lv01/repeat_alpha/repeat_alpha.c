/*=====================================================
idea!: 대문자, 소문자 인 경우를 나누어 반복횟수 정하기! 
=====================================================*/
#include <unistd.h>

void	repeat_alpha(char c)
{
	int	i;
	int	cnt;
	
	// 4. 대문자이면 'A'를, 소문자이면 'a'를 뺀다.
	// 	  ex) C는 A보다 2 더 크므로 세번 출력해야됨.
	if (c >= 'A' && c <= 'Z')
		cnt = c - 'A';
	else if (c >= 'a' && c <= 'z')
		cnt = c - 'a';
	i = 0;
	// 5. 함수에 들어오기 전에 일단 한 글자가 출력 되있으므로,
	//	  감안하여서 추가적으로 출력한다.
	//	  ex) 'C'면 cnt가 2이므로 두번 출력하되, 밖에서 출력하고
	//		  들어오므로 총 세번이 나온다.
	while (i < cnt)
	{
		write(1, &c, 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	int	idx;

	idx = 0;
	// 1. 매개변수가 하나인 경우에만 수행한다.
	while (argv[1][idx] != '\0' && argc == 2)
	{
		// 2. 일단 iteration을 돌며 한 글자씩 출력한다.
		write(1, &argv[1][idx], 1);
		// 3. 알파벳이 맞는 경우 내부 함수에 들어간다.
		if((argv[1][idx] >= 'a' && argv[1][idx] <= 'z')
			|| (argv[1][idx] >= 'A' && argv[1][idx] <= 'Z'))
			repeat_alpha(argv[1][idx]);
		++idx;
	}
	write(1, "\n", 1);

	return (0);
}
