#include "shell.h"

/**
 * tokenize_input - this function breaks apart the user input into
 * separate command tokens
 * @input: the user input in form of commands
 *
 * Return: the command in token form
 */
char **tokenize_input(char *input)
{
	char *token = NULL;
	char *token_copy = NULL;
	char **command = NULL;
	int i = 0, token_count = 0;

	if (!input)
		return (NULL);
	token_copy = _strdup(input);
	token = strtok(token_copy, " \t\n");
	if (token == NULL)
	{
		free(input), input = NULL;
		free(token_copy), token_copy = NULL;
		return (NULL);
	}
	while (token)
	{
		token_count++;
		token = strtok(NULL, " \t\n");
	}
	free(token_copy), token_copy = NULL;

	command = malloc(sizeof(char *) * (token_count + 1));
	if (!command)
	{
		free(input), input = NULL;
		return (NULL);
	}

	token = strtok(input, " \t\n");
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	free(input), input = NULL;
	command[i] = NULL;
	return (command);
}
