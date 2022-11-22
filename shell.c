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
	char *lineptr;
	char *new_argv[2];
	size_t lineLen, nread;

	lineptr = NULL;
	lineLen = is_terminal = 0;
	new_argv[0] = NULL;

	do {

		if (isatty(fileno(stdin) == 1))
		{
			_puts("#mySimpleShell$: ");
			is_terminal = 1;
		}

		nread = getline(&lineptr, &lineLen, stdin);
		lineptr[nread - 1] = '\0';
		new_argv[0] = lineptr;
		new_argv[1] = NULL;

		response = _execute(new_argv, env);
		free(lineptr);
	} while (is_terminal && response);

	return (0);
}

