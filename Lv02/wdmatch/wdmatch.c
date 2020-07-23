#include <unistd.h>

int	g_str1_len;

int	wdmatch(char *str1, char *str2)
{
	int	cnt;
	
	// str1의 길이를 세기 위해 변수를 두기
	// str1의 길이를 알아야 str2에서 모두 찾았는가 확인 가능
	g_str1_len = 0;
	while (str1[g_str1_len] != '\0')
		++g_str1_len;
	cnt = 0;
	// str2가 끝이 될 때까지 순환
	while (*str2 != '\0')
	{
		// str2에서 str1의 글자를 찾으면 str1도 증가
		if (*str1 == *str2)
		{
			++cnt;
			++str1;
		}
		++str2;
	}
	if (cnt == g_str1_len)
		return (1);
	return (0); 
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		// wdmatch가 만족할 때, str1의 길이를 사용하여 출력
		if (wdmatch(argv[1], argv[2]))
			write(1, argv[1], g_str1_len);
	}
	write(1, "\n", 1);
	return (0);
}
