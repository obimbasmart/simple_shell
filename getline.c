#include "main.h"

/**
 * _getline - a custom implementation of C getline func
 * @lineptr: buffer to store a line(string)
 * @n: initial size of lineptr
 * @stream: input stream
 *
 * Return: number of chars read
 */
ssize_t _getline(char **lineptr, size_t *n,
		FILE __attribute__((unused)) * stream)
{
	ssize_t nread_ret;
	size_t nread_t;
	int nread;
	char *buffer;
	char _char;

	nread = nread_t = 0;
	_char  = 'a';

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (nread_t == 0)
		fflush(stdout);
	else
		return (-1);

	buffer = malloc(sizeof(char) * shell_data.IN_BUFFSIZE);
	if (!buffer)
		return (-1);

	while (_char != '\n')
	{
		nread = read(STDIN_FILENO, &_char, 1);
		if (nread == -1 || (nread == 0 && nread_t == 0)) /* error or EOF */
		{
			free(buffer);
			free(*lineptr);
			return (-1);
		}
		if (nread == 0 && nread_t != 0) /* no more chars to read */
		{
			nread_t++;
			break;
		}
		if (nread_t >= shell_data.IN_BUFFSIZE) /* memory full */
		{
			shell_data.IN_BUFFSIZE *= 2;
			buffer = _realloc(buffer, nread_t, shell_data.IN_BUFFSIZE);
		}
		buffer[nread_t] = _char;
		nread_t += 1;
	}
	buffer[nread_t] = '\0';
	assign_buffer(buffer, lineptr, nread_t, n);
	nread_ret = nread_t;

	if (nread_ret)
		nread_t = 0;
	free(buffer);
	buffer = NULL;
	return (nread_ret);
}

/**
 * assign_buffer - assign buffer to lineptr
 * @buffer: pointer to char *
 * @lineptr: pointer to pointer to char *
 * @n_buff: size of buffer
 * @n_lineptr: size of lineptr
 *
 * Return: void
 */
void assign_buffer(char *buffer, char **lineptr,
		size_t n_buff, size_t *n_lineptr)
{
		if (*lineptr == NULL || *n_lineptr < n_buff)
		{
			*lineptr = _strdup(buffer);
			*n_lineptr = shell_data.IN_BUFFSIZE;
			return;
		}
		_strcpy(*lineptr, buffer);
}

