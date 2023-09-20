#include "main.h"

/**
 * _printenv - print environmental variables
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
