#include "shell.h"

/**
 * execute_command - Forks and executes a command with arguments using execve
 * @args: Array of arguments (tokens)
 * @argv: Argument vector from main (for program name in errors)
 *
 * Return: Exit status of the command
 */
int execute_command(char **args, char **argv)
{
	pid_t pid;
	int status = 0;
	char *full_path;

	if (args == NULL || args[0] == NULL)
		return (0);

	full_path = get_location(args[0]);
	if (full_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error forking");
		free(full_path);
		return (1);
	}

	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			free(full_path);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	free(full_path);
	return (status);
}
