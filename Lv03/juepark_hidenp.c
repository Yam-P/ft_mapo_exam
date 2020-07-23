#include <unistd.h>
#include <stdio.h>

int		get_strlen(char *str)
{
	int len = 0;
	while(*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	hidenp(int part_size, char **str, int len_1, int len_2)
{
	int k = 0;
	int i = 0;
	while(k < len_2)
	{
		if (str[0][i] == str[1][k])
		{
			i++;
		}
		k++;
	}
	if (i == len_1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
int 	main(int argc, char **argv)
{
	int len_1 = 0;
	int len_2 = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	len_1 = get_strlen(argv[1]);
	len_2 = get_strlen(argv[2]);
	if (len_1 == 0 || len_2 == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	hidenp(argc - 1, &argv[1], len_1, len_2);
}
