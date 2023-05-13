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
