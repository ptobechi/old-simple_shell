#include <stdio.h>
#include <stdlib.h>

int count_tokens(char *str)
{
	int i = 0, count = 1;

	if (str == NULL)
		return (-1);

	if (str[0] == '\0')
		return (0);

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}

	return (count);
}

char *_strdup(char *s)
{
	char *s_dup;
	int i = 0;

	while (s[++i] != '\0');

	i++;
	s_dup = malloc(i * sizeof(char));
	if (s_dup == NULL)
		return (NULL);

	i = 0;
	while (s[i] != '\0')
	{
		s_dup[i] = s[i];
		i++;
	}

	s_dup[i] = '\0';

	return (s_dup);
}

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

int *get_token_pos_arr(char *str)
{
	int i, j, token_len;
	int *token_pos_arr;

	token_len = count_tokens(str);
	token_pos_arr = malloc(token_len * 2 * sizeof(int));
	if (token_pos_arr == NULL)
		return (NULL);

	printf("%d\n", token_len);
	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (i == 0)
		{
			token_pos_arr[j] = 0;
			j++;
		}
		if (str[i] == ' ')
		{
			token_pos_arr[j] = i - 1;
			j++;
			token_pos_arr[j] = i + 1;
			j++;
		}
		if (str[i + 1] == '\0')
			token_pos_arr[j] = i;
	}
	return (token_pos_arr);
}

char **get_sub_str(char *str, int *token_pos_arr)
{
	int i, j, k;
	char **str_arr = NULL;
	int token_len = count_tokens(str);

	str_arr = malloc(token_len * sizeof(char*));
	if (str_arr == NULL)
		return (NULL);

	for (i = 0, j = 0, k = 1; i < token_len; i++, j += 2, k += 2)
		str_arr[i] = _strndup(str,token_pos_arr[j], token_pos_arr[k]);

	free(token_pos_arr);

	return (str_arr);
}

int main(void)
{
	int i = 0, j = 0, k = 1;
	char *str = "hello world again";
	char **str_arr;
	int token_len = count_tokens(str);

	str_arr = get_sub_str(str, get_token_pos_arr(str));

	for (i = 0; i < token_len; i++)
		printf("%s\n", str_arr[i]);

	for (i = 0; i < token_len; i++)
		free(str_arr[i]);

	free(str_arr);

	return (0);
}
