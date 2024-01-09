#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value of the node
 * @prev: Pointer to the previous element of the stack (or queue)
 * @next: Pointer to the next element of the stack (or queue)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its associated function
 * @opcode: The opcode
 * @f: The function to perform the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *my_stack;

void my_getline(FILE *fd);
int tokenizer(char *buffer, int line_number, int format);
void find_function(char *opcode, char *value,
unsigned int line_number, int format);
void call_function(void (*f)(stack_t **, unsigned int),
char *op, char *val, int line, int format);
stack_t *create_node(int n);
void free_nodes(void);
void push(stack_t **new_node, __attribute__((unused)) unsigned int ln);
void pall(stack_t **stack, unsigned int line_number);
void print(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
