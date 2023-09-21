#include "main.h"

/**
 * get_cmd_path - search for executable cmd
 * @cmd: command
 * @flag: handle path mode
 *
 * Return: location pointer
 */
char *get_cmd_path(char *cmd, int *flag)
{
	char *cmd_full_path, *cmd_parent_path;
	p_ll *head = NULL, *temp;

	if (cmd == NULL)
		return (NULL);

	/**if a full path or path exists return path*/
	/**if (cmd[0] == '/' || find_file(cmd) == 0)*/
	if (cmd[0] == '/' || cmd[0] == '.')
		return (cmd);

	/** create linked list from env var PATH **/
	head = create_path_ll();
	if (head == NULL)
		return (NULL);

	/** find dirs for command exec file **/
	temp = head;
	do {
		cmd_parent_path = _strcat(temp->path, "/");
		cmd_full_path = _strcat(cmd_parent_path, cmd);

		free(cmd_parent_path);
		if (find_file(cmd_full_path) == 0)
			break;

		free(cmd_full_path);
		cmd_full_path = NULL;
		temp = temp->next;

	} while (temp->next != NULL);

	_free_linked_list(head);
	*flag = 1;
	return (cmd_full_path);
}
