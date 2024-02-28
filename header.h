#ifndef HEADER_H
#define HEADER_H

#include <stddef.h>

size_t tokenize(char *str, char *delim);
char **word_list(char *str, char *delim);
int process_argument(char **av, char *lineptr);

#endif
