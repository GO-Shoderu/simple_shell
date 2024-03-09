#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* tokenize - Function tokenizes a string based on delimter
* @str: String to tokenize
* @delim: Delimiter to use
*
* Return: Returns number of words found in the string
*/

size_t tokenize(char *str, char *delim)
{
	size_t words_count = 0;

	if (strtok(str, delim))
	{
		++words_count;
	}

	while (strtok(NULL, delim))
	{
		++words_count;
	}

	return (words_count);
}

/**
* word_list - Function makes an array of words based on passed string
* @str: String to prepare an array from
* @delim: Delimiter that determines end of words
*
* Return: Pointer of an array of words (strings), NULL if allocation fai
*/

char **word_list(char *str, char *delim)
{
	char **arr = NULL;
	size_t arr_iter = 0;
	size_t arr_size = 0;
	size_t str_size = strlen(str);
	char prev_char = '\0';
	size_t str_iter;

	arr_size = tokenize(str, delim);

	if (arr_size > 0)
	{
		arr = malloc(sizeof(char *) * (arr_size + 1));

		for (str_iter = 0; str_iter < str_size; ++str_iter)
		{
			if (arr_iter > (arr_size - 1))
				break;


			if (str[str_iter] != '\0' && prev_char == '\0')
			{
				arr[arr_iter] = str + str_iter;
				++arr_iter;
			}

			prev_char = str[str_iter];
		}

		arr[arr_iter] = NULL;
	}

	return (arr);
}
