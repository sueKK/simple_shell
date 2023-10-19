#include "shell.h"

/**
 * free_command - this function frees the command argumensts
 *
 * @array: the array of tokenized arguments
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

	index = get_index(idx);

	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, message, _strlen(message));

	free(index);
}

/**
 * get_index - the index of the command entered as input
 * @n: the counter of the index
 *
 * Return: the index of the command
 */
char *get_index(int n)
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
