#include "shell.h"

/**
 * write_string - Write a string to a file descriptor.
 * @str: The string to be written.
 */
void write_string(const char *str)
{
	write(1, str, _strlen(str));
}
