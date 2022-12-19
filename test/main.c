#include "main.h"

int main()
{
	char str[] = "Obimba Smart is a boy";
	char **arr = tokenize(str);
	
	int idx = 0;
	while (arr[idx])
	{
		printf("No %d: %s\n", idx + 1, arr[idx]);
		idx++;
	}
}
/**
 * tokenize - split a string into tokens
 * @str  - original string
 *
 * Return: array of strings
 */
char **tokenize(char *str)
{
	size_t idx, size = 1;
	char *token;
	char **array_s = malloc(sizeof(char *));

	token = strtok(str, DELIM);
	
	idx = 0;
	while (token)
	{
		array_s = realloc(array_s, sizeof(char *) * ++size);
		array_s[idx] = strdup(token);
		token = strtok(NULL, DELIM);
		idx++;
	}
	array_s[idx] = token;
	return (array_s);
}

