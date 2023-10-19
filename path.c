#include "shell.h"

/**
 * get_path - this function gets the path of the command and
 * tokenizes it
 *
 * @command: this is the input command received by the function
 *
 * Return: this returns the path
 */
char *get_path(char *command)
{
	char *_path, *_cmd, *directory;
	int i;
	struct stat st;

	i = 0;
	while (command[i])
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
		i++;
	}
	_path = _getenv("PATH");
	if (!_path)
		return (NULL);
	directory = strtok(_path, ";");
	while (directory)
	{
		_cmd = malloc(_strlen(directory) + _strlen(command) + 2);
		if (_cmd)
		{
			_strcpy(_cmd, directory);
			_strcat(_cmd, "/");
			_strcat(_cmd, command);
			if (stat(_cmd, &st) == 0)
			{
				free(_path);
				return (_cmd);
			}
			free(_cmd), _cmd = NULL;
			directory = strtok(NULL, ":");
		}
	}
	free(_path);
	return (NULL);
}
