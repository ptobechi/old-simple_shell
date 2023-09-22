#include "main.h"

/**
 * _strlen  - calculate length of a string
 * @str: string
 *
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

