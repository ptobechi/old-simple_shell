#include <stdio.h>
#include <stdlib.h>

char *_strndup(char *s, int start, int end)
{
	char *s_dup;
	int i = 0;

	while (s[++i] != '\0');

	if (start > i || end > i || start >= end)
		return (NULL);

	i = end - start;
	i++;

	s_dup = malloc(i * sizeof(char));
	if (s_dup == NULL)
		return (NULL);

	for (i = 0; start <= end; i++, start++)
		s_dup[i] = s[start];

	s_dup[i] = '\0';

	return (s_dup);
}

char **_strtok(char *str, char *delim)
{
	int i;
	char **str_arr;
	int token_len = count_tokens(str);

	str_arr = get_sub_str(str, delim);

	for (i = 0; i < token_len; i++)
		printf("%s\n", str_arr[i]);

	return (str_arr);
}

int main(void)
{
	int i = 0, j = 0, k = 1;
	char *str = "hello world again! How are you?";
	char *delim = " ";
	char **str_arr;

	str_arr = _strtok(str, delim);

	free(str_arr);

	return (0);
}
