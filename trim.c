#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char trim_spaces(char str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ')
			return (&str[i]);
		i++;
	}
}
