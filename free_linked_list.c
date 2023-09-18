#include "main.h"

void _free_linked_list(p_ll *head)
{
	p_ll *temp;

	while (head != NULL)
	{
		temp = head;
		head = temp->next;
		free(temp);
	}
}


