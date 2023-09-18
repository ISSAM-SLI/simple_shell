#include "main.h"

/**
 * getEnvCmd - Execute the 'env' command.
 */
void getEnvCmd(void)
{
	int z = 0;

	while (environ[z])
	{
		write(STDOUT_FILENO, environ[z], my_strlen(environ[z]));
		write(STDOUT_FILENO, "\n", 1);
		z++;
	}
}
/**
 * custom_exec - Executing a command with arguments
 * @cmd: command line
 * @argv: argument parameter
 * @num: parameter number
 *
 * Return: The exit status.
 */
int custom_exec(char **cmd, char **argv, int num)
{
	pid_t New_child;
	int status;
	char *valid_cmd;

	if (my_strcmp(cmd[0], "env") == 0)
	{
		getEnvCmd();
		freememory(cmd);
		return (0);
	}
	valid_cmd = find_cmd(cmd[0]);
	if (valid_cmd == NULL)
	{
		output_error(argv[0], cmd[0], num);
		freememory(cmd);
		return (127);
	}
	New_child = fork();
	if (New_child == 0)
	{
		if (execve(valid_cmd, cmd, environ) == -1)
		{
			free(valid_cmd);
			freememory(cmd);
		}
	}
	else
	{
		wait(&status);
		freememory(cmd);
		free(valid_cmd);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
			exit(2);
	}

	return (WEXITSTATUS(status));
}
