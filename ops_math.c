#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: a pointer to a pointer to the stack
 * @line_number: the line number at which add was called
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (var->top == NULL || var->top->next == NULL)
		handleError(1000);

	var->top->next->n += var->top->n;
	pop(NULL, 0);
}
