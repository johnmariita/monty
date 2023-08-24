#include <stdlib.h>
#include "monty.h"

/**
 * pop - function that removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(ptr);
	ptr = NULL;
}
