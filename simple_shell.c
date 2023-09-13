#include "main.h"

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
	ssize_t vread;
	size_t n = 0;
	char **_argv = NULL;
	char *token, *delim = " |";
	int i;
	int status;
	pid_t child_p;

	(void)argc;
	(void)argv;

	printf("ghst$ ");
	while (1 && (vread = getline(&lineptr, &n, stdin)) != EOF)
	{
		printf("ghst$ ");

		/** check value passed from cmd line*/
		if (vread == -1)
			perror("Invalid Argument passed");
		else
		{
			_argv =	create_cmd_table(lineptr);

			/* create a child process for execve call */
			child_p = fork();
			if (child_p == 0)
			{
				if (execve(_argv[0], _argv, NULL) == -1)
					perror("Failed to run function");
			}
			wait(&status); /* wait for child_p completion */
			free(_argv);
		}
	}
	free(lineptr);
	return (0);
}
