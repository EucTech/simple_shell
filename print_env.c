#include "main.h"
/**
 * print_env - This is a function that will print the enviroment
 * @sta: This is a status executable
 * @cmd: This is a pointer to the environ
 * Return: Void
 */

int print_env(char **cmd, int sta)
{
	size_t k;
	int total;
	(void)cmd;
	(void)sta;

	for (k = 0; environ[k] != NULL; k++)
	{
		total = _strlen(environ[k]);
		write(STDOUT_FILENO, environ[k], total);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
