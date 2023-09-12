#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	char *lineptr, *lineptr_dup, *token;
	size_t n = 0;
	char *delim = " |";
	int token_len, i, status;
	char **argv = NULL;
	pid_t child_pid;
	char *path = "/bin/ls\n";

	if (getline(&lineptr, &n, stdin) == -1)
	{
		perror("getline error:");
		return (1);
	}

	lineptr_dup = strdup(lineptr);

	token_len = get_token_len(lineptr_dup, delim);
	free(lineptr_dup);

	argv = malloc(token_len * sizeof(char *));

	i = 0;
	do
	{
		token = strtok(lineptr, delim);
		lineptr = NULL;

		if (token != NULL)
			printf("%ld\n", strlen(token));

		argv[i++] = token;
	} while (token != NULL);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("%s--\n", argv[0]);
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Execve error:");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		if (status == -1)
		{
			perror("Wait error:");
			return (-1);
		}
		printf("child(%d) terminated successfully\n", status); 
	}

	free(lineptr);
	free(argv);
	return (0);
}


