#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	int status, count = 5;
	pid_t my_pid;
	pid_t child_pid;
	char *argv[] = {"/bin/ls",  NULL};

	while(count--)
	{
		child_pid = fork();
		my_pid = getpid();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("execve in child\n");
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Execve Error:");
				return (1);
			}
		}
		else
		{
			wait(&status);
			if (status == -1)
			{
				perror("Error:");
				return (1);
			}
			printf("ppid - getpid()-- %u\n", getpid());
			printf("ppid - child_pid -- %u\n", child_pid);
			printf("ppid - my_pid -- %u\n", my_pid);
		}
	}
	return (0);
}
