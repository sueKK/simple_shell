#include "shell.h"

/**
 * write_string - Write a string to a file descriptor.
 * @fd: The file descriptor to write to.
 * @str: The string to be written.
 */
void write_string(int fd, const char *str)
{
	write(fd, str, _strlen(str));
}
