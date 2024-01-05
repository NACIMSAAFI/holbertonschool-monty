#include "monty.h"

void find_function(char *toke, char *value, int line_number, int format)
{
    int i;
    int j;

    instruction_t f[] = {
        {"push", &push_stak},
        {"pall", &pall_stak},
        {"pint", &print_stak},
        {"pop", &pop_top},
        {"swap", &swap_stak},
        {"add", &add_tow_top_elements},
        {"nop", &do_nothing},
        {NULL, NULL}};

    for (i = 1, j = 0; f[j].opcode != NULL; i++)
    {
        if (strcmp(toke, f[j].opcode) == 0)
        {
            call_function(f[j].f, toke, value, line_number, format);
            i = 0;
        }
        j++;
    }
}

void call_function(void (*f)(stack_t **, unsigned int), char *toke, char *value, int line_number, int format)
{
     my_stack = NULL;
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
    (void)format;
}
