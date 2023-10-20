# include "shell.h"

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
