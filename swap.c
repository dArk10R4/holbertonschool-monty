#include <stdio.h>
#include "monty.h"

/**
 * swap_s - swaps
 * @stack: stack
 */
void swap_s(stack_t **stack)
{
	stack_t *temp = (*stack)->next;

	temp->n += (*stack)->n;
	(*stack)->n = temp->n - (*stack)->n;
	temp->n -= (*stack)->n;
}

/**
 * swap_f - swap function
 * @stack: stack
 * @line_number: line number
 */
void swap_f(stack_t **stack, unsigned int line_number)
{
	const char *format = "L%d: can't swap, stack too short\n";

	if (*stack && (*stack)->next)
	{
		swap_s(stack);
		return;
	}

	fprintf(stderr, format, line_number);
	ext(stack);
}
