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
	int line = 0;

	signal(SIGINT, sig_handle);
	while (1)
	{
		line++;
		if (isatty(STDIN_FILENO))
			prompt();
		g_line = _getline(&pointer, &n, stdin);
		if (g_line == EOF)
		{
			_EOF(pointer);
			continue;
		}
		if (g_line == -1)
		{
			free(pointer);
			return (EXIT_FAILURE);
		}
		cmd = token(pointer);
		if (_strcmp(cmd[0], "exit") == 0)
			my_exit(cmd, pointer, av, line);
		my_builtin(cmd);
		execute_com(cmd, pointer, line, av);
		free(cmd);
		free(pointer);
		pointer = NULL;
		n = 0;
	}
	return (0);
}
