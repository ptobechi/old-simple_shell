#include "main.h"

/**
 * remove_newline_char - remove new line char
 * @s: string of null terminated
 *
 * Return: A pointer
 */
char *remove_newline_char(char *s)
{
	int i = 0;

	while (s[++i] != '\0');

	if (s[i - 1] == '\n')
		s[i - 1] = '\0';

	return (s);
}
