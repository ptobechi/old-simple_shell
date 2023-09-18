#include "main.h"

/**
 * find_file - find the file
 * @file_path: path to file
 *
 * Return: 1 if found, -1 otherwise
*/
int find_file(char *file_path)
{
	struct stat st;

	if (file_path == NULL)
	{
		printf("File path is NULL\n");
		return (-1);
	}

	if (stat(file_path, &st) < 0)
		return (-1);

	return (0);
}
