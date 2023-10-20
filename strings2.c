#include "shell.h"

/**
 * reverse_str - this function reverses a string.
 *
 * @str: the string to be reversed.
 * @length: the length of the strign to be reversed
 *
 * Return: the reversed string
 */
void reverse_str(char *str, int length)
{
	char tmp;
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * write_string - Write a string to a file descriptor.
 * @str: The string to be written.
 */
void write_string(const char *str)
{
	write(1, str, _strlen(str));
}

/**
 * _strncmp - Compare the first n characters of two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal, a value less than 0 if s1 is less than s2,
 * or a value greater than 0 if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
	{
		return 0;
	}
	while (n-- && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
