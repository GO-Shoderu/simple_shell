#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char *trim_spaces(const char *str)
{
	int start = 0;
	int end = 0;
	int trimmed_length = 0;
	char *trimmed_str;
	int i;

	while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n'))
	{
		start++;
	}

	end = start;
	while (str[end] != '\0')
	{
		end++;
	}
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t' || str[end - 1] == '\n'))
	{
		end--;
	}

	trimmed_length = end - start;

	trimmed_str = malloc(trimmed_length + 1);
	if (trimmed_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < trimmed_length; i++)
	{
		trimmed_str[i] = str[start + i];
	}
	trimmed_str[trimmed_length] = '\0';

	return (trimmed_str);
}
