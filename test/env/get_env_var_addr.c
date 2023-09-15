#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("address of env from main third para: %p\n", (void*)env);
	printf("address of global env: %p\n", (void*)environ);

	return (0);
}
