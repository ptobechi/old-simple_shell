#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * main - print environment variable value
 * @ac: argument count
 * @av: null terminated list of array of arguments
 *
 * Return: Always (0);
*/
int main(int ac, char **av)
{
	char *_env;

	if (ac != 2)
	{
		printf("Usage: %s env_variable_name\n", av[0]);
		return (1);
	}

	_env = _getenv(av[1]);

	if (_env != NULL)
		printf("%s\n", _env);
	else
		printf("Env var not found\n");

	free(_env);
	return (0);
}
