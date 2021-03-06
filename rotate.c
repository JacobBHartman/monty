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

/**
 * rotateRight - rotates the stack to the bottom
 * @stack: a pointer to a pointer to a stack
 * @line_number: the line number at which rotr was called
 *
 * Return: void
 */
void rotateRight(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1;
	stack_t *temp2;

	(void) stack;
	(void) line_number;

	if (var->top == NULL || var->top->next == NULL)
		return;

	temp1 = var->top;
	temp2 = var->top;
	while (temp2->next != NULL)
		temp2 = temp2->next;

	temp2->prev->next = NULL;
	temp2->prev = NULL;

	temp2->next = temp1;
	var->top = temp2;
	temp1->prev = temp2;
}
