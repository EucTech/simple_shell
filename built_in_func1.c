#include "main.h"
/**
 * my_builtin - This is a function that checkes builtins
 * @cmd: This is a tokenized comands
 * @sta: This is the execute
 * Return: int value of -1
 */

int my_builtin(char **cmd, int sta)
{
	my_bit han_b[] = {

		{"env", print_env},
		{NULL, NULL}
	};

	int k = 0;

	while ((han_b + k)->exe)
	{
		if (_strcmp(cmd[0], (han_b + k)->exe) == 0)
		{
			return ((han_b + k)->check(cmd, sta));
		}
		k++;
	}
	return (-1);
}

/**
 * all_built_in - This is a function that will check builtin
 * @cmd: This is the command
 * Return: -1
 */

int all_built_in(char **cmd)
{
	my_bit check[] = {
		{"cd", NULL},
		{NULL, NULL},
	};

	int k = 0;

	if (*cmd == NULL)
		return (-1);

	while ((check + 1)->exe)
	{
		if (_strcmp(cmd[0], (check + k)->exe) == 0)
			return (0);
		k++;
	}
	return (-1);
}
