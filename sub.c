#include <stdlib.h>
#include "monty.h"

/**
 * sub - function that subtracts the values or the two top nodes
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int i = 1;

	if (*stack == NULL)
		i = 0;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	(*stack) = (*stack)->next;
	free(ptr);
	ptr = NULL;
}
