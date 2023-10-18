#include "shell.h"

/**
 * _getenv - Custom implementation of getenv to retrieve
 * the value of an environment variable.
 * @name: The name of the environment variable.
 * @env: The environment variables.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(const char *name, char **env)
{
	size_t name_len = _strlen(name);

	char **var = env;

	for (; *var; var++)
	{
		if (_strlen(*var) >= name_len && _strncmp(*var, name, name_len) == 0)
		{
			if ((*var)[name_len] == '=')
			{
				char *value = (char *)malloc(_strlen(*var) - name_len);

				if (value == NULL)
					return (NULL);
				_strcpy(value, &(*var)[name_len + 1]);
				return (value);
			}
		}
	}
	return (NULL);
}

/**
 * get_environment_variables - Custom function to retrieve
 * the environment variables.
 *
 * Return: An array of environment variables or NULL if not available.
 */
char **get_environment_variables()
{
	char **environ = retrieve_environment_variables();
	int env_count;
	int i;
	char **env_copy;
	char **var;

	if (environ == NULL)
		return (NULL);
	env_count = 0;

	var = environ;

	for (; *var; var++)
		env_count++;

	env_copy = (char **)malloc(sizeof(char *) * (env_count + 1));

	if (env_copy == NULL)
	{
		free_environment_variables(environ);
		return (NULL);
	}
	i = 0;

	for (; i < env_count; i++)
	{
		env_copy[i] = _strdup(environ[i]);
		if (env_copy[i] == NULL)
		{
			free_environment_variables(environ);
			free_environment_variables(env_copy);
			return (NULL);
		}
	}
	env_copy[env_count] = NULL;
	free_environment_variables(environ);
	return (env_copy);
}

/**
 * retrieve_environment_variables - Custom function to retrieve
 * the environment variables.
 *
 * Return: An array of environment variables or NULL if not available.
 */
char **retrieve_environment_variables()
{
	char **environ;
	int env_count = 0;
	int i;
	char **var = environ;
	char **env_copy;

	for (; *var; var++)
		env_count++;

	env_copy = (char **)malloc(sizeof(char *) * (env_count + 1));

	if (env_copy == NULL)
		return (NULL);

	for (i = 0; i < env_count; i++)
	{
		env_copy[i] = _strdup(environ[i]);
		if (env_copy[i] == NULL)
		{
			free_environment_variables(env_copy);
			return (NULL);
		}
	}
	env_copy[env_count] = NULL;
	return (env_copy);
}

/**
 * free_environment_variables - Custom function to free memory
 * allocated for environment variables.
 * @env: The environment variable array to be freed.
 */
void free_environment_variables(char **env)
{
	char **var = env;

	for (; *var; var++)
		free(*var);
	free(env);
}

