#include "main.h"

/**
 * token - This is a function that tokenize an input
 * @name: This is the command input by the user
 * Return: Char pointer
 */

char **token(char *name)
{
	int k, buf = BUFF;
	char **token1, *token2;

	if (name == NULL)
		return (NULL);

	token1 = malloc(sizeof(char *) * buf);
	if (token1 == NULL)
	{
		perror("hsh");
		return (NULL);
	}

	token2 = strtok(name, "\n ");
	for (k = 0; token2; k++)
	{
		token1[k] = token2;
		token2 = strtok(NULL, "\n ");
	}

	token1[k] = NULL;
	free(token2);
	return (token1);
}

/**
 * _getenv - gets the value Of enviroment variable
 * @n: environment variable name
 *
 * Return: the value of the variable or NULL
 */

char *_getenv(char *n)
{
	int k, l, m;
	size_t len_n, len_v;
	char *v;

	len_n = _strlen(n);
	for (k = 0 ; environ[k]; k++)
	{
		if (_strncmp(n, environ[k], len_n) == 0)
		{
			len_v = _strlen(environ[k]) - len_n;
			v = malloc(sizeof(char) * len_v);
			if (!v)
			{
				free(v);
				perror("unable to allocate memory");
				return (NULL);
			}

			m = 0;
			for (l = len_n + 1; environ[k][l]; l++, m++)
			{
				v[m] = environ[k][l];
			}
			v[m] = '\0';

			return (v);
		}
	}

	return (NULL);
}

/**
 * _realloc - reallocates memory
 * @ptr: pointer to previously allocated memory
 * @size_a: first allocation in bytes
 * @size_b: new allocted memory in bytes
 *
 * Return: ptr, NULL or a pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int size_a, unsigned int size_b)
{
	unsigned int k;
	void *d;
	char *filler, *ptrc;

	if (size_a == size_b)
		return (ptr);
	if (ptr == NULL)
	{
		d = malloc(size_b);
		if (d == NULL)
			return (NULL);
		return (d);
	}
	if (size_b == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptrc = ptr;
	d = malloc(sizeof(*ptrc) * size_b);
	if (d == NULL)
	{
		free(ptr);
		return (NULL);
	}
	filler = d;

	for (k = 0; k < size_a && k < size_b; k++)
		filler[k] = *ptrc++;
	free(ptr);
	return (d);
}
