#include "main.h"

/**
 * split_token - Splitting a string into tokens.
 * @line_str: A line of string
 *
 *  function splits an input string into tokens
 *
 * Return: An array of tokens, or NULL.
 */
char **split_token(char *line_str)
{
	char *token = NULL;
	char **elements = NULL;
	char *delm = " \t\n";
	int i = 0;

	if (!line_str)
		return (NULL);

	elements = malloc(sizeof(char *) * 1024);
	if (!elements)
	{
		free(line_str);
		return (NULL);
	}

	token = strtok(line_str, delm);
	if (token == NULL)
	{
		free(line_str);
		free(elements);
		return (NULL);
	}

	while (token)
	{
		elements[i] = my_strdup(token);
		token = strtok(NULL, delm);
		i++;
	}

	free(line_str);
	elements[i] = NULL;
	return (elements);
}
