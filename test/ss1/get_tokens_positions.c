#include "main.h"

int *get_tokens_positions(char *str, char delim)
{
	int i, j;
	int token_len = get_token_len(str, delim);
	int *tokens_positions = malloc(token_len * 2 * sizeof(int));

	if (tokens_positions == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (i == 0)
		{
			tokens_positions[j] = 0;
			j++;
		}
		if (str[i] == delim)
		{
			tokens_positions[j] = i - 1;
			j++;
			tokens_positions[j] = i + 1;
			j++;
		}
		if (str[i + 1] == '\0')
			tokens_positions[j] = i;
	}
	return (tokens_positions);
}
