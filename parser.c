#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

char *line;
/**
 * call_ins - calls instruction
 * @token: instruction
 * @linenum: line number
 */
void call_ins(char *token, int linenum, stack_t **stack)
{
	instruction_t instructions[] = {push, pall};
	int len_i = sizeof(instructions) / sizeof(instruction_t);
	short int is_ins = 0;
	int i = 0;

	for (i = 0; i < len_i; i++)
	{
		if (strcmp(instructions[i].opcode, token) == 0)
		{
			instructions[i].f(stack, linenum);
			is_ins = 1;
			break;
		}
	}

	if (!is_ins)
	{
		fprintf(stderr, "L%d: unknown\
 instruction %s\n", linenum, token);
		ext(stack);
	}

}

/**
 * parser - parser
 * @fb: file
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
			continue;

		call_ins(token, linenum, &stack);
		free(str);
		linenum++;
	}

	if (line)
		free(line);

	free_stack(&stack);
}
