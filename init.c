#include "main.h"

/**
 * execute_cmd - seeks to execute builtin functions
 * @argv: array of command-line arguments passed to the program
 *
 * Return: return to initiation of process if the command is not builtin
 */
int execute_cmd(char **argv)
{
	int (*builtin_func)(char **); /* function pointer to
						* hold the address of a builtin function
						*/

	if (argv[0] == NULL) /* no command */
		return (1);

	builtin_func = get_func(argv[0]); /* get the builtin function */

	if (builtin_func) /* if valid builtin */
		return (builtin_func(argv));

	return (init_process(argv));
}

/**
 * init_process - initiates the process
 *
 * @toks: array of command-line arguments passed to the program
 * Return: 1 on success
 */
int init_process(char **toks)
{
	static int cmd_num = 0, stat;
	pid_t pid;
	char *command_path = find_path(toks[0]);

	cmd_num++; /* ????? */
	pid = fork();
	if (pid == 0) /* if child */
	{
		if (access(toks[0], X_OK) == 0) /* if pathname is an executable*/
			execve(toks[0], toks, environ);

		else if (command_path != NULL) /* command found */
		{
			if (execve(command_path, toks, environ) == -1)
			{
				perror("hsh");
				free(command_path);
				exit(EXIT_FAILURE);
			}
			free(command_path);
		}
		else /* command not found */
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", cmd_num, toks[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* error: fork fail */
		perror("hsh");

	else /* parent is process is running */
	{
		do {
			waitpid(pid, &stat, WUNTRACED); /* wait for child process to exit
									* or get terminated by a signal
								*/

		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	free(command_path);
	
	return (1);
}
