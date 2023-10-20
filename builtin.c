#include "shell.h"

/**
 * _builtin - this function identifies built in commands.
 *
 * @command: the command to be identified.
 *
 * Return: Always 0
 */
int _builtin(char *command)
{
	char *builtin[] = {
		"exit", "env", "setenv",
		"cd", NULL
	};
	int i;

	i = 0;
	while (builtin[i])
	{
		if (_strcmp(command, builtin[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * handle_builtins - this function handles the builtin commands
 *
 * @command: the command to be handled
 * @av: the list of arguments in the command
 * @status: the status of the shell
 * @idx: the index of the command input
 *
 * Return: void
 */
void handle_builtins(char **command, char **av, int *status, int idx)
{
	if (_strcmp(command[0], "exit") == 0)
		X_shell(command, av, status, idx);

	else if (_strcmp(command[0], "env") == 0)
		write_env(command, status);
}

/**
 * X_shell - this function exits the shell with the exit command
 *
 * @command: the user input to be iterated
 * @av: the arguments passed to the command
 * @status: the exit status of the shell
 * @idx: the index of the command iteration of the shell
 *
 * Return: void
 */
void X_shell(char **command, char **av, int *status, int idx)
{
	int exit_val = (*status);
	char *index, message[] = ": exit: Wrong number: ";

	if (command[1])
	{
		if (_positive(command[1]))
		{
			exit_val = char_to_int(command[1]);
		}
		else
		{
			index = int_to_char(idx);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, message, _strlen(message));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free_command(command);
			(*status) = 2;
			return;
		}
	}
	free_command(command);
	exit(exit_val);
}

/**
 * write_env - this function writes the command into the stdin
 *
 * @command: the command to be printed
 * @status: the status of the shell
 *
 * Return: void
 */
void write_env(char **command, int *status)
{
	int i;

	i = 0;
	while (environ[i])
	{
		write_string(environ[i]);
		write_string("\n");
		i++;
	}
	free_command(command);
	(*status) = 0;
}
