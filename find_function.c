#include "monty.h"

void call_function(void (*f)(stack_t **, unsigned int), char *opcode, char *value, unsigned int line_number)
{
    int i, int_value;

    if (strcmp("push", opcode) == 0)
    {
        if (value == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        for (i = 0; value[i] != '\0'; i++)
        {
            if (isdigit((unsigned char)value[i]) == 0 && (i == 0 && value[i] != '-'))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
        }

        int_value = atoi(value);
        f(&my_stack, int_value);
    }
    else if (value != NULL)
    {
        fprintf(stderr, "L%d: usage: %s without a valid argument\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
    else
    {
        f(&my_stack, line_number);
    }
}

void find_function(char *opcode, char *value, unsigned int line_number)
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
            call_function(f[i].f, opcode, value, line_number);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
