#include "main.h"

/**
 * _strtok - get token from string
 * @str: string of char
 * @delim: delimiter
 *
 * Return: tokens
 */
/*
char **_strtok(char *str, char delim)
{
	int i, j, k;
	char **str_arr = NULL, *token;
	int token_len = get_token_len(str, delim);
	int *tokens_positions = get_tokens_positions(str, delim);

	token_len++;
	str_arr = malloc(token_len * sizeof(char *));
	if (str_arr == NULL)
		return (NULL);

	for (i = 0, j = 0, k = 1, token_len--; i < token_len; i++, j += 2, k += 2)
	{
		token = _strndup(str, tokens_positions[j], tokens_positions[k]);
		str_arr[i] = remove_newline_char(token);
	}
	str_arr[i] = NULL;

	free(tokens_positions);

	return (str_arr);
}
*/
