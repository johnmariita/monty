#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "monty.h"

void read_file(FILE *file)
{
	char *line = NULL;
	size_t size = 0;
	char **command = malloc(sizeof(char *));

	while (getline(&line, &size, file) != -1)
	{
		command[1] = strtok(line, "\n ");
		command[2] = strtok(NULL, "\n ");
		if (command[1] == NULL)
			continue;
		printf("%s", command[1]);
	}
}
