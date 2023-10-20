#include "shell.h"

/**
 * read_input - this function reads user input from the stdin stream.
 *
 * Description: this function reads user input and outputs in into the
 * entry point of the program.
 *
 * Return: the input of the user
 */
char *read_input(void)
{
	char *prompt = "#cisfun$ ";
	char *input = NULL;
	size_t input_size = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write_string(prompt);
	n = getline(&input, &input_size, stdin);
	if (n == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
