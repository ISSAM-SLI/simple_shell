#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 *
 * Return : 0 if it fails
 */

static char *strtok_custom(char *str, const char *delim) 
{
	static char *next_token = NULL;
	char *valeur = malloc(sizeof(char));
	char *token_start = next_token;
	char *token_end = strpbrk(next_token, delim);
		
	if (token_end != NULL) 
	{
		*token_end = '\0';
		next_token = token_end + 1;
	}
        else if (token_end = '\0')
	{
		break;
	}	
	
	else 
	{
		next_token = (NULL);
	}

	return token_start;
}
