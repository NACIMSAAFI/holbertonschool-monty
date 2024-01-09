#include "monty.h"

/**
 * my_getline - Reads lines from a file and processes them
 * @fd: File pointer
 */
void my_getline(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = tokenizer(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * tokenizer - Tokenizes the input lines
 * @buffer: Input line
 * @line_number: Line number
 * @format: Format flag
 * Return: Format flag
 */
int tokenizer(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "$\n ";
	int i = 0;

	if (!buffer)
	{
		perror("Error: malloc failed");
		return (EXIT_FAILURE);
	}

	while (isspace((unsigned char)buffer[i]))
	{
		i++;
	}

	opcode = strtok(buffer + i, delim);
	if (!opcode)
		return (format);

	value = strtok(NULL, delim);
	find_function(opcode, value, line_number, format);
	return (format);
}
