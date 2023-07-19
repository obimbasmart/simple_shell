#include "main.h"

char *builtin_arr[] = { "cd", "exit",
}; /* array of strings: builtin commands */

int (*builtin_func[]) (char **) = { &my_cd, &my_exit,
}; /* array of function pointers */

/**
 * builtins_number - return the number of builtin functions
 *
 * Return: int
 */
int builtins_number(void)
{
	return (sizeof(builtin_arr) / sizeof(char *));
}


/**
 * init_process - initiates the process
 *
 * @toks: array of command-line arguments passed to the program
 * Return: 1 on success
 */
int init_process(char **toks)
{
	static int cmd_num = 0;
	pid_t pid;
	int stat;
	char *command_path = find_path(toks[0]);

	cmd_num++; /* ????? */
	pid = fork();

	if (pid == 0) /* if child */
	{
		if (access(toks[0], X_OK) == 0) /* if pathname is an executable*/
			execve(toks[0], toks, environ);

		else if (command_path != NULL)
		{
			if (execve(command_path, toks, environ) == -1)
			{
				perror("hsh");
				free(command_path);
				exit(EXIT_FAILURE);
			}
			free(command_path);
		}
		else
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", cmd_num, toks[0]);
			free(command_path); /* free command_path if NULL*/
			free(toks);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* error: fork fail */
		perror("hsh");

	else /* parent is process is running */
	{
		do {
			waitpid(pid, &stat, WUNTRACED); /* wait for child process to exit or
											 * get terminated by a signal
											 */
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return (1);
}

/**
 * execute_cmd - seeks to execute builtin functions
 * @argv: array of command-line arguments passed to the program
 *
 * Return: return to initiation of process if the command is not builtin
 */
int execute_cmd(char **argv)
{
	int j;

	if (argv[0] == NULL) /* no command */
		return (1);

	for (j = 0; j < builtins_number(); j++)
	{
		if (_strcmp(argv[0], builtin_arr[j]) == 0)
			return ((*builtin_func[j])(argv));
	}
	return (init_process(argv));
}
