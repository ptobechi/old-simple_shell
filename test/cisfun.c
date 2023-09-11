#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry Point
 * @argc: argument count
 * @argv: argument variable
 *
 * Return: Always 0 (Suceess)
*/
int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t vread;
	size_t n = 0;
	char *_argv[] = NULL; /** doubt it will work */
	char *token, *delim = " ";
	int i;

	while (1)
	{
		printf("ghst$ ");

		vread = getline(&lineptr, &n, stdin);

		/** check value passed from cmd line*/
		if (vread == -1)
			perror("Invalid Argument passed");
		else
		
			/** tokenization using strtok */
			token = strtok(lineptr, delim);

			while (token != NULL)
			{
				/** creating a command table */
				_argv[i] = token;

				strtok(NULL, delim);
				i++;
			}

			for (i = 0; i < sizeof(_argv) / sizeof(_argv[0]); i++)
			{
				printf("%s\n", _argv[i]);
			}

		}
	}
	free(_argv);
	free(lineptr);
	return (0);
}
