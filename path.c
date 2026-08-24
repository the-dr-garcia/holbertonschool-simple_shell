#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: Name of the environment variable
 *
 * Return: Pointer to the value string, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i, j;

	if (!name || !environ)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] && name[j]; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (environ[i][j] == '=' && name[j] == '\0')
			return (&(environ[i][j + 1]));
	}
	return (NULL);
}

/**
 * get_location - Locates the full path of a command
 * @command: The command name to find
 *
 * Return: Malloc'ed full path string, or NULL if not found / shouldn't fork
 */
char *get_location(char *command)
{
	char *path_env, *path_copy, *token, *file_path;
	int command_len, dir_len;
	struct stat st;

	if (!command)
		return (NULL);

	if (strchr(command, '/'))
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	path_env = _getenv("PATH");
	if (!path_env || path_env[0] == '\0')
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	command_len = strlen(command);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		if (token[0] == '\0')
		{
			if (stat(command, &st) == 0)
			{
				free(path_copy);
				return (strdup(command));
			}
			token = strtok(NULL, ":");
			continue;
		}

		dir_len = strlen(token);
		file_path = malloc(command_len + dir_len + 2);
		if (!file_path)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(file_path, token);
		strcat(file_path, "/");
		strcat(file_path, command);

		if (stat(file_path, &st) == 0)
		{
			free(path_copy);
			return (file_path);
		}

		free(file_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
