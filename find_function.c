#include "monty.h"
#include <string.h>

void call_function(void (*f)(stack_t **, unsigned int), char *toke, char *value, unsigned int line_number)
{
    if (strcmp("push", toke) == 0)
    {
        if (value == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        int int_value = atoi(value);
        f(&my_stack, int_value);
    }
    else
    {
        f(&my_stack, line_number);
    }
}

void find_function(char *toke, char *value, unsigned int line_number)
{
    instruction_t f[] = {
        {"push", &push},
        {"pall", &pall},
        {"pint", print_top},
        {NULL, NULL}};

    int i;
    for (i = 0; f[i].opcode != NULL; i++)
    {
        if (strcmp(toke, f[i].opcode) == 0)
        {
            call_function(f[i].f, toke, value, line_number);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, toke);
    exit(EXIT_FAILURE);
}
