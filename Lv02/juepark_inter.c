#include <stdio.h>
#include <unistd.h>
int	check_inter(char c, char* str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;	
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int i;
	int c;
	unsigned int check[256] = {0, };

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if (check[c] == 0 && check_inter(c, &argv[2][0]))
			{
				check[c] = 1;
				write(1, &(argv[1][i]), 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
