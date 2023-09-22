#include "main.h"

/**
 * _create_cmd_table - create a command table
 * @tokens: string of null terminated char
 * @delim: delimeter
 *
 * Return: Always 0 (Success)
 */
char **_create_cmd_table(char *tokens, char *delim)
{
	char **_arr = NULL, *tokens_cpy, *token;
	int token_len, i;

	token_len = get_token_len(tokens, delim);

	/** mem allocation for cmd table */
	_arr = (char **)malloc(sizeof(char *) * (token_len + 1));
	if (_arr == NULL)
	{
		perror("Memomry allocation failed");
		return (NULL);
	}

	/** tokenize token_cpy and store tokens to _arr */
	memset(_arr, 0, (token_len + 1));
	i = 0;
	tokens_cpy = _strdup(tokens);
	token = strtok(tokens_cpy, delim);
	while (token != NULL)
	{
		/*_arr[i] = _strdup(remove_newline_char(token));*/
		_arr[i] = _strdup(token);
		if (_arr[i] == NULL)
		{
			perror("Memory allocation failed");
			free(tokens_cpy);
			free_2d_array(_arr);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	_arr[i] = NULL;

	free(tokens_cpy);
	return (_arr);
}
