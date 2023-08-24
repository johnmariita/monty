#include <stdio.h>
#include "monty.h"

/**
 * pall - function that prints the content of a stack / queue
 * @stack: pointer to the stack
 * @line_number: the line number int the monty file
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr = *stack;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
