#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

int main(void)
{
	char *_env;

	_env = _getenv("LS_COLORS");

	if (_env != NULL)
		printf("%s\n", _env);
	else
		printf("Env var not found\n");

	free(_env);
	return (0);
}
