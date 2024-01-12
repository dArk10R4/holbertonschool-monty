#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void push_s(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		ext(stack);
	}
	new->n = n;

	if (!(*stack))
	{
		*stack = new;
		return;
	}

	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
 }

void push_f(stack_t **stack, unsigned int line_number)
{
	char *token;
	const char *format = "L%d: usage: push integer\n";
	const char s[1] = " ";

	token = strtok(line, s);
	token = strtok(NULL, s);


	if (!token)
	{
		fprintf(stderr, format, line_number);
		ext(stack);
	}

	push_s(stack, atoi(token));
}

instruction_t push = {"push", push_f};
