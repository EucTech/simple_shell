#include "main.h"

/**
 * main - This is a function that takes command line arguments
 * and execute it
 * @ac: This is the number of the command line arguments
 * @av: This is the argument vectors
 * Return: 0
 */

int main(int ac, char **av)
{
	ssize_t g_line;
	char *pointer;
	size_t n = 0;

	(void)ac;
	(void)av;

	signal(SIGINT, sig_handle);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		g_line = getline(&pointer, &n, stdin);
		if (g_line == EOF)
			_EOF(pointer);
	}

	return (0);
}
