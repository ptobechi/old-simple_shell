#include "main.h"

/**
 * get_token_len count token
 * @lineptr: string
 * @delim: delimeter
 *
 * Return: Always 0 (Success)
*/
int get_token_len(char *lineptr, char *delim)
{
	char *token;
	int count = 0;

	do {
		token = strtok(lineptr, delim);
		lineptr = NULL;
		count++;
	} while (token != NULL);

	return (count);
}
