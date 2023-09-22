#include "main.h"

void rm_trailing_space(char *s)
{
	int i, tr_sp_start_pos;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ' && s[i + 1] == ' ')
		{
			tr_sp_start_pos = i + 1;
		}
	}
	s[tr_sp_start_pos] = '\0';
}


int main(void)
{
	char s[20] = "Hello     ";
	char str[50] = "/bin/ls /bin/ls    /bin/ls            ";

	printf("%s\n", s);
	rm_trailing_space(s);
	printf("%s\n", s);

	printf("%s\n", str);
	rm_trailing_space(str);
	printf("%s\n", str);

	return (0);
}
