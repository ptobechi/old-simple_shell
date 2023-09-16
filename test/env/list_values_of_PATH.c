#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * main - list the directories from the PATH env var value
 *
 * Return: Alawys (0);
*/
int main(void)
{
	char *name = "PATH", *val, *token, *delim = ":";

	val = _getenv(name);

	do {
		token = strtok(val, delim);
		if (token != NULL)
			printf("%s\n", token);

		if (val != NULL)
			free(val);

		val = NULL;
	} while (token != NULL);

	return (0);
}
