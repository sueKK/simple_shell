#include "shell.h"

/**
 * execute - This function handles execution of
 * commands using the exec functions
 *
 * @command: The array of commands to be executed
 * @av: these are the arguments passed to the function
 *
 * Return: returns status of command execution
 */
int execute(char **command, char **av)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(av[0]);
			free_command(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free_command(command);
	}
	return (WEXITSTATUS(status));
}
