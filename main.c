#include "shell.h"

/**
 * trim_whitespace - Removes trailing whitespace and newlines from a string
 * @str: The string to trim
 */
void trim_whitespace(char *str)
{
	int i = strlen(str) - 1;

	while (i >= 0 && (str[i] == '\n' || str[i] == '\r' || str[i] == ' ' || str[i] == '\t'))
	{
		str[i] = '\0';
		i--;
	}
}

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_chars;
	int interactive = isatty(STDIN_FILENO);
	(void)argc;

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, "($) ", 4);

		read_chars = getline(&line, &len, stdin);
		if (read_chars == -1)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			break;
		}

		trim_whitespace(line);

		if (strlen(line) == 0)
			continue;

		if (strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}

		execute_command(line, argv);
	}

	return (0);
}
