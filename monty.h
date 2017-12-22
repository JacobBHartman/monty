#ifndef _MONTY_H_
#define _MONTY_H_

/****************
 *  DIRECTIVES  *
 ****************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/****************
 *  STRUCTURES  *
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
 *  GLOBAL VARIABLES  *
 **********************/
/**
 * struct variable_s - a struct that will hold globally accessible variables
 * @file_name: name of the file opened
 * @file_address: address of the file
 * @line_num: the line number being read currently
 * @opcode: the operation code that tells monty what to do
 * @daata: the data being manipulated by the operation
 * @top: a stack (doubly linked list)
 * @buffer: a buffer that is being written to from each line in the file
 * @arg_one: the argument at index 1 (2nd argument, or the 1st after ./monty)
 * @queue_mode: 1 is on, 1 is off
 *
 * Description: a structure that will hold global variables
 */
typedef struct variable_s
{
	char *file_name;
	FILE *file_address;
	unsigned int line_num;
	char *opcode;
	int daata;
	stack_t *top;
	char *buffer;
	char *arg_one;
	unsigned int queue_mode;
} var_t;

extern var_t *var;


/*************************
 *  FUNCTION PROTOTYPES  *
 *************************/
void parseMontyFile(void);

void (*op(char *opcode))(stack_t **, unsigned int);

void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);

void swap(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);

void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void divideStack(stack_t **, unsigned int);
void multiplyStack(stack_t **, unsigned int);
void moduloStack(stack_t **, unsigned int);

void rotateLeft(stack_t **, unsigned int);
void rotateRight(stack_t **, unsigned int);

void cleanFreeAndClose(void);
void freeStack(stack_t *top);
void handleError(unsigned int error_code);

void onStack(stack_t **, unsigned int);
void onQueue(stack_t **, unsigned int);

#endif /* _MONTY_H_ */
