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
