#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pall_s - prints stack
 * @stack: stack
 */
void pall_s(stack_t **stack)
{
	stack_t *temp;

	temp = (*stack);

	while(temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}

void pall_f(stack_t **stack, unsigned int line_number)
{
	pall_s(stack);
}

instruction_t pall = {"pall", pall_f};
