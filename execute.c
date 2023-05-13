#include "main.h"
/**
 * execute_com - This is a function that executes command in a shell
 * @av: This is the argument given
 * @input: This is the input the user gives
 * @line: This is the command given
 * @cmd: This is the name of the programme
 * Return: 0
 */

int execute_com(char **av, char *input, int line, char **cmd)
{
	pid_t pid;
	int status;

	if (*av == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*av, "./", 2) != 0 && _strncmp(*av, "/", 1) != 0)
		{
			get_command(av);
		}

		if (execve(*av, av, environ) == -1)
		{
			not_found(av[0], line, cmd);
			free(input);
			free(av);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
