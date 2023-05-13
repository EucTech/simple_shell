#include "main.h"

/**
 * main - This is a function that takes command line arguments
 * and execute it
 * @ac: This is the number of the command line arguments
 * @av: This is the argument vectors
 * Return: 0
 */

int main(int ac __attribute__((unused)), char **av)
{
	ssize_t g_line;
	char *pointer = NULL, **cmd = NULL;
	size_t n = 0;
	int line = 0, k;

	signal(SIGINT, sig_handle);

	while (1)
	{
		line++;
		if (isatty(STDIN_FILENO))
			prompt();
		g_line = getline(&pointer, &n, stdin);

		if (g_line == EOF)
		{
			_EOF(pointer);
			continue;
		}
		else if (*pointer == '\n')
			free(pointer);
		if (g_line == -1)
		{
			free(pointer);
			return (EXIT_FAILURE);
		}
		cmd = token(pointer);
		execute_com(cmd, pointer, line, av);

		for (k = 0; cmd[k] != NULL; k++)
			free(cmd[k]);
		free(cmd);
		pointer = NULL, n = 0;
	}
	return (0);
}
