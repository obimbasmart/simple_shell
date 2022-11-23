#include "main.h"

/**
 * tokenize - function that splits a string into tokens
 * @str: original string
 * @delim: delimeters or seperators
 *
 * Return: array of valid tokens
 */

char **tokenize(char *str, char *delim)
{
	char **arr_tokens;
	char *token;
	unsigned int n_token, i;
	char *str_copy;

	str_copy = strdup(str);
	n_token = i = 0;

	token = strtok(str, delim);
	while (token)
	{
		n_token++;
		token = strtok(NULL, delim);
	}

	arr_tokens = malloc(sizeof(*arr_tokens) * (n_token + 1));
	if (!arr_tokens)
	{
		dprintf(STDERR_FILENO, "Error: malloc - failed to allocate memory\n");
		return (NULL);
	}

	token = strtok(str_copy, delim);
	while (token)
	{
		arr_tokens[i] = malloc(sizeof(char) * strlen(token));
		strcpy(arr_tokens[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	arr_tokens[i] = token;

	return (arr_tokens);
}
