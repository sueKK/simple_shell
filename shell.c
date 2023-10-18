#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Description: This is a simple shell project implementation
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *prompt = "($) ";
	char **command_and_args;

	while (1)
	{
		write_string(STDOUT_FILENO, prompt);

		if (fgets(input, _strlen(input), stdin) == NULL)
		{
			write_string(STDOUT_FILENO, "\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
		input[_strlen(input) - 1] = '\0';
		command_and_args = tokenize_input(input);

		if (command_and_args != NULL)
		{
			execute_command(command_and_args);
			free_command_args(command_and_args);
		}
	}
	return (0);
}
