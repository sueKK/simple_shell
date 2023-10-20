#include "shell.h"

/**
 * execute - This function handles execution of
 * commands using the exec functions
 *
 * @command: The array of commands to be executed
 * @av: these are the arguments passed to the function
 * @idx: the index of the input command
 *
 * Return: returns status of command execution
 */
int execute(char **command, char **av, int idx)
{
	char *_cmd;
	int status;
	pid_t child_pid;

	_cmd = get_path(command[0]);
	if (!_cmd)
	{
		error_message(av[0], command[0], idx);
		free_command(command);
		return (127);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(_cmd, command, environ) == -1)
		{
			free_command(command);
			free(_cmd), _cmd = NULL;
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free_command(command);
		free(_cmd), _cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
