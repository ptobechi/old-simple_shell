#include <stdio.h>

/**
 * getline - imitates a std getline
 * @lineptr: pointer to string value
 * @n: dynamically allocates memory of n size to the string
 * @stream: stream source
 *
 * Return: Always 0 (Success)
*/
/** stream = fopen(filepathname, "r")*/
ssize_t _getline(char **restrict lineptr, size_t  *restrict n, FILE *restrict stream)
{
	/*store address of stream to lineptr*/
	/*stream = Hello World */
	lineptr = &stream;
}

/**
 * main - Entry Point
 *
 * Return: Always 0 (success)
*/
int main()
{
	FILE *stream;
	size_t n = 0;
	char *lineptr = NULL;
	ssize_t nread;

	nread = _getline(&lineptr, &n, stream);

	printf("Line Read is %zd:\n", nread);
}
