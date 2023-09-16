#include "main.h"

p_ll *append_node(p_ll *head, char *path)
{
	p_ll *new, *temp;

	new = malloc(sizeof(p_ll *));
	if (new == NULL)
		return (NULL);

	new->path = path;
	new->next = NULL;

	if (head == NULL)
		head = new;
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (head);
}
