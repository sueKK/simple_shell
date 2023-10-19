#include "shell.h"

/**
 * execute - This function handles execution of
 * commands using the exec functions
 * @command: The array of commands to be executed
 *
 * Description: This function handles execution of commands using the execve
 * system call using the specifies command path array and returns an exit
 * status
 */
void execute(char **command)
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
		if (execve(command[0], command, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
