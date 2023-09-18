#include "main.h"

/**
 * main - Entry point of the program.
 * @ac: Counting arguments.
 * @argv: Argument Vector.
 *
 * Return: exit status.
 */
int main(int ac, char **argv)
{
	char *var = NULL;
	char **string = NULL;
	int status = 0, num = 0;
	(void)ac;

	while (1)
	{
		var = get_ln();
		if (var == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		num++;

		string = split_token(var);
		if (string == NULL)
			continue;
		if (my_strcmp(string[0], "exit") == 0)
		{
			freememory(string);
			break;
		}
		status = custom_exec(string, argv, num);
	}
	return (0);
}
