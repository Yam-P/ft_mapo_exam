#include <stdio.h>
#include <unistd.h>

int	char_num[128];
int	visited[128];

char *strcat(char *str1, char *str2)
{
	int 	i;
	int		j;
	char	*ret;

	i = 0;
	ret = str1;
	printf("idx: %d\n", i);
	while (str1[i] != '\0')
	{
		++i;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		str1[i] = str2[j];
		++i;
		++j;
	}
	str1[i] = '\0';
	return (ret);
}

void	cnt_freq(char *str1, char *str2)
{
	int		i;
	int		j;
	int		print;
	char	*str;

	str = strcat(str1, str2);
	printf("strcat: %s\n", str);
	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				++char_num[(int)str[i]];
			if (char_num[(int)str[i]] > 1 && !visited[(int)str[i]])
			{
				visited[(int)str[i]] = 1;
				print = str[i];
				write(1, &print, 1);
			}
			++j;
		}	
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		cnt_freq(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
