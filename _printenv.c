#include "main.h"

/**
 * _printenv - print environmental variables
 * @env: environment variable
 *
 * Return: void
 */
void _printenv(char **env)
{
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
