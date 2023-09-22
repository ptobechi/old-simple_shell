#include "main.h"

/**
 * get_token_len - count length of token
 * @str: string
 * @delim: delimiter
 *
 * Return: Always 0 (Success)
 */
int get_token_len(char *str, char *delim)
{
	int count = 1;

	if (str == NULL)
		return (-1);

	while (*str != '\0')
	{
		if (*str == *delim)
			count++;
		str++;
	}
	return (count);
}
