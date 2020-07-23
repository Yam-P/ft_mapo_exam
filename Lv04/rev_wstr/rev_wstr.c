#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		is_space(char c)
{
	if (c == '\n' || c == '\t')
		return (1);
	return (0);
}

void	recursive(char *str)
{
	int		idx;

	if (*str)
		return ;

	idx = 0;
	printf("str: %s", str);	
	while (str[idx] && !is_space(str[idx]))
		++idx;
	recursive(&str[idx]);
	while (str[idx] && !is_space(str[idx]))
	{
		write(1, &str[idx], 1);
		++idx;
	}

}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		recursive(argv[1]);
	}	
	write(1, "\n", 1);
	return (0);
}
