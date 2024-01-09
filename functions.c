#include "monty.h"

/**
 * push - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void push(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (my_stack == NULL)
	{
		my_stack = *new_node;
		return;
	}
	tmp = my_stack;
	my_stack = *new_node;
	my_stack->next = tmp;
	tmp->prev = my_stack;
}

/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * print - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	EXIT_FAILURE;
	printf("%d\n", (*stack)->n);
}
