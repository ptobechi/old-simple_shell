#include "main.h"

/**
 * rm_trailing_space - remove extra space
 * @s: string on null term
 *
 * Return: void
 */
void rm_trailing_space(char *s)
{
	int i, tr_sp_start_pos = -1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ' && s[i + 1] == ' ')
			tr_sp_start_pos = i + 1;
	}
	if (tr_sp_start_pos != -1)
		s[tr_sp_start_pos] = '\0';
}

/**
 * remove_newline_char - remove new line char
 * @s: string of null terminated
 *
 * Return: A pointer
 */
char *remove_newline_char(char *s)
{
	int i = 0;

	while (s[++i] != '\0')
		;

	if (s[i - 1] == '\n')
		s[i - 1] = '\0';

	return (s);
}

/**
 * _trim -  cleanup string leading whitespaces
 * @str: string
 */
void _trim(char **str)
{
	char *start = *str;
	char *end = *str + _strlen(*str) - 1;

	/*Find the index of the first non-whitespace character*/
	while (*start && (*start == ' ' || *start == '\t'))
	{
		start++;
	}

	/*Find the index of the last non-whitespace character*/
	while (end > start && (*end == ' ' || *end == '\t'))
	{
		end--;
	}

	/*Null-terminate the trimmed string*/
	end[1] = '\0';

	/*Update the pointer to the trimmed string*/
	*str = start;
}
