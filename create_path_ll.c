#include "main.h"

p_ll *create_path_ll(void)
{
	p_ll *head = NULL, *new, *temp;
	char *name = "PATH", *val, **tokens, delim = ':';
	int i;

	(void)new;
	(void)temp;

	val = _getenv(name);

	if (val == NULL)
		return (NULL);

	tokens = _strtok(val, delim);

	for (i = 0; tokens[i] != NULL; i++)
	{
		head = append_node(head, _strdup(tokens[i]));

		if (val != NULL)
		{
			free(val);
			val = NULL;
		}
	};

	free_2d_array(tokens);
	return (head);
}
