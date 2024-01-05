#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

extern stack_t *my_stack;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void find_function(char *toke, char *value, int line_number, int format);
void call_function(void (*f)(), char *toke, char *value, int line_number, int format);
void push_stak(stack_t **stack, unsigned int line_number);
void pall_stak(stack_t **stack, unsigned int line_number);
void print_stak(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void swap_stak(stack_t **stack, unsigned int line_number);
void add_tow_top_elements(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);



int main(int argc, char *argv[]);

#endif
