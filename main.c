#include "monty.h"

stack_t *my_stack = NULL;

int main(int argc, char *argv[])
{
    FILE *file;
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL || argv[1] == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    my_getline(file);
    fclose(file);

    return 0;
}
