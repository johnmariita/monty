#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - function that frees a stack
 * @stack: pointer to the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *ptr = *stack;

	while (*stack)
	{
		ptr = (*stack);
		*stack = (*stack)->next;
		free(ptr);
	}
}
