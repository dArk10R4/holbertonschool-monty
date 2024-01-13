#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LINE
#include "monty.h"


/**
 * call_ins - calls instruction
 * @token: instruction
 * @linenum: line number
 * @stack: stack
 * @str: str
 */
void call_ins(char *token, int linenum, stack_t **stack, char **str)
{
	instruction_t instructions[] = {
		{ "push", push_f },
		{ "pall", pall_f },
		{ "pint", pint_f },
		{ "pop", pop_f },
		{ "swap", swap_f },
		{ "add", add_f }
	};
	int len_i = sizeof(instructions) / sizeof(instruction_t);
	short int is_ins = 0;
	int i = 0;
	const char *format = "L%d: unknown instruction %s\n";

	for (i = 0; i < len_i; i++)
	{
		if (strcmp(instructions[i].opcode, token) == 0)
		{
			free(*str);
			instructions[i].f(stack, linenum);
			is_ins = 1;
			break;
		}
	}
	if (!is_ins)
	{
		fprintf(stderr, format, linenum, token);
		if (*str != NULL)
			free(*str);
		ext(stack);
	}

}

/**
 * parser - parser
 * @fp: file
 */
void parser(FILE *fp)
{
	int linenum = 1;
	size_t len = 0;
	ssize_t read;
	char *token;
	stack_t *stack = NULL;
	char *str;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		str = strdup(line);
		if (!str)
		{
			fprintf(stderr, "Error: malloc failed\n");
			ext(&stack);
		}

		token = strtok(str, " \n\t");
		if (!token)
		{
			linenum++;
			free(str);
			continue;
		}

		call_ins(token, linenum, &stack, &str);
		linenum++;
	}

	if (line)
		free(line);

	free_stack(&stack);
}
