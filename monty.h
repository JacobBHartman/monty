#ifndef _MONTY_H_
#define _MONTY_H_


/****************
 |  DIRECTIVES  |
 ****************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/****************
 |  STRUCTURES  |
 ****************/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**********************
 |  GLOBAL VARIABLES  |
 **********************/

typedef struct variable_s
{
	char *file_name;
	FILE *file_address;
	unsigned int line_num;
	char *opcode;
	int daata;
	stack_t *top;
	char *buffer;
} var_t;

extern var_t *var;


/*************************
 |  FUNCTION PROTOTYPES  |
 *************************/


void (*op(char *opcode))(stack_t **, unsigned int);

void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);

void swap(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

void add(stack_t **, unsigned int);

void freeStack(stack_t *top);
void handleError(unsigned int error_code);

#endif /* _MONTY_H_ */
