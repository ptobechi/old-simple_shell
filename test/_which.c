#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	unsigned int i = 1;
	struct stat st;

	if (argc < 2)
	{
		printf("Invalid argument number\n");
		return (1);
	}

	while(argv[i])
	{
		printf("%s",argv[i]);
		if (stat(argv[i], &st) == 0)
			printf("Found\n");
		else
			printf("Not found\n");
		i++;
	}
	return (0);
}
