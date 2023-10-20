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
	int status = 0, idx = 0;
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

		idx++;
		command = tokenize_input(input);
		if (!command)
			continue;
		if (_builtin(command[0]))
			handle_builtins(command, av, &status, idx);
		else
			status = execute(command, av, idx);
	}
}
