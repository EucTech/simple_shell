#include "main.h"

/**
 * _itoa - This is a function that converts integer to a char
 * @n: This is the number to convert to char
 * Return: a pointer to char
 */

char *_itoa(int n)
{
	char *ptr;
	unsigned int c;
	int count = count_num(n);

	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (NULL);

	ptr[count] = '\0';

	if (n < 0)
	{
		c = n * -1;
		ptr[0] = '-';
	}
	else
		c = n;

	count--;
	do {
		ptr[count] = (c % 10) + '0';
		c /= 10;
		count--;
	} while (c > 0);

	return (ptr);
}


/**
 * count_num - This is a function that gets the length of a integer
 * @n: This is the integer to count
 * Return: int
 */

int count_num(int n)
{
	unsigned int c;
	int count = 1;

	if (n < 0)
	{
		count++;
		c = n * -1;
	}
	else
		c = n;
	while (c > 9)
	{
		count++;
		c /= 10;
	}

	return (count);
}


/**
 * _strncmp - This is a function that compares two strings
 * @s1: This is the destination
 * @s2: This is the source
 * @n: This is how many numbers to compare
 * Return: string
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t k;

	if (s1 == NULL)
	{
		return (-1);
	}
	for (k = 0; k < n && s2[k]; k++)
	{
		if (s1[k] != s2[k])
			return (1);
	}

	return (0);
}

/**
 * _strcmp - This is a function that compares two strings
 * @s1: This is the first
 * @s2: second string
 * Return: 0 Always
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}


/**
 * _strcpy - This is a function that copies a strings
 * @dest: This is the destination
 * @src: This is the source to copy to
 * Return: DESTINATION
 */
char *_strcpy(char *dest, char *src)
{
	int k;

	k = 0;
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}

	dest[k] = '\0';
	return (dest);
}
