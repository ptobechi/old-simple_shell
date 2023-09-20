#include "main.h"

/**
 * main - A simple shell program
 *
 * Return: Always 0 (sucess)
 */
int main(void)
{
	/*char *cmd_path;*/
	ssize_t vread;
	size_t n = 0;
	char **_argv = NULL, *delim = " ";
	char *lineptr = NULL;

	signal(SIGINT, handle_signal);

	while (1)
	{
		printf("$ ");

		/** handle EOF and ctrl D */
		vread = getline(&lineptr, &n, stdin);
		if (vread == -1)
		{
			printf("\n");
			break;
		}

		/** handle tokenization and cmd table */
		_argv =	_create_cmd_table(lineptr, delim);
		/**	if (_strccmp(_argv[0], "exit", '\0') == 0)
		  {
		  exit(900);
		  }
		  else if (_strccmp(_argv[0], "env", '\0') == 0)
		  _printenv();
		  else
		  {
		  cmd_path = get_cmd_path(_argv[0]);
		  if (cmd_path == NULL)
		  perror("No such file or directory");
		  else*/
		run_cmd(_argv[0], _argv);
		/*}*/

		free_2d_array(_argv);
	}
	/*	free(cmd_path);*/

		free(lineptr);

	return (0);
}
