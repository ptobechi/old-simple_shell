#include <stdio.h>
#include <string.h>

int main()
{
//	char _char[] = "Hello, boy, yes";
	char *delim = " ";
	char *token;
	char *lineptr = NULL;
	size_t n;

	ssize_t rvalue = getline(&lineptr, &n, stdin);
	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		printf("%s\n", token);

		token = strtok(NULL, delim);
	}
	return (0);
}
