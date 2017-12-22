#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: a pointer to a pointer to a doubly linked list (stack)
 * @line_number: the line number at which swap was called
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) stack;
	(void) line_number;

	if (var->top == NULL || var->top->next == NULL)
		handleError(900);

	temp = var->top->next;

	var->top->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = var->top;

	temp->next = var->top;
	var->top->prev = temp;
	temp->prev = NULL;

	var->top = temp;
}

/**
 * nop - does nothing
 * @stack: a pointer to a pointer to a doubly linked list (stack)
 * @line_number: the line number at which nop was called
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: a pointer to a pointer to a doubly linked list (stack)
 * @line_number: the line number at which pchar was called
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (var->top == NULL)
		handleError(1600);

	if (var->top->n > 127 || var->top->n < 1)
		handleError(1700);

	putchar(var->top->n);
	putchar('\n');
}
