#include "main.h"

p_ll *_create_p_ll(void)
{
	p_ll *head = NULL, *new, *temp;
	char *name = "PATH", *val, *token, *delim = ":";

	val = _getenv(name);

	if (val == NULL)
		return (NULL);

	do {
		token = strtok(val, delim);
		if (token != NULL)
			head = append_node(head, _strdup(token));
		
		if (val != NULL)
			free(val);

		val = NULL;
	} while (token != NULL);

	return (head);
}
