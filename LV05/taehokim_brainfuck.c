#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2048

int brainfuck(char *string)
{
	int        i;
	int        loop;
	char    *pointer;

	i = 0;
	if (!(pointer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while (i <= BUFF_SIZE)
		pointer[i++] = '\0';
	i = 0;
	while (string[i])
	{
		string[i] == '<' ? pointer += 1 : pointer;
		string[i] == '>' ? pointer -= 1 : pointer;
		string[i] == '+' ? *pointer += 1 : *pointer;
		string[i] == '-' ? *pointer -= 1 : *pointer;
		if (string[i] == '.')
			write(1, &*pointer, 1);
		if (string[i] == '[' && !*pointer)
		{
			loop = 1;
			while (loop)
			{
				i += 1;
				string[i] == '[' ? loop += 1 : loop;
				string[i] == ']' ? loop -= 1 : loop;
			}
		}
		if (string[i] == ']' && *pointer)
		{
			loop = 1;
			while (loop)
			{
				i -= 1;
				string[i] == '[' ? loop -= 1 : loop;
				string[i] == ']' ? loop += 1 : loop;
			}
		}
		i += 1;
	}
	return (1);
}

int		main(int argc, const char *argv[])
{
	brainfuck("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    // else
    //     write(1, "\n", 1);
    // return (0);
}
