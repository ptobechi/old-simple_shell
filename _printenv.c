#include "main.h"

/**
 * _printenv - print environmental variables
 *
 * Return: void
 */
void _printenv(void)
{
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
}
