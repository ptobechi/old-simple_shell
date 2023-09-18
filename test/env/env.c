#include <stdio.h>

/**
 * main - print environment variable using the third parameter of main
 * @ac: argument count
 * @av: argument vector
 * @env: enviroment variable
 *
 * Return: Always (0);
*/
int main(int ac, char **av, char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
