#include "monty.h"

stack_t *my_stack;

/**
 * main - Main function to start the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Error: Can't open file");
		exit(EXIT_FAILURE);
	}

	my_getline(file);
	fclose(file);

	free_nodes();

	return (EXIT_SUCCESS);
}

/**
 * create_node - Creates a new node for the stack
 * @n: Integer value of the new node
 * Return: Pointer to the new node
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (!my_stack)
		return;

	while (my_stack)
	{
		tmp = my_stack;
		my_stack = my_stack->next;
		free(tmp);
	}
}
