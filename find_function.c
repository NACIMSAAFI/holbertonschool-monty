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
            call_fun(f[j].f, toke, value, line_number, format);
            i = 0;
        }
        j++;
    }
}
