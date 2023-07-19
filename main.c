#include "main.h"
/*
 * main - Entry point to the shell loop
 *
 * Return: 0 on Success
 */
int main(void)
{
	myshell_loop();
	return (0);
}

/*
 * myshell_loop - shell loop
 *
 * Return: return void
 */
void myshell_loop(void)
{
	char *lineptr = NULL;
	char **argv = NULL;
	int stat;
	char *prompt = "$";
	size_t buf = 0; /*buffer size allocated by getline()*/
    ssize_t charsRead;

	do {
		if (isatty(STDIN_FILENO)) /* interactive mode */
		{
			write(STDIN_FILENO, prompt, _strlen(prompt));
			fflush(stdout);
		}

		charsRead = getline(&lineptr, &buf, stdin);
		if (charsRead == -1)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\r", 1);
				free(lineptr);
				exit(0);/*EOF is received*/
			}
			else
			{
				perror("can't read line");
				free(argv);
				exit(0);
			}
		}
		argv = tokenize_string(lineptr); /* split line into tokens */
		stat = execute_cmd(argv);

		free(argv);		
	} while (stat);
	
	free(lineptr);
}
