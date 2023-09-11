#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

int main()
{
	char *line;
	char *token;
	char *delim = " |";
	char *lineptr = NULL;
	size_t n = 0;

	if (getline(&lineptr, &n, stdin) == -1)
		return (-1);
	
	token = strtok(lineptr, delim);

	printf("%s\n", token);
	token = strtok(lineptr, delim);


	printf("%s\n", token);
	return (0);
}
