#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main -       this is the entry point of this program
 * @ac:		argument counts
 * @av:		arguments
 *
 * Return:      returns 0 if everything goes well but returns 1 if otherwise
 */

int main(int ac, char **av)
{
	char *lineptr = NULL;
	size_t len = 0;
	ssize_t nread;
	(void) ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		nread = getline(&lineptr, &len, stdin);

		if (nread == -1)
			break;

		if (process_argument(av, lineptr) == -1)
			fprintf(stderr, "Error: Failed to process input\n");
	}

	free(lineptr);

	return (0);
}
