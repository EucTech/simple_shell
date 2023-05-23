#include "main.h"

/**
 * prompt - This is a function that displays the prompt in a shell
 * Return: Nothing
 */

void prompt(void)
{
	char *prompt = "UK~$ ";

	write(STDOUT_FILENO, prompt, 5);
}


/**
 * _EOF - THis function checks end of file
 * @buff: This is a pointer to the text file
 * Return: No Return
 */

void _EOF(char *buff)
{
	if (buff)
	{
		free(buff);
		buff = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);

	/*free(buff);*/
	exit(EXIT_SUCCESS);
}


/**
 * sig_handle - This is a function that handle signal like control C
 * @sig: This is the kind of signal to handle
 * Return: Nothing
 */

void sig_handle(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nUK~$ ", 6);
}

/**
 * not_found - This is a function that print not found when unknown
 * command is given
 * @input: This the input given
 * @line: This the line
 * @cmd: This is a pointer to the
 * Return: NOTHING
 */
void not_found(char *input, int line, char **cmd)
{
	char *num;

	PRINT(cmd[0]);
	PRINT(": ");
	num = _itoa(line);
	PRINT(num);
	free(num);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

