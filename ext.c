#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * free_stack
 * @stack: stack
 */
void free_stack(stack_t **stack)
{
	stack_t *temp, *temp2;
	temp = (*stack);

	while(temp)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
}

/**
 * ext - frees and exit
 * stack - stack
 * message - message
 */
void ext(stack_t **stack)
{
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
