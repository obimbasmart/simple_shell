#include "main.h"

/**
 * f_exist - checks the the status of a file
 * @path: path to file
 *
 * Return: 0 if file is found, -1 if not
 */
int f_exist(char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
		return (1);

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
	(void)signum;
	/* if (signum == SIGINT) */
		;/* _puts("\n#myShell: "); */

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

	/* if (strcmp(argv[0], "exit") == 0) */
		/* return (-1); */

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
	else
		shell_data._isterminal = 0;
}
