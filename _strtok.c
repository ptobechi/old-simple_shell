#include "main.h"

/**
 * _str_chr - To find a character in a string
 * @str: The string
 * @_char: The character to locate
 * Return: A pointer to the character in the string
 */
const char *_str_chr(const char *str, char _char)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == _char)
			return (&str[i]);
		i++;
	}

	return (NULL);
}

/**
 * _strtok - returns token from a string
 * @str: string
 * @delim: delimeter
 *
 * Return: tokens string of null char
 */
char *_strtok(char *str, char *delim)
{
	static char *store_ptr;
	char *token_start;

	if (str != NULL)
		store_ptr = str;
	if (store_ptr == NULL || *store_ptr == '\0')
		return (NULL);

	while (*store_ptr && _str_chr(delim, *store_ptr))
		store_ptr++;

	token_start = store_ptr;

	while (*store_ptr && !_str_chr(delim, *store_ptr))
		store_ptr++;

	if (*store_ptr)
		*store_ptr++ = '\0';

	return (token_start);
}
