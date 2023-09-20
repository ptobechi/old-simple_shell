#include "main.h"

/**
 * create_cmd_table - create a command table
 * @tokens: string of null terminated char
 *
 * Return: Always 0 (Success)
 */
char *_create_cmd_table(char *tokens, char *delim)
{
	char **_arr = NULL, char *tokens_cpy, char *token, *token_count;
	int count = 0;

	/** duplicate tokens */
	tokens_cpy = strdup(tokens);

	if (tokens_cpy == NULL)
	{
		perror("token duplicate failed");
		return (NULL);
	}

	/**count tokens and allocate memory for _arr **/
	token_count = strdup(tokens);
	token = sttrok(token_count, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(token_count);

	_arr = (char **)malloc((count + 1) * sizeof(char *));
	if (_arr == NULL)
	{
		perror("Memomry allocation failed");
		return (NULL);
	}

	/** tokenize token_cpy and store tokens to _arr */
	count = 0;
	token = strtok(tokens_cpy, delim);
	while (token != NULL)
	{
		_arr[count] = strdup(token);
		if (_arr[count] == NULL)
		{
			free_2d_array(_arr);
			free(tokens_cpy);
			return (NULL);
		}
		count++;
		token = strtok(NULL, delim);
	}
	_arr[i] = NULL;

	free(tokens_cpy);
	return (_arr);
}
