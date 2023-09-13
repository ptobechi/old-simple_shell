#include "main.h"

char **create_cmd_table(char *lineptr)
{
	char *lineptr_cpy, *token, *delim = " ";
	int i, token_len;
	char **_argv;
	/** duplicate and count tokens*/
	lineptr_cpy = _strdup(lineptr);
	token_len = get_token_len(lineptr_cpy, delim);

	/*mem alloc for cmd table */
	_argv = malloc(token_len * sizeof(char *));

	/*parsing and creating a cmd table*/
	i = 0;
	do {
		token = strtok(lineptr, delim);
		lineptr = NULL;

		/*remove newlines from token*/
		if (token != NULL)
		{
			token = remove_newline_char(token);
			_argv[i] = token;
			i++;
		}
	} while (token != NULL);

	free(lineptr_cpy);

	return (_argv);
}
