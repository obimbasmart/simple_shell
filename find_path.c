#include "main.h"

/**
 * find_path - function looks for files in the current PATH
 * @cmd: command(filename, filepath)
 *
 * Return: full path to file (executable)
 */
char *find_path(char *cmd)
{
	char *dir, *command_path, *path, *path_copy;

	path = getenv("PATH");
	command_path = NULL;

	/* check if path is already valid */
	if (access(cmd, X_OK) == 0)
		return (cmd);

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		/* char *command_path = malloc(_strlen(dir) + _strlen(cmd) + 2); */
		command_path = malloc(sizeof(char) * TOKEN_BUFFSIZE);
		sprintf(command_path, "%s/%s", dir, cmd);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		dir = strtok(NULL, ":");

		free(command_path);
	}
	free(path_copy);
	return (NULL);
}
