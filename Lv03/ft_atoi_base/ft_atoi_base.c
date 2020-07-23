// char를 숫자로 변환
int	cvt_char2int(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int ret;
	int sign;

	sign = 0;
	// 첫 글자가 -라면 sign 플래그를 켜고 str은 첫번째 주소부터 시작하도록
	if (str[0] == '-')
	{
		str = &str[1];
		sign = 1;
	}

	ret = 0;
	while (*str != '\0')
	{
		// 숫자 아닌 값이 있으면 진행을 멈춤
		if (cvt_char2int(*str) == -1)
			break ;
		// atoi 연산
		ret = ret * str_base + cvt_char2int(*str);
		++str;
	}

	ret = sign ? -ret : ret;
	return (ret);
}
