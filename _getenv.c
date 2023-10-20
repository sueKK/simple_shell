#include "shell.h"

/**
 * _setenv - this is a custom implementation of the setenv function
 * @name: the name of the command
 * @value: the value of the command
 * @overwrite: the integer handling iteration
 *
 * Return: Always 0.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, len = 0;
	char *new_var;

	if (!name || !value)
		return (-1);
	while (environ[i])
	{
		len = _strlen(name);
		if (_strncmp(environ[i], name, len) == 0)
		{
			if (overwrite)
			{
				new_var = malloc(_strlen(name) + _strlen(value) + 2);
				_strcpy(new_var, name);
				_strcat(new_var, "=");
				_strcat(new_var,  value);
				environ[i] = new_var;
				return (0);
			}
			return (0);
		}
		i++;
	}
	new_var = malloc(_strlen(name) + _strlen(value) + 2);
	_strcpy(new_var, name);
	_strcat(new_var, "=");
	_strcat(new_var,  value);
	environ[i] = new_var;
	environ[i + 1] = NULL;
	return (0);
}

/**
 * _getenv - this function retrieves the environment variable.
 *
 * @var: this is the environment variable.
 *
 * Return: the environment PATH value
 */
char *_getenv(char *var)
{
	char *temp, *key, *val, *env;
	int i;

	i = 0;
	while (environ[i])
	{
		temp = _strdup(environ[i]);
		key = strtok(temp, "=");
		if (_strcmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(temp);
			return (env);
		}
		free(temp), temp = NULL;
		i++;
	}
	return (NULL);
}
