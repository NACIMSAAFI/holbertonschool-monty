#include "monty.h"

/**
 * call_function - Calls the appropriate function based on the opcode
 * @f: Function pointer
 * @op: Opcode
 * @val: Value (unused)
 * @line: Line number
 * @format: Format flag
 */
void call_function(void (*f)(stack_t **, unsigned int),
char *op, char *val, int line, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			fprintf(stderr, "L%d: usage: push integer\n", line);
		EXIT_FAILURE;
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				fprintf(stderr, "L%d: usage: push integer\n", line);
			EXIT_FAILURE;
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			f(&node, line);
	}
	else
		f(&my_stack, line);
}

/**
 * find_function - Finds and calls the function corresponding to the opcode
 * @opcode: Opcode
 * @value: Value (unused)
 * @line_number: Line number
 * @format: Format flag
 */
void find_function(char *opcode, char *value,
unsigned int line_number, int format)
{
	instruction_t f[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", print},
		{NULL, NULL}};

	int i;

	for (i = 0; f[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, f[i].opcode) == 0)
		{
			call_function(f[i].f, opcode, value, line_number, format);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
