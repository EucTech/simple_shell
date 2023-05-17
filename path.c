#include "main.h"

/**
 * get_command_dir - gets a command's directory
 * @token: execuatable command
 * @dir: directory where commad is
 *
 * Return: full path of command or NULL
 */

char *get_command_dir(char *token, char *dir)
{
	size_t len;
	char *cmd;

	len = _strlen(dir) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, dir);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}


/**
 * get_command -  finds executable command in the path
 * @cmd: command inputted
 *
 * Return: 0 if success or 1 otherwise
 */

int get_command(char **cmd)
{
	struct stat buff;
	char *path, *v, *c_path;

	path = _getenv("PATH");
	v = _strtok(path, ":");
	while (v != NULL)
	{
		c_path = get_command_dir(*cmd, v);
		if (stat(c_path, &buff) == 0)
		{
			*cmd = _strdup(c_path);
			free(path);
			free(c_path);
			return (0);
		}
		free(c_path);
		v = _strtok(NULL, ":");
	}
	free(path);

	return (0);
}
