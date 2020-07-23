/*======================================================
idea!: 조건을 만족하는 값과 만족하지 않는 값에 대해
	   출력 방식이 다른 경우를 처리 
======================================================*/
#include <unistd.h>

int		ch_alphabet(char c)
{
	char tmp;
	
	// 3. 아래 조건을 만족해서 값을 13간격으로 바꾼다면
	//    tmp를 출력 후 1을 반환 -> 들어왔던 조건문 밑의 write 실행 안함
	if ((c >= 'a' && c <= 'm')
		|| (c >= 'A' && c <= 'M'))
	{
		tmp = c + 13;
		write(1, &tmp, 1);
		return (1);
	}
	else if ((c >= 'n' && c <= 'z')
			 || (c >= 'N' && c <= 'Z'))
	{
		tmp = c - 13;
		write(1, &tmp, 1);
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int	idx;

	idx = 0;
	// 1. 매개변수를 하나만 받기
	while (argc == 2 && argv[1][idx] != '\0')
	{
		// 2. 알파벳을 변화시키는 조건에 부합하지 않으면
		// 	  그냥 진행되던 값 출력
		if (!ch_alphabet(argv[1][idx]))
			write(1, &argv[1][idx], 1);
		++idx;
	}
	write(1, "\n", 1);
	return (0);
}
