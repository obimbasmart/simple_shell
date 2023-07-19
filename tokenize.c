#include "main.h"

/**
 *tokenize_string - splits the string into tokens(small chunks of words)
 *@lineptr: pointer to the line read from the command-line
 *
 *Return: returns pointer to the array of tokens
 */
char **tokenize_string(char *lineptr)
{
	int buf = TOKEN_BUFFSIZE, index = 0;
	char **toks = malloc(buf * sizeof(char*));
	char *token;
	const char *delim = " \n\t";
	char *error = "tsh: allocation error\n";

	if (toks == NULL)
	{
		write(STDERR_FILENO, error, _strlen(error));
		exit(EXIT_FAILURE);
	}
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		toks[index] = token;
		index++;
		if (index >= buf)
		{
			if (!toks)
			{
				write(STDERR_FILENO, error, _strlen(error));
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	toks[index] = NULL;

	return toks;
}

/**
 * free_tokens - free an array of strings from memory
 * @toks: array of tokens
 *
 * Return: nothing
 */
void free_tokens(char **toks)
{
	/*int i;*/

	/*for (i = 0; toks[i] != NULL; i++) */
	/*{ */
	/*	free(toks[i]); */
	/*} */
	/*free the memory allocated for the toks array*/
	free(toks);
}
