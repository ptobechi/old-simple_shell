#include "main.h"

/**
 * err_msg - custom error messages
 * @a: shell (hsh)
 * @b: custom msg
 * @c: command
 *
 * Return: void
 */
void err_msg(char *a, char *b, char *c)
{
	char error_message[256];
	int len = 0;

	/* Create the custom error message*/
	while (a[len] != '\0')
	{
		error_message[len] = a[len];
		len++;
	}
	error_message[len++] = ':';
	error_message[len++] = ' ';
	error_message[len++] = '0';
	error_message[len++] = ':';
	while (*b != '\0')
	{
		error_message[len++] = *b;
		b++;
	}
	error_message[len++] = ' ';
	while (*c != '\0')
	{
		error_message[len++] = *c;
		c++;
	}
	error_message[len++] = '\n';

	/* Write the error message to stderr*/
	write(STDERR_FILENO, error_message, len);
}

