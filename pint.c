#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

/**
 * pint - function that prints the top integer of a stack
 * @stack: pointer to the stack
 * @line_number: the line we're on currently
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
