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
	char *prompt = "#cisfun$ ";
	char *input = NULL;
	size_t input_size = 0;
	char *token;
	char **command;
	int i = 0;

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

		execute(command);
		i = 0;
		free(command);
	}
}
