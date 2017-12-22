#include "monty.h"

/**
 * rotateLeft - rotates the stack to the top
 * @stack: a pointer to a pointer to a stack
 * @line_number: the line number at which rotl was called
 *
 * Return: void
 */
void rotateLeft(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1;
	stack_t *temp2;

	(void) stack;
	(void) line_number;

	if (var->top == NULL || var->top->next == NULL)
		return;

	temp2 = var->top;
	temp1 = var->top;
	while (temp1->next != NULL)
		temp1 = temp1->next;

	var->top = var->top->next;
	var->top->prev = NULL;

	temp2->next = NULL;
	temp2->prev = temp1;

	temp1->next = temp2;
}
