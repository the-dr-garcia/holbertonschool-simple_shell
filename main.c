#include "shell.h"

/**
 * trim_whitespace - Removes leading and trailing whitespace and newlines
 * @str: The string to trim
 *
 * Return: Pointer to the trimmed string
 */
char *trim_whitespace(char *str)
{
	char *end;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		str++;

	if (*str == 0)
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r'))
	{
		*end = '\0';
		end--;
	}

	return (str);
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
	char *clean_line = NULL;
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

		clean_line = trim_whitespace(line);

		if (strlen(clean_line) == 0)
			continue;

		if (strcmp(clean_line, "exit") == 0)
		{
			free(line);
			break;
		}

		execute_command(clean_line, argv);
	}

	return (0);
}
