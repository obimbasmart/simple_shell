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
	size_t lineLen, nread;

	lineptr = token = NULL;
	lineLen = is_terminal = nread = 0;
	response = 1;

	signal(SIGINT, handle_sigint);

	do {

		if (isatty(fileno(stdin) == 1))
		{
			_puts("#myShell$: ");
			is_terminal = 1;
		}

		nread = getline(&lineptr, &lineLen, stdin);
		lineptr[nread - 1] = '\0';
		token = strtok(lineptr, DELIM);

		if (token)
		{
			_argv[0] = token;
			response = _execute(_argv, env);
		}

		free(lineptr);
		lineptr = NULL;

	} while (response != -1 && (is_terminal || token));

	return (0);
}


/**
 * handle_sigint - handler for SIGINT: CTRL+d
 * @signum: the signal ID
 *
 * Return: nothing
 */
void handle_sigint(int signum)
{
	if (signum == SIGINT)
		_puts("\n#myShell: ");

}

