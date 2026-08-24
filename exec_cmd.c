#include "shell.h"

/**
 * execute_command - Forks and executes a command with arguments using execve
 * @args: Array of arguments (tokens)
 * @argv: Argument vector from main (for program name in errors)
 *
 * Return: Nothing
 */
void execute_command(char **args, char **argv)
{
	pid_t pid;
	int status;

	if (args == NULL || args[0] == NULL)
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("Error forking");
		return;
	}

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
