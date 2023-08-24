#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "monty.h"

glob glo_vars;
/**
 * read_file - function that reads the content of the file
 * @file: the file to be open
 * @stack: pointer to the stack
 */
void read_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t size = 0, l_number = 1;
	int i = 0;
	char **command = malloc(sizeof(char *) * 3);
	instruction_t ops[] = {{"push", push}, {"pint", pint},
				{"pop", pop}, {"pall", pall},
				{"nop", nop}, {NULL, NULL}
	};

	while (custom_getline(&line, &size, file) != -1)
	{
		command[1] = strtok(line, "\t\n ");
		command[2] = strtok(NULL, "\t\n ");
		if (command[1] == NULL)
			continue;
		if (command[2])
		{
			glo_vars.value = atoi(command[2]);
			if (glo_vars.value == 0 && command[2][0] != '0')
			{
				free(line);
				free_stack(stack);
				free(command);
				fprintf(stderr, "L%ld: usage: push integer\n", l_number);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
		for (i = 0; ops[i].opcode; i++)
		{
			if (strcmp(command[1], ops[i].opcode) == 0)
			{
				ops[i].f(stack, l_number);
				break;
			}
		}
		if (ops[i].opcode == NULL)
		{
			free(line);
			free_stack(stack);
			fclose(file);
			fprintf(stderr, "L%ld: unknown instruction %s\n", l_number, command[1]);
			exit(EXIT_SUCCESS);
		}
		l_number++;

	}
	free(line);
	free(command);
}
