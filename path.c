#include "main.h"

/**
 * find_cmd - Finding the full path of a cmd.
 * @cmd: cmd to find.
 *
 * function looks for a command in the PATH directories
 * and returns its full path
 *
 * Return: the full path of the command, or NULL
 */
char *find_cmd(char *cmd)
{
	char *path_value, *token_value, *full_path;
	struct stat st;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (my_strdup(cmd));
			return (NULL);
		}
	}

	path_value = my_getenv("PATH");
	if (!path_value)
		return (NULL);

	token_value = strtok(path_value, ":");
	while (token_value)
	{
		full_path = malloc(my_strlen(token_value) + 1 + my_strlen(cmd) + 1);
		if (full_path)
		{
			my_strcpy(full_path, token_value);
			my_strcat(full_path, "/");
			my_strcat(full_path, cmd);
			if (stat(full_path, &st) == 0)
			{
				free(path_value);
				return (full_path);
			}
			free(full_path);
			token_value = strtok(NULL, ":");
		}
	}

	free(path_value);
	return (NULL);
}
