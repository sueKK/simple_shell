#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Description: This is a simple shell project implementation
 * with minimal functionality.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *prompt = "($) ";
	char **command_and_args;
	char *new_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";

	if (setenv("PATH", new_path, 1) == -1)
	{
		perror("setenv");
		return (1);
	}

	while (1)
	{
		write_string(STDOUT_FILENO, prompt);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			write_string(STDOUT_FILENO, "\n");
			break;
		}
		input[_strlen(input) - 1] = '\0';

		if (_strlen(input) == 0)
		{
			continue;
		}
		command_and_args = tokenize_input(input);

		if (command_and_args != NULL)
		{
			execute_command(command_and_args);
			free_command_args(command_and_args);
		}
	}
	return (0);
}
