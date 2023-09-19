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
	char *lineptr = NULL;

	/*(void)envp;*/
	(void)argv;
	(void)argc;

	signal(SIGINT, handle_signal);


	printf("$ ");
	while ((vread = getline(&lineptr, &n, stdin)) != -1)
	{
		printf("$ ");

		if (vread == -1)
			perror("getline failed:");
		else
		{
			_argv =	_strtok(lineptr, delim);

			if (_strccmp(_argv[0], "exit", '\0') == 0)
			{
				free_2d_array(_argv);
				exit(900);
			}
			else if (_strccmp(_argv[0], "env", '\0') == 0)
				_getenv(*envp);
			else
			{
				cmd_path = get_cmd_path(_argv[0]);
				if (cmd_path == NULL)
					perror("No such file or directory");
				else
					run_cmd(cmd_path, _argv);
			}
		}

		free_2d_array(_argv);
	}
	free(cmd_path);


	return (0);
}
