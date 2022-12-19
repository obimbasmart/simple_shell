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
	char *lineptr, *lineptr_c;
	size_t nline, nlen;
	/* char *_argv[] = {NULL, NULL}; */
	char **_argv;
	ssize_t nread;

	lineptr = lineptr_c = NULL;
	shell_data._isterminal = nread = nlen = 0;
	signal(SIGINT, handle_sigint);

	do {

		_isatty();
		nread = getline(&lineptr, &nline, stdin);
		/* check for end of file */
		if (nread == -1)
			break;

		/* lineptr[nread - 1] = '\0'; */
		/* lineptr_c = TrimWhiteSpace(lineptr); */

		_argv = tokenize(lineptr);
		/* if (nread > 1 && strlen(lineptr_c)) */
		if (_argv[0] && !f_exist(_argv[0]))
			perror(argv[0]);

		else
			{
				if (_argv[1] && !f_exist(_argv[1]))
					perror(argv[0]);
				else
					shell_data.response = _execute(_argv, env);
			}

	} while (lineptr || shell_data._isterminal);

	free(lineptr);
	lineptr = NULL;
	return (0);
}

