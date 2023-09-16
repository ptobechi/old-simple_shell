#include "main.h"

char *find_cmd_full_path(char *cmd)
{
	p_ll *head = NULL, *temp;
	char *cmd_full_path;

	/** create linked list from env var PATH **/
	head = _create_p_ll();
	if (head == NULL)
		return (0);
	/** find dirs for command exec file **/
	temp = head;
	do
	{
		cmd_full_path = _strcat(temp->path, "/");
		cmd_full_path = _strcat(cmd_full_path, cmd);

		if (find_file(cmd_full_path) == 0)
			return (cmd_full_path);

		temp = temp->next;
	}
	while (temp->next != NULL);

	return (NULL);
}
