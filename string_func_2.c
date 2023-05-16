#include "main.h"

/**
 * _strlen - This is a funtion that returns the lenth of a string
 * @s: integer to get its lenth
 * Return: Always
 */
int _strlen(char *s)
{
	int i = 1, sum = 0;
	char d = s[0];

	while (d != '\0')
	{
		sum++;
		d = s[i++];
	}
	return (sum);
}

/**
 * _strdup -  This is a function that duplicate a string
 * @str: string to duplicate
 * Return: a pointer
 */

char *_strdup(char *str)
{
	char *strout;
	unsigned int i, j;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	strout = (char *)malloc(sizeof(char) * (i + 1));

	if (strout == NULL)
		return (NULL);

	for (j = 0; j <= i; j++)
		strout[j] = str[j];

	return (strout);
}

/**
 * _strcat - This a function that concat strings
 * @dest: This is the destinations
 * @src: This is the source
 * Return: char pointer
 */
char *_strcat(char *dest, char *src)
{
	char *n = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (n);
}


/**
 * _memset - This is a function that fills memory with a constant byte
 * @s: pointed destination
 * @b: constant byte
 * @n: number of bytes
 * Return: destination
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}

/**
 * _memcpy - This is a function that copies memory area
 * @dest: the destination
 * @src: source
 * @n: number of byte
 * Return: destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
