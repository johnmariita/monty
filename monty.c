#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

/**
 * main - the main function
 * @argc: the argument count
 * @argv: the argument vector
 * Return: returns 0 on completion
 */
int main(int argc, char **argv)
{
	FILE *fp = NULL;
	stack_t *stack = NULL, *ptr = stack;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fp, &stack);
	fclose(fp);
	while (stack != NULL)
	{
		ptr = stack;
		stack = stack->next;
		free(ptr);
	}
	return (0);
}
