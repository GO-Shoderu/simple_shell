#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main -       this is the entry point of this program
 *
 * Return:      returns 0 if everything goes well but returns 1 if otherwise
 */

int main(void)
{
	char *lineptr = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

	while ((nread = getline(&lineptr, &len, stdin)) != -1)
	{
		if (process_argument(lineptr) == -1)
			fprintf(stderr, "Error: Failed to process input\n");

		printf("$ ");
	}

	free(lineptr);

	return (0);
}
