#include "main.h"

char *get_cmd_path(char *cmd)
{
	char *cmd_full_path;

	if (cmd[0] == '/' || find_file(cmd) == 0)
		return (cmd);

	cmd_full_path = find_cmd_full_path(cmd);
	if (cmd_full_path != NULL)
		return (cmd_full_path);

	return (NULL);
}
