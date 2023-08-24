#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * custom_getline - function that works as the getline func
 * @lineptr: pointer where the line will be stored
 * @n: the size to be allocated
 * @stream: stream to be read
 * Return: returns the characters read
 */
int custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t i = 0;
	char *temp;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			temp = (char *)_realloc(*lineptr, *n);
			if (temp == NULL)
				return (-1);
			*lineptr = temp;
		}
		(*lineptr)[i++] = c;
		if (c == '\n')
			break;
	}
	(*lineptr)[i] = '\0';
	if (i == 0 && c == EOF)
		return (-1);
	return (i);
}
