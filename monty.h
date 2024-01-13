#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void parser(FILE *fp);
void ext(stack_t **stack);
void push_f(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
#ifdef LINE
char *line = NULL;
#else
extern char *line;
#endif
extern instruction_t push;
extern instruction_t pall;
#ifdef FP
FILE *fp = NULL;
#else
extern FILE *fp;
#endif
#endif
