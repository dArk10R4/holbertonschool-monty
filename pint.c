#include <stdio.h>
#include "monty.h"

/**
 * pint_f - pint function
 * @stack: stack
 * @line_number: line number
 */
void pint_f(stack_t **stack, unsigned int line_number)
{
	const char *format = "L%d: can't pint, stack empty";

	if (!*stack)
	{
		fprintf(stderr, format, line_number);
		ext(stack);
	}

	printf("%d\n", (*stack)->n);
}
