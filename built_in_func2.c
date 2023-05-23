#include "main.h"

/**
 * my_exit - This is a function that exit a program
 * @cmd: This is a tokenized command
 * @pointer: This is a pointer to the input
 * @av: This is argment vector
 * @line: This is incremented to get the length
 * Return: Nothing
 */

void my_exit(char **cmd, char *pointer, char **av, int line)
{
	int i = 0;
	int statue;

	if (cmd[1] == NULL)
	{
		free(pointer);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			print_er(av, line, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(pointer);
			free(cmd);
			exit(statue);
		}
	}
}

/**
 * print_er - This is a function that print error message
 * @av: This is the argument
 * @line: This is to get the length
 * @cmd: This is the given command
 * Return: Nothing
 */

void print_er(char **av, int line, char **cmd)
{
	char *num = _itoa(line);

	PRINT(av[0]);
	PRINT(": ");
	PRINT(num);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Invalid number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(num);
}

/**
 * _atoi - This is a function that converts to digit
 * @s: This is the string to convert
 * Return: digit
 */

int _atoi(char *s)
{
	int num_sign = 1;
	unsigned int digit = 0;

	do {
	if (*s == '-')
	{
		num_sign *= -1;
	}
	else if (*s >= '0' && *s <= '9')
	{
		digit = (digit * 10) + (*s - '0');
	}
	else if (digit > 0)
	{
		break;
	}
	} while (*s++);
	return (digit * num_sign);
}


/**
 * _isalpha - This is a function that print lowcase or uppercase
 * @c: The int for lowcase or uppercase
 * Return: Always
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
		return (0);
}
