#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * trim_spaces - removes leading spaces
 *
 * @str: recieves a string;
 *
 * Return: it returns a string
 */

char *trim_spaces(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ')
			return (&str[i]);
		i++;
	}

	return (NULL);
}
