#include "main.h"

int main(void)
{
	char *PATH_val, *cmd_path;
	ssize_t vread;
	size_t n = 0;
	char **_argv = NULL, delim = ' ';

	(void)PATH_val;

/*	lineptr = NULL; */

	signal(SIGINT, handle_signal);

	while (1) {
		printf("ghst$ ");

		vread = _getline(&lineptr, &n, stdin);
		if (vread == -1)
			perror("getline failed:");
		else
		{
			if (vread == EOF)
				return (-1);

			_argv =	_strtok(lineptr, delim);

			cmd_path = get_cmd_path(_argv[0]);
			if (cmd_path == NULL)
				printf("Command '%s' not found!\n", _argv[0]);
			else
				run_cmd(cmd_path, _argv);
		}
	}
	return (0);
}
