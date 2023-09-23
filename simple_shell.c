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

	if (argc > 1)
		_file_input(argv, envp);

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$", 1);
			fflush(stdout);
		}

		/** handle EOF and ctrl D */
		vread = getline(&lineptr, &n, stdin);
		if (vread == -1)
			break;

		/** handle tokenization and cmd table */
		_argv =	_create_cmd_table(lineptr, delim);

		/** enter shell mode */
		exec_shell(_argv, envp, &lineptr);

	}

	free(lineptr);

	return (0);
}

/**
 * exec_shell - takes cmd from terminal
 * @_argv: command table
 * @envp: environment pointer
 * @lineptr: getline read text refrence
 *
 * Return: void
 */
void exec_shell(char **_argv, char **envp, char **lineptr)
{
	int exit_status = 0;

	/** handle exit*/
	if (_strccmp(_argv[0], "exit", '\0') == 0)
	{
		if (_argv[1] != NULL)
			exit_status = _atoi(_argv[1]);
		free(*lineptr);
		free_2d_array(_argv);
		exit(exit_status);
	}
	else if (_strccmp(_argv[0], "env", '\0') == 0)
		/** prints environment variable */
		_printenv(envp);
	else
		/** execute command */
		run_cmd(_argv, envp);

	free_2d_array(_argv);
}

