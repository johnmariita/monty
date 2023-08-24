#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

/**
 * push - function that inserts a node to the head of the stack
 * @stack: pointer to the stack
 * @line: the line number
 */
void push(stack_t **stack, unsigned int line)
{
	stack_t *newnode;

	line++;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	newnode->prev = NULL;
	newnode->n = glo_vars.value;
	if (*stack)
		(*stack)->prev = newnode;
	newnode->next = *stack;
	*stack = newnode;
}
