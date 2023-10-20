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
	(void) av;
	(void) idx;
	if (_strcmp(command[0], "exit") == 0)
		X_shell(command, status);

	else if (_strcmp(command[0], "env") == 0)
		write_env(command, status);
}

/**
 * X_shell - this function exits the shell with the exit command
 *
 * @command: the user input to be iterated
 * @status: the exit status of the shell
 *
 * Return: void
 */
void X_shell(char **command, int *status)
{
	free_command(command);
	exit(*status);
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
