#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
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

	//{"/", "|", ">", "<", " ",}; //delimiters

	//int count = 1;
	//while (*lineptr != '\0')
	//{
	//	if (*lineptr == *delim)
	//		count++;
	//	lineptr++;
	//}
	return (count);
}

/**
 * main - Entry Point
 * @argc: argument count
 * @argv: argument variable
 *
 * Return: Always 0 (Suceess)
 */
int main(int argc, char **argv)
{
	char *lineptr = NULL;
	ssize_t vread;
	size_t n;
	char **_argv = NULL;
	char *token, *delim = " ";
	int i, token_len;

	while (1)
	{
		printf("ghst$ ");

		//get values from cmd line
		vread = getline(&lineptr, &n, stdin);

		/** check value passed from cmd line*/
		if (vread == -1)
			perror("Invalid Argument passed");
		else
		{
			//get token length for mem alloc
			token_len = get_token_len(lineptr, delim);
			//printf("%d\n", token_len);

			//memory reallocation for _argv
			_argv = malloc(sizeof(char *) * token_len);

			token = strtok(lineptr, delim);

			//parsing token to cmd table
			i = 0;
			while (token != NULL)
			{
				_argv[i] = token;
				token = strtok(NULL, delim);
				i++;
			}
			i++;
			_argv[i] = NULL;


			//create a child process to execute cmd
			pid_t child_p = fork();
			int status;
			//char *arg[] = {"/bin/ls", "/usr", NULL};
			if (child_p == 0)
				if (execve(_argv[0], _argv, NULL) == -1)
					perror("Failed to exec function");
			wait(&status);
		}
	}

	free(_argv);
	free(lineptr);
	return (0);
}
