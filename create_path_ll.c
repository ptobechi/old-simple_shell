#include "main.h"

p_ll *create_path_ll(void)
{
	p_ll *head = NULL, *new, *temp;
	char *name = "PATH", *val, *token, *delim = ":";

	(void)new;
	(void)temp;

	val = _getenv(name);

	if (val == NULL)
		return (NULL);

	printf("%s\n", val);
	while ((token = strtok(val, delim)) != NULL)
	{
		head = append_node(head, _strdup(token));

		if (val != NULL)
		{
			free(val);
			val = NULL;
		}
	};

	return (head);
}
