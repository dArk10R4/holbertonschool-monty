#include <stdio.h>
#include <ctype.h>
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
	new->prev = NULL;

	if (!(*stack))
	{
		*stack = new;
		return;
	}

	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

short int isNumber(const char *str) {
	if (*str == '\0')
		return 0;

	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0') {
		if (!isdigit(*str))
			return (0);
		str++;
    }

    return 1;
}

void push_f(stack_t **stack, unsigned int line_number)
{
	char *token;
	const char *format = "L%d: usage: push integer\n";
	const char s[3] = " \n\t";

	token = strtok(line, s);
	token = strtok(NULL, s);

	if (!token || !isNumber(token))
	{
		fprintf(stderr, format, line_number);
		ext(stack);
	}

	push_s(stack, atoi(token));
}

instruction_t push = {"push", push_f};
