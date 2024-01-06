#include "monty.h"

void my_getline(FILE *fd)
{
    int line_number;
    char *buffer = NULL;
    size_t len = 0;

    for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
    {
        tokenizer(buffer, line_number);
    }
    free(buffer);
}

void tokenizer(char *buffer, int line_number)
{
    char *toke, *value;
    const char *delim = "$\n ";

    if (buffer == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    toke = strtok(buffer, delim);
    value = strtok(NULL, delim);
    find_function(toke, value, line_number);
}
