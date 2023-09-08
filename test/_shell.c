#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	size_t n = 0, rvalue;
	char *lineptr;
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("$ ");
		rvalue = getline(&lineptr, &n, stdin);

		if (rvalue == -1)
		{
			perror("Closing Shell..");
			return (-1);
		}

		printf("%s\n", lineptr);
	}
	free(lineptr);
	return (0);
}

