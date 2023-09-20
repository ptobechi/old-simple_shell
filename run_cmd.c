#include "main.h"

/**
 * run_cmd - execute cmd
 * @_argv: array of null terminated strings
 *
 * Return: void
 */
void run_cmd(char **_argv)
{
	int status;
	pid_t child_p;
	char *cmd_path;

	cmd_path = get_cmd_path(_argv[0]);
	if (cmd_path == NULL)
		perror("$");
	else
	{
		child_p = fork();

		if (child_p == 0)
		{
			if (execve(cmd_path, _argv, NULL) == -1)
				perror("$");
		}
	}

	wait(&status); /* wait for child_p completion */
}
