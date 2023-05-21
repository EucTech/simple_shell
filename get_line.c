#include "main.h"

/**
 * _getline - gets a string from input
 * @lptr: buffer that stores input
 * @stream: the stream to read imput
 * @l: lptr size
 *
 * Return: bytes read
 */

ssize_t _getline(char **lptr, size_t *l, FILE *stream)
{
	char *buff;
	char c = 'x';
	int fr;
	ssize_t byt;
	static ssize_t in;

	if (in == 0)
		fflush(stream);
	else
		return (-1);
	in = 0;
	buff = malloc(sizeof(char) * 120);
	if (!buff)
		return (-1);
	while (c != '\n')
	{
		fr = read(STDIN_FILENO, &c, 1);
		if (fr == -1 || (fr == 0 && in == 0))
		{
			free(buff);
			return (-1);
		}
		if (fr == 0 && in != 0)
		{
			in++;
			break;
		}
		if (in >= 120)
			buff = _realloc(buff, in, in + 1);
		buff[in] = c;
		in++;
	}
	buff[in] = '\0';

	allocate_lptr(lptr, l, buff, in);
	byt = in;
	if (fr != 0)
		in = 0;
	return (byt);
}


/**
 * allocate_lptr - allocates the lptr variable
 * @lptr: a buffer that stores input
 * @buff: string to assign to lptr
 * @l: lptr size
 * @b: buff size
 *
 * Return: nothing
 */

void allocate_lptr(char **lptr, size_t *l, char *buff, size_t b)
{
	if (*lptr == NULL)
	{
		if (b > 120)
			*l = b;
		else
			*l = 120;
		*lptr = buff;
	}
	else if (*l < b)
	{
		if (b > 120)
			*l = b;
		else
		{
			*l = 120;
		}
		*lptr = buff;
	}
	else
	{
		_strcpy(*lptr, buff);
		free(buff);
	}
}

