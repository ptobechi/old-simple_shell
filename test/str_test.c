#include <stdio.h>

void mod_s(char *str)
{
	str += 4;

	printf("%s\n", str);
}

int main(void)
{
	char *s = "Hello world";

	mod_s(s);

	return (0);
}
