#include "main.h"
/**
 * print_env - This is a function that will print the enviroment
 * Return: Void
 */

void print_env(void)
{
	size_t k;
	int total;

	for (k = 0; environ[k] != NULL; k++)
	{
		total = _strlen(environ[k]);
		write(STDOUT_FILENO, environ[k], total);
		write(STDOUT_FILENO, "\n", 1);
	}
}
