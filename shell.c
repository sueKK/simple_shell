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
	size_t input_size = 0;
	char *prompt = "#cisfun$ ";
	char *input = NULL;
	char *token;
	char **command;
	int status, i = 0;
	pid_t child_pid;

	while (1)
	{
		write_string(prompt);
		getline(&input, &input_size, stdin);
		token = strtok(input, "\t\n");
		command = malloc(sizeof(char *) * 1024);

		while (token)
		{
			command[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
		}
		command[i] = '\0';

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(command[0], command, NULL) == -1)
				perror("Error executing command");
		}
		else
		{
			wait(&status);
		}
		i = 0;
		free(command);
	}
}
