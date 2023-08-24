#include <stdlib.h>
#include "monty.h"

/**
 * swap - function that swaps the two top elements in a stack
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int i = 1, temp;

	if (*stack == NULL)
		i = 0;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
