#include <stdio.h>

extern char **environ;

/**
 * _env - prints environment variables
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}
