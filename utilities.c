#include "shell.h"

/**
 * free_command - this function frees the command argumensts
 *
 * @array: the array of tokenized arguments.
 * Return: void
 */
void free_command(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array), array = NULL;
}

/**
 * error_message - this function prints and error message
 *
 * @shell_name: the name of the shell
 * @cmd: the command that has been entered
 * @idx: the index of the command entered
 *
 * Return: the error message
 *
 */
void error_message(char *shell_name, char *cmd, int idx)
{
	char *index, message[] = ": not found\n";

	index = int_to_char(idx);

	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, message, _strlen(message));

	free(index);
}

/**
 * int_to_char - the integer to be converted into a string or character
 * @n: the integer to be converted
 *
 * Return: the converted character or string
 */
char *int_to_char(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '0';
	reverse_str(buffer, i);

	return (_strdup(buffer));
}

/**
 * _positive - checks if an interger is positive
 *
 * @str: the integer string to be checked
 *
 * Return: 1 if interger is positive
 */
int _positive(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * char_to_int - converts a string into an integer
 *
 * @str: the string to be converted into an integer
 *
 * Return: the integer that has been converted
 */
int char_to_int(char *str)
{
	int i, num = 0;

	i = 0;
	while (str[i])
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
