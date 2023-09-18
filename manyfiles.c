#include "main.h"

/**
 * freememory - Freeing memory allocated
 * @string: Array of strings to free.
 *
 * function deallocates memory for strings.
 */
void freememory(char **string)
{
	int k;

	if (!string)
		return;

	for (k = 0; string[k]; k++)
	{
		free(string[k]);
	}

	free(string);
}
/**
 * my_itoa - Converting an integer to a string.
 * @num: The integer to convert.
 *
 * Return: A pointer to the resulting string.
 */
char *my_itoa(int num)
{
	char buffer_num[15];
	int j = 0;

	if (num == 0)
	{
		buffer_num[j++] = '0';
	}
	else
	{
		while (num > 0)
		{
			buffer_num[j++] = (num % 10) + '0';
			num /= 10;
		}
	}
	buffer_num[j] = '\0';
	my_reverse(buffer_num, j);

	return (my_strdup(buffer_num));
}

/**
 * my_reverse - Reversing a string.
 * @string: The string to reverse.
 * @Extent: The Extent of the string.
 */
void my_reverse(char *string, int Extent)
{
	char var;
	int begin = 0;
	int finish = Extent - 1;

	while (begin < finish)
	{
		var = string[begin];
		string[begin] = string[finish];
		string[finish] = var;
		begin++;
		finish--;
	}
}
