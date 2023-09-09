#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "hello";
	char *sc = "";

	strcpy(sc, s);

	printf("%s\n", sc);

	return (0);
}
