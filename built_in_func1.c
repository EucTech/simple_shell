#include "main.h"
/**
 * my_builtin - This is a function that checkes builtins
 * @cmd: This is a tokenized comands
 * Return: int value of -1
 */

int my_builtin(char **cmd)
{
	if (*cmd == NULL)
		return (-1);
	if (_strcmp(cmd[0], "env") == 0)
		print_env();

	if (_strcmp(cmd[0], "cd") == 0)
		change_dir(cmd);
	/*if (_strcmp(cmd[0], "setenv") == 0)*/
		/*_setenv(cmd[1], cmd[2], 1);*/
	/*if (_strcmp(cmd[0], "unsetenv") == 0)*/
		/*_unsetenv(cmd[1], cmd[2], 1);*/
	return (0);
}

/**
 * change_dir - This is a function that changes directorys
 * @cmd: This is the command
 * Return: 0
 */

int change_dir(char **cmd)
{
	char chan[PATH_MAX];
	char *print = _getenv("PWD");
	int count = _strlen(print);

	if (cmd[1] == NULL)
		chdir(_getenv("HOME"));

	if (!_strcmp(cmd[1], "~"))
		chdir(_getenv("HOME"));
	if (_strcmp(cmd[1], "-") == 0)
	{
		chdir(_getenv("OLDPWD"));
		write(STDOUT_FILENO, print, count);
		write(STDOUT_FILENO, "\n", 1);
	}

	if (chdir(cmd[1]) != 0)
	{
		/*perror("chdir");*/
		return (-1);
	}

	if (getcwd(chan, sizeof(cmd)) != NULL)
	{
		/*setenv("OLDPWD", print, 1);*/
		/*setenv("PWD", chan, 1);*/
	}
	return (0);
}

