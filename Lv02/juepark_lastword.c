#include <stdio.h>
#include <unistd.h>
int	ft_isspace(char c)
{
	if (c == '\v' || c == '\r' || c == ' ' || c == '\t' || c == '\f' || c == '\n')
		return 1;
	else
		return 0;
}

int ft_isword(char *str)
{
	while (*str && !(ft_isspace(*str)))
	{
		str++;
	}
	while (*str && ft_isspace(*str))
	{
		str++;
	}
	if (*str == '\0' )
		return 1;
	else
		return 0;
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			while (argv[1][i] && ft_isspace(argv[1][i]))
				i++;
			if (argv[1][i] && ft_isword(&argv[1][i]))
			{
				while (argv[1][i] != '\0' && !ft_isspace(argv[1][i]))
				{
					write(1, &(argv[1][i]), 1);
					i++;
				}
				if (argv[1][i] == '\0'|| ft_isspace(argv[1][i]))
					break;
			}
			i++;
		}
	}	
	write(1, "\n", 1);
	return 0;
}
