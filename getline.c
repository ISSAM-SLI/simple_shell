#include "main.h"

/**
 * get_ln - Get a line from Stdin.
 *
 * function reads and allocates text from standard input.
 * displaying '$ ' if it's from a terminal.
 * Return: the read line, or NULL if error or EOF.
 */
char *get_ln(void)
{
	char *buffer_sequence = NULL;
	size_t length = 0;
	ssize_t lire;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);

	lire = getline(&buffer_sequence, &length, stdin);

	if (lire == -1)
	{
		free(buffer_sequence);
		return (NULL);
	}

	return (buffer_sequence);
}
