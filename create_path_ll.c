#include "main.h"

/**
 * create_path_ll - create linked list
 *
 * Return: void
 */
p_ll *create_path_ll(void)
{
	p_ll *head = NULL;
	char *name = "PATH", *val, **tokens, delim = ':';
	int i;

	val = _getenv(name);

	if (val == NULL)
		return (NULL);

	tokens = _strtok(val, delim);

	for (i = 0; tokens[i] != NULL; i++)
	{
		head = append_node(head, _strdup(tokens[i]));
	};

	free(val);
	free_2d_array(tokens);
	return (head);
}
