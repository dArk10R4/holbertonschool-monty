#include <stdio.h>
#include "monty.h"

/**
 * add_s - adds
 * @stack: stack
 */
void add_s(stack_t **stack)
{
	(*stack)->next->n += (*stack)->n;
	pop_s(stack);
}
/**
 * add_f - add function
 * @stack: stack
 * line_number: line number
 */
void add_f(stack_t **stack, unsigned int line_number)
{
	const char *format = "L%d: can't add, stack too short";

	if (*stack && (*stack)->next)
	{
		add_s(stack);
		return;
	}

	fprintf(stderr, format, line_number);
	ext(stack);
}
