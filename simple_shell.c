#include "main.h"

/**
 * main - A simple shell program
 * @argc: argument count
 *
 * @argv:
 * Return: Always 0 (sucess)
 *
 */
int main(int argc, char **argv, char **envp)
{
	char *cmd_path;
	ssize_t vread;
	size_t n = 0;
	char **_argv = NULL, delim = ' ';

	lineptr = NULL;
	(void)envp;
	(void)argv;
	(void)argc;

	signal(SIGINT, handle_signal);


	printf("ghst$ ");
	while ((vread = getline(&lineptr, &n, stdin)) != -1)
	{
		printf("ghst$ ");

		if (vread == -1)
			perror("getline failed:");
		else
		{
			_argv =	_strtok(lineptr, delim);

			cmd_path = get_cmd_path(_argv[0]);
			if (cmd_path == NULL)
				perror("No such file or directory");
			else
			{
				run_cmd(cmd_path, _argv);
			/*	free_2d_array(_argv);*/
			}
		}
	}

	free(cmd_path);
	free(lineptr);

	return (0);
}
