/*================================================================
idea!: 받은 문자열의 길이를 먼저 구한 후 인덱스를 뒤집어 출력한다.
================================================================*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	idx;
	int	len;

	len = 0;
	// 1. 문자열의 길이를 구하기
	while (argc > 1 && argv[1][len] != '\0')
		len++;
	// 2. 마지막 index는 길이 - 1
	idx = len - 1;
	// 3. 마지막 index부터 출력하여 뒤집어진 문자열 얻기
	while (idx > 0)
	{
		write(1, &argv[1][idx], 1);
		--idx;
	}
	write(1, "\n", 1);
	return (0);
}
