#include "main.h"

/**
 * prompt - This is a function that displays the prompt in a shell
 * Return: Nothing
 */

void prompt(void)
{
	char *prompt = "UK~$ ";

	write(STDIN_FILENO, prompt, 5);
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

	free(buff);
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
