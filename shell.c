#include "main.h"

/**
 * main - driver program for simple super shell
 * @argc: number of args passed to programm
 * @argv: array of args to programm
 * @env: array of environmet variables
 *
 * Return: 0 sucess
 */

/* define global variable for shell data */
s_data_t shell_data;

int main(__attribute__((unused))int argc, char **argv, char **env)
{
	/* int response; */
	char *lineptr;
	size_t nline, nlen;
	char **_argv;
	ssize_t nread;

	lineptr = NULL;
	shell_data._isterminal = nread = nlen = 0;
	signal(SIGINT, handle_sigint);

	do {

		_isatty();
		nread = getline(&lineptr, &nline, stdin);
		/* check for end of file */
		if (nread == -1)
			break;

		_argv = tokenize(lineptr);

		if (_argv[0])
		{
			if (!f_exist(_argv[0]) || _argv[1])
				perror(argv[0]);
			else
				shell_data.response = _execute(_argv, env);
		}

	} while (shell_data._isterminal);

	free(lineptr);
	lineptr = NULL;
	return (0);
}

