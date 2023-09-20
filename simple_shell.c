#include "main.h"

/**
 * main - A simple shell program
 * @argc: argument count
 * @argv: argument variable
 * @envp: environment pointer
 *
 * Return: Always 0 (sucess)
 */
int main(int argc, char **argv, char **envp)
{
	ssize_t vread;
	size_t n = 0;
	char **_argv = NULL, *delim = " ";
	char *lineptr = NULL;

	(void)argc;
	(void)argv;

	signal(SIGINT, handle_signal);

	while (1)
	{
		write(STDOUT_FILENO, "$", 1);

		/** handle EOF and ctrl D */
		vread = getline(&lineptr, &n, stdin);
		if (vread == -1)
		{
			printf("\n");
			break;
		}

		/** handle tokenization and cmd table */
		_argv =	_create_cmd_table(lineptr, delim);

		/** handle exit*/
		if (_strccmp(_argv[0], "exit", '\0') == 0)
		{
			free_2d_array(_argv);
			exit(900);
		}
		else if (_strccmp(_argv[0], "env", '\0') == 0)
			/** prints environment variable */
			_printenv(envp);
		else
			/** execute command */
			run_cmd(_argv);

		free_2d_array(_argv);
	}

	free(lineptr);

	return (0);
}
