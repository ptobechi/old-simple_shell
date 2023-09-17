#include "main.h"

int main(void)
{
	char *lineptr = NULL, *PATH_val, *cmd_path;
	ssize_t vread;
	size_t n = 0;
	char **_argv = NULL;

	while (1) {
		printf("ghst$ ");

		vread = getline(&lineptr, &n, stdin);
		if (vread == -1)
			perror("getline failed:");
		else
		{
			if (vread == EOF)
				return (0);

			_argv =	create_cmd_table(lineptr);

			cmd_path = get_cmd_path(_argv[0]);
			if (cmd_path == NULL)
				printf("Command '%s' not found!\n", _argv[0]);
			else
				run_cmd(cmd_path, _argv);
		}
		free(lineptr);
		lineptr = NULL;
	}
	return (0);
}
