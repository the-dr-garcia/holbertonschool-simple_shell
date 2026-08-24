#include "shell.h"

/**
 * execute_command - Forks and executes a command using execve
 * @cmd: The command path to execute
 * @argv: Argument vector from main
 *
 * Return: Nothing
 */
void execute_command(char *cmd, char **argv)
{
	pid_t pid;
	int status;
	char *exec_argv[2];

	exec_argv[0] = cmd;
	exec_argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("Error forking");
		return;
	}

	if (pid == 0)
	{
		if (execve(cmd, exec_argv, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], cmd);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
