#include "main.h"

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

/**
 * _execute - function executes a program passed as arg
 * @argv: array of args to program
 * @env: array of environmet variables
 *
 * Return: 0 sucess
 */
int _execute(char **argv, char **env)
{
	int status;
	pid_t child_pid;

	child_pid = fork();

	if (strcmp(argv[0], "exit") == 0)
		return (-1);

	status = 0;
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			perror(argv[0]);

		exit(0);
	}

	wait(&status);
	return (0);
}

/**
 *  _isatty - check if input is form terminal
 *
 * Return: nothing
 */
void _isatty(void)
{
	if (isatty(fileno(stdin)) == 1)
	{
		_puts("#myShell$: ");
		shell_data._isterminal = 1;
	}
	shell_data._isterminal = 0;
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
	char *token, *str_c = str;
	char **array_s = malloc(sizeof(char *) * size);

	token = strtok(str, DELIM);
	
	idx = 0;
	while (token)
	{
		size++;
		array_s = realloc(array_s, sizeof(char *) * size);
		array_s[idx] = strdup(token);
		token = strtok(NULL, DELIM);
		idx++;
	}

	array_s[idx] = token;
}








