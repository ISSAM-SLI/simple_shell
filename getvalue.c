#include "main.h"

/**
 * my_getenv - Get the value of an environment variable.
 * @glbl_var: The name of the environment variable to retrieve.
 *
 * This function searches the environment
 * for the specified environment.
 *
 * Return: The value of the environment
 * variable, or NULL.
 */
char *my_getenv(char *glbl_var)
{
	char *reserve, *key, *value, *copy_value;
	int m = 0;

	while (environ[m])
	{
		reserve = my_strdup(environ[m]);
		key = strtok(reserve, "=");

		if (my_strcmp(glbl_var, key) == 0)
		{
			value = (strtok(NULL, "\n"));
			copy_value = my_strdup(value);
			free(reserve);
			return (copy_value);
		}
		free(reserve);
		m++;
	}
	return (NULL);
}
