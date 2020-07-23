/*=====================================================
idea!: 첫 번째 space 때는 탈출하지 않고 진행해야 하지만
	   두 번째 space 떄는 탈출해야한다!
=====================================================*/
#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\t' || c == '\f')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int		idx;
	int		flag;

	idx = 0;
	flag = 0;
	// 1. 매개변수가 한개인 경우에만 while문을 실행하고,
	while (argv[1][idx] != '\0' && argc > 1)
	{
		// 2. 첫 번째 매개변수를 하나씩 봐가며
		//	  공백이 끝나면 시작점으로 간주한다.
		if (!is_space(argv[1][idx]))
		{
			// 3. space가 아니면 플래그를 열어주며 문자가 시작됨을 나타내고
			// 	  idx를 증가시키며 한글자씩 출력한다.
			flag = 1;
			write(1, &argv[1][idx], 1);
		}
		// 4. 다음 space가 나오면 첫 번째 단어가 아니므로 탈출한다.
		// 핵심: 첫 번째 space는 flag가 0이여서 탈출할 수 없다!
		if (flag && is_space(argv[1][idx]))
			break ;
		++idx;
	}
	// 1. 그 외에는 줄 바꿈을 한다.
	write(1, "\n", 1);
	return (0);
}
