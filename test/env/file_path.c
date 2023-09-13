#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}

	i = 1;
	printf("%s:", av[i]);
	while (av[i])
	{
		if (stat(av[i], &st) == 0)
		{
			printf(" Found\n");
		}
		else
		{
			printf(" Not found\n");
		}
		i++;
	}

	return (0);
}
