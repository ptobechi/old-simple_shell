#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - ENtry Point
 *
 * Return: Always 0 (success);
 */
int main()
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t child_id, child_id2, child_id3;
	int status;

	child_id = fork();

	if (child_id == -1)
	{
		perror("Failed to create child ID");
		return (1);
	}
	if (child_id == 0)
		execve(argv[0], argv, NULL);

	wait (&status);

	child_id2 = fork();
	if (child_id2 == -1)
	{
		perror("Failed at 2");
		return (1);
	}
	if (child_id2 == 0)
		execve(argv[0], argv, NULL);

	wait(&status);

	child_id3 = fork();
	if (child_id3 == -1)
	{
		perror("Failed at 2");
		return (1);
	}
	if (child_id3 == 0)
		execve(argv[0], argv, NULL);

	wait(&status);

	return (0);
}
