#include <stdio.h>
#include <stdlib.h>

int	oper_res(char *oper, int num1, int num2)
{
	if (oper[0] == '+' && oper[1] == '\0')
		return (num1 + num2);
	else if (oper[0] == '-' && oper[1] == '\0')
		return (num1 - num2);
	else if (oper[0] == '*' && oper[1] == '\0')
		return (num1 * num2);
	else if (oper[0] == '/' && oper[1] == '\0')
		return (num1 / num2);
	return (0);
}

int main(int argc, char **argv)
{
	int ret;

	// 1. atoi는 string을 integer로 바꾸는 함수이므로,
	//	  문자열로 만들어진 수를 숫자로 바꾸어서 함수에 대입
	if (argc == 4)
	{
		ret = oper_res(argv[2], atoi(argv[1]), atoi(argv[3]));
		printf("%d", ret);
	}
	printf("\n");
	return (0);
}
