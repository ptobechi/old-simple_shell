#include "main.h"

/**
 * run_cmd - execute cmd
 * @_argv: array of null terminated strings
 * @envp: environment variables
 *
 * Return: void
 */
void run_cmd(char **_argv, char **envp)
{
	int status, handle_flag = 0;
	pid_t child_p;
	char *cmd_path, **env_var = NULL;

	/** get command location*/
	cmd_path = get_cmd_path(_argv[0], &handle_flag);
	/** create custom environment path */
	env_var = _create_env_table(envp);
	if (cmd_path == NULL)
	{
		free(env_var);
		free(cmd_path);
		_err_msg("./hsh: 1", _argv[0], " not found\n");
		exit(127);
	}
	else
	{
		child_p = fork();

		if (child_p == 0)
			if (execve(cmd_path, _argv, env_var) == -1)
				perror((char *)EACCES);

		if (handle_flag)
			free(cmd_path);
	}
	free_2d_array(env_var);

	/* Parent process*/
	waitpid(child_p, &status, 0);

	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		exit(2);
}

