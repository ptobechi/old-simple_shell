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
	char *lineptr = NULL, *lineptr_cpy = NULL;
	ssize_t vread;
	size_t n = 0;
	char **_argv = NULL;
	char *token, *delim = " |";
	int i, token_len;
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
			/** duplicate and count tokens*/
			lineptr_cpy = _strdup(lineptr);
			token_len = get_token_len(lineptr_cpy, delim);

			/*mem alloc for cmd table */
			_argv = malloc(token_len * sizeof(char *));

			/*parsing and creating a cmd table*/
			i = 0;
			do {
				token = strtok(lineptr, delim);
				lineptr = NULL;

				/*remove newlines from token*/
				if (token != NULL)
				{
					token = remove_newline_char(token);
					_argv[i] = token;
					i++;
				}
			} while (token != NULL);

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
