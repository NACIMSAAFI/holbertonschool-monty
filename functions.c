#include "monty.h"

/**
 * push - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 */
void push(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (!new_node || !*new_node)
		return;

	if (!my_stack)
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
	if (!stack)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * print - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
