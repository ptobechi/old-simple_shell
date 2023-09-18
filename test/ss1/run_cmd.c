#include "main.h"

void run_cmd(char *path, char **_argv)
{
	int status;
	pid_t child_p;

	child_p = fork();

	if (child_p == 0)
	{
		if (execve(path, _argv, NULL) == -1)
			perror("execve error:");
	}

	wait(&status); /* wait for child_p completion */
}
