#include "shell.h"

/**
 * reverse_str - this function reverses a string
 *
 * @str: the string to be reversed
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
