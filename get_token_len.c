#include "main.h"

/**
 * get_token_len - count length of token
 * @str: string
 * @delim: delimiter
 *
 * Return: Always 0 (Success)
 */
int get_token_len(char *str, char delim)
{
	int i, j, count = 1;

	if (str == NULL)
		return (-1);

	if (str[0] == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == delim)
		{
			for (j = i + 1; str[j] != '\0'; j++)
				if (str[j] != delim)
				{
					count++;
					i = j;
					break;
				}
		}
	}
	return (count);
}
