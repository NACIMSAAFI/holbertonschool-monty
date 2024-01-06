#include "monty.h"

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

int tokenizer(char *buffer, int line_number, int format)
{
    char *toke, *value;
    const char *delim = "\n ";

    if (buffer == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    toke = strtok(buffer, delim);
    if (toke == NULL)
        return (format);
    value = strtok(NULL, delim);
    find_function(toke, value, line_number);
    return (format);
}
