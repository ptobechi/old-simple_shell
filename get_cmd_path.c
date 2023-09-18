#include "main.h"

char *get_cmd_path(char *cmd)
{
	char *cmd_full_path, *cmd_parent_path;
	p_ll *head = NULL, *temp;

	if (cmd == NULL)
		return (NULL);

	if (cmd[0] == '/' || find_file(cmd) == 0)
		return (cmd);

	/** create linked list from env var PATH **/
	head = create_path_ll();
	if (head == NULL)
		return (0);

	/** find dirs for command exec file **/
	temp = head;
	do
	{
		cmd_parent_path = _strcat(temp->path, "/");
		cmd_full_path = _strcat(cmd_parent_path, cmd);

		if (find_file(cmd_full_path) == 0)
			break;

		cmd_full_path = NULL;

		temp = temp->next;
	}
	while (temp->next != NULL);

	return (cmd_full_path);
}
