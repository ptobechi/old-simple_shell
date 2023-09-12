#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int get_token_len(char *lineptr, char *delim)
{
	char *token;
	int count = 0;

	do {
		token = strtok(lineptr, delim);
		lineptr = NULL;
		count++;
	} while (token != NULL);

	return (count);
}

char *remove_newline_char(char *s)
{
	int i = 0;

	while (s[++i] != '\0');

	if (s[i - 1] == '\n')
		s[i - 1] = '\0';

	return (s);
}

int main(void)
{
	//char *argv[] = {"./test", "Hello World", "It is Working",  NULL};
	char *argv[] = {"/bin/ls", "ls", "/usr", NULL};

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
		{
			token = remove_newline_char(token);
			argv[i++] = token;
		}

	} while (token != NULL);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error:");
		return (1);
	}
	if (child_pid == 0)
	{
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
