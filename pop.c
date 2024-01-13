#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop_s - pop from stack
 * @stack: stack
 */
void pop_s(stack_t **stack)
{
	stack_t *temp;

	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return;
	}

	temp = (*stack)->next;
	temp->prev = NULL;
	free(*stack);
	*stack = temp;
}

/**
 * pop_f - pop function
 * @stack: stack
 * @line_number: line number
 */
void pop_f(stack_t **stack, unsigned int line_number)
{
	const char *format = "L%d: can't pop an empty stack\n";

	if (!*stack)
	{
		fprintf(stderr, format, line_number);
		ext(stack);
	}

	pop_s(stack);
}
