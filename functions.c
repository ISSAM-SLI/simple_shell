#include "main.h"

/**
 * my_strdup - Replicate a string.
 * @input: string to Replicate.
 *
 * Return: A pointer to the Replicated string.
 */
char *my_strdup(const char *input)
{
	char *copy;
	int i, count = 0;

	if (input == NULL)
		return (NULL);
	while (input[count] != '\0')
		count++;
	copy = malloc(sizeof(char) * (count + 1));
	if (copy == NULL)
		return (NULL);
	for (i = 0; i <= count; i++)
		copy[i] = input[i];
	return (copy);
}

/**
 * my_strcmp - Comparing two strings.
 * @string1: fst string.
 * @string2: scnd string.
 *
 * Return: An integer < 0, equal to 0, or > 0 .
 */
int my_strcmp(char *string1, char *string2)
{
	int compare;

	compare = (int)*string1 - (int)*string2;
	while (*string1 != '\0')
	{
		if (*string1 != *string2)
			break;
		string1++;
		string2++;
		compare = (int)*string1 - (int)*string2;
	}
	return (compare);
}

/**
 * my_strlen - find length of a string.
 * @string: The input string.
 *
 * Return: The length of the string.
 */
int my_strlen(char *string)
{
	int length = 0;

	while (string[length])
		length++;
	return (length);
}

/**
 * my_strcat - Concatenating two strings.
 * @Target: Target string.
 * @Original: Original string.
 *
 * Return: A pointer to the concatenated string.
 */
char *my_strcat(char *Target, char *Original)
{
	char *full_destin = Target;

	while (*Target)
		Target++;
	while (*Original)
	{
		*Target = *Original;
		Target++;
		Original++;
	}
	*Target = '\0';
	return (full_destin);
}

/**
 * my_strcpy - Copy one string to another.
 * @copied: Target string.
 * @source: Original string.
 *
 * Return: A pointer to the copied string.
 */
char *my_strcpy(char *copied, char *source)
{
	int i = 0;

	while (source[i])
	{
		copied[i] = source[i];
		i++;
	}
	copied[i] = '\0';
	return (copied);
}
