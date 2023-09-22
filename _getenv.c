#include "main.h"

/**
 * _create_env_table - create a custom env command table
 * @envp: environment variable
 *
 * Return: Returns a pointer
 */
char **_create_env_table(char **envp)
{
	/*Count the number of environment variables*/
	int count = 0, i;
	char **env;

	while (envp[count] != NULL)
		count++;

	/* Allocate memory for the array of environment variables*/
	env = (char **)malloc((count + 1) * sizeof(char *));
	if (env == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	memset(env, 0, (count + 1));

	/* Copy each environment variable to the new array*/
	for (i = 0; i < count; i++)
	{
		env[i] = _strdup(envp[i]);
		if (env[i] == NULL)
		{
			perror("Memory allocation failed");
			exit(1);
		}
	}
	/* Add a NULL terminator to the end of the array*/
	env[count] = NULL;

	return (env);
}

/**
 * _getenv - get environment variable
 *
 * @name: Environment path
 *
 * Return: Always 0 (Sucess)
 */
char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;
	char *val = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strccmp(environ[i], name, '=') == 0)
		{
			while (name[++j] != '\0')
				;

			while (environ[i][++k] != '\0')
				;

			val = malloc((k - j) * sizeof(char));
			if (val == NULL)
				return (NULL);

			for (k = 0, j++; environ[i][j] != '\0'; j++, k++)
				val[k] = environ[i][j];

			val[k] = '\0';
			break;
		}
	}
	return (val);
}
