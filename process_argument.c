#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * process_argument - this is responsible for processing the user commands
 *
 * @av: arguments from the terminal
 * @lineptr: this is the tokenized user input
 *
 * Return: 0 if everything goes well and -1 if otherwise
 */

int process_argument(char **av, char *lineptr)
{
	int wstatus;
	pid_t pid;
	/* char *trimmed_str = trim_spaces(lineptr); */

	char **args = word_list(lineptr, " \t\n");

	if (args == NULL)
		return (0);

	pid = fork();
	if (pid == -1)
	{
		perror("Error: ");
		return (-1);
	}

	if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror(av[0]);
		exit(EXIT_FAILURE);
	} else
	{
		wait(&wstatus);
	}

	free(args);

	return (0);
}
