#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 *
 * Return :
 */

static char *strtok_custom(char *str, const char *delim) 
{
	static char *next_token = NULL;
	if (str != NULL) 
	{
		next_token = str;
	} 
	else if (next_token == NULL) 
	{
		return (NULL);
	}

	char *token_start = next_token;
	char *token_end = strpbrk(next_token, delim);

	if (token_end != NULL) 
	{
		*token_end = '\0';
		next_token = token_end + 1;
	} else 
	{
		next_token = (NULL);
	}

	return token_start;
}
