#include <unistd.h>

void	char_low2up(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 'a' + 'A';
}

void	char_up2low(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c = *c - 'A' + 'a';
}

int		is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\b')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 || is_space(argv[i][j - 1]))
			{
				if(argv[i][j] >= 'a' && argv[i][j] <= 'z')
					char_low2up(&argv[i][j]);
			}
			else if (j != 0 && is_alpha(argv[i][j]))
				char_up2low(&argv[i][j]);
			write(1, &argv[i][j], 1);
			++j;
		}
		write(1, "\n", 1);
	}
	return (0);
}
