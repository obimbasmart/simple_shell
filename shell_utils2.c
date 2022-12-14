#include "main.h"

/**
 * _puts - function that writes a string to stdout
 * @str: string to write
 *
 * Return: number of bytes written to stdout
 */
size_t _puts(char *str)
{
	if (str == NULL)
	{
		return (write(STDOUT_FILENO, "(null)", 6));
	}
	return (write(STDOUT_FILENO, str, strlen(str)));
}

/**
 * tokenize - split a string into tokens
 * @str: original string
 *
 * Return: array of strings
 */
char **tokenize(char *str)
{
	size_t idx, size = 3;
	char *token;
	char **array_s = malloc(sizeof(char *) * size);

	token = strtok(str, DELIM);
	idx = 0;
	while (token)
	{
		array_s[idx] = strdup(token);
		token = strtok(NULL, DELIM);
		idx++;
	}
	array_s[idx] = token;
	return (array_s);
}
