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

	while (1)
	{
		printf("ghst$ ");

		vread = getline(&lineptr, &n, stdin);

		/** check value passed from cmd line*/
		if (vread == -1)
			perror("Invalid Argument passed");
		else
		{
			lineptr_cpy = _strdup(lineptr);

			token_len = get_token_len(lineptr_cpy, delim);
			printf("%d\n", token_len);

			_argv = malloc(token_len * sizeof(char *));

			i = 0;
			do {
				token = strtok(lineptr, delim);
				lineptr = NULL;

				_argv[i] = token;
				i++;
			} while (token != NULL);
			//i++;
			//_argv[i] = NULL;

		//	char *_arg[] = {"/bin/ls", "/usr", NULL};

			pid_t child_p = fork();
			int status;
		//	char *fpath = which(_argv[0]);

		//	if (fpath== NULL)
		//		perror("File not Found");

			if (child_p == 0)
			{
				if (execve(_argv[0], _argv, NULL) == -1)
					perror("Failed to run function");
				printf("Child process complete\n");
			}
			wait(&status);
		}
		free(_argv);
	}
	free(_argv);
	free(lineptr);
	return (0);
}
