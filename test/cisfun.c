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
	size_t n = 0;
	char **_argv = NULL; //doubt it will work
	char *token, *delim = " ";
	int i, token_len;

	while (1)
	{
		printf("ghst$ ");

		vread = getline(&lineptr, &n, stdin);

		/** check value passed from cmd line*/
		if (vread == -1)
			perror("Invalid Argument passed");
		else
		{
			//get token length for mem alloc
			token_len = get_token_len(lineptr, delim);
			printf("%d\n", token_len);

			//memory reallocation for _argv
			_argv = malloc(sizeof(char *) * token_len);

			/** tokenization using strtok */
			token = strtok(lineptr, delim);

			//i = 0;
			while (token != NULL)
			{
				_argv[i] = token;

				strtok(NULL, delim);
				//i++;
			}

			//for (i = 0; i < token_len; i++)
			//{
				printf("%s\n", _argv[i]);
			//}

		}
	}
	free(_argv);
	free(lineptr);
	return (0);
}
