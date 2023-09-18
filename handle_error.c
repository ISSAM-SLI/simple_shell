#include "main.h"

/**
 * output_error - Outputting an error..
 * @prog_name: The program name.
 * @cmd: Command inupt
 * @num: The index error.
 *
 * Function displays a "command not found" error message standard error
 * .
 */
void output_error(char *prog_name, char *cmd, int num)
{
	char *converted_num;

	converted_num = my_itoa(num);

	write(STDERR_FILENO, prog_name, my_strlen(prog_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, converted_num, my_strlen(converted_num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, my_strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);

	free(converted_num);
}
