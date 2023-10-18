#include "shell.h"

/**
 * handle_command_not_found - Handle a command not found error.
 * @command_and_args: The command that was not found.
 */
void handle_command_not_found(char *command_and_args)
{
	const char *error_message;

	error_message = "Command not found";
	write_string(STDERR_FILENO, error_message);
	write_string(STDERR_FILENO, command_and_args);
	write_string(STDERR_FILENO, "\n");
	exit(EXIT_FAILURE);
}

/**
 * execute_command - Execute the given command with arguments.
 * @command_and_args: An array of strings representing
 * the command and its arguments.
 */
void execute_command(char **command_and_args)
{
	char *token;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *path = getenv("PATH");
		char *path_copy = strdup(path);

		token = strtok(path_copy, ":");
		while (token != NULL)
		{
			char command_path[MAX_INPUT_SIZE];

			strcpy(command_path, token);
			strcat(command_path, "/");
			strcat(command_path, command_and_args[0]);
			if (access(command_path, X_OK) == 0)
			{
				char *envp[] = { NULL };

				execve(command_path, command_and_args, envp);
				perror("execve");
				handle_command_not_found(command_and_args[0]);
				exit(EXIT_FAILURE);
			}
			token = strtok(NULL, ":");
		}
		handle_command_not_found(command_and_args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * free_command_args - Free memory allocated for the command and arguments.
 * @command_and_args: An array of strings representing
 * the command and its arguments.
 */
void free_command_args(char **command_and_args)
{
	int i = 0;

	for (; command_and_args[i] != NULL; i++)
	{
		free(command_and_args[i]);
	}
	free(command_and_args);
}

/**
 * tokenize_input - Tokenize the user input.
 * @input: The user input.
 *
 * Return: An array of strings.
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *token;
	int token_count = 0;
	int i;

	token = strtok(input, " ");
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, " ");
	}

	if (token_count == 0)
	{
		return (NULL);
	}
	tokens = (char **)malloc((token_count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		return (NULL);
	}
	token = strtok(input, " ");

	i = 0;
	while (token != NULL)

	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
