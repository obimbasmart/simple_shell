#include "main.h"

/**
 * main - driver program for simple super shell
 * @argc: number of args passed to programm
 * @argv: array of args to programm
 * @env: array of environmet variables
 *
 * Return: 0 sucess
 */
int main(__attribute__((unused))int argc,
		__attribute__((unused)) char **argv, char **env)
{
	int is_terminal, response;
	char *lineptr, *token;
	char *_argv[] = { NULL, NULL };
	size_t lineLen;

	lineptr = NULL;
	lineLen = is_terminal = 0;
	response = 1;

	do {

		if (isatty(fileno(stdin) == 1))
		{
			_puts("#myShell$: ");
			is_terminal = 1;
		}

		getline(&lineptr, &lineLen, stdin);

		token = strtok(lineptr, " \r\n\t\v");

		while (token)
		{
			_argv[0] = token;
			response = _execute(_argv, env);
			token = strtok(NULL, " \r\t\n\v");
		}

		free(lineptr);
		lineptr = NULL;

	} while (is_terminal && response != -1);

	return (0);
}

