#include "main.h"

/**
 * getEnv - get environment variable
 *
 * Return: Null
*/
void getEnv(char **envp)
{
	while (*envp != NULL)
	{
		printf("%s\n", *envp);
		envp++;
	}
}
