#include "main.h"

/**
 * run_cmd - execute cmd
 * @_argv: array of null terminated strings
 *
 * Return: void
 */
void run_cmd(char **_argv)
{
	int status, handle_flag = 0;
	pid_t child_p;
	char *cmd_path;

	/** lookup command*/
	cmd_path = get_cmd_path(_argv[0], &handle_flag);
	if (cmd_path == NULL)
	{
		free(cmd_path);
		perror("$");
	}
	else
	{
		child_p = fork();

		if (child_p == 0)
			if (execve(cmd_path, _argv, NULL) == -1)
				perror("$");

		if (handle_flag)
			free(cmd_path);
	}

	wait(&status); /* wait for child_p completion */
}
