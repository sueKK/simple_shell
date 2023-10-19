#include "shell.h"

/**
 * main - Entry point of the program
 * @ac: Argument count
 * @av: Arguments in the command
 *
 * Description: This is a simple shell project implementation
 *
 * Return: Always returns 0.
 */
int main(int ac, char **av)
{
	char *input = NULL;
	char **command = NULL;
	int status = 0;
	(void) ac;

	while (1)
	{
		input = read_input();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write_string("\n");
			return (status);
		}
		command = tokenize_input(input);
		if (!command)
			continue;


		status = execute(command, av);
	}
}
