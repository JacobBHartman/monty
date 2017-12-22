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

/**
 * sub - subtracts the top element of the stack from the second
 * @stack: a pointer to a pointer to the stack
 * @line_number: the line number at which sub was called
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (var->top == NULL || var->top->next == NULL)
		handleError(1100);

	var->top->next->n -= var->top->n;
	pop(NULL, 0);
}

/**
 * divideStack - divides the second top element of stack by the top element
 * @stack: a pointer to a pointer to the stack
 * @line_number: the line number at which div was called
 *
 * Return: void
 */
void divideStack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (var->top == NULL || var->top->next == NULL)
		handleError(1200);

	if (var->top->n == 0)
		handleError(1300);

	var->top->next->n /= var->top->n;
	pop(NULL, 0);
}

/**
 * multiplyStack - multiples the second top element by the top elemtent on stak
 * @stack: a pointer to a pointer to the stack
 * @line_number: the line number at which mul was called
 *
 * Return: void
 */
void multiplyStack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (var->top == NULL || var->top->next == NULL)
		handleError(1400);

	var->top->next->n *= var->top->n;
	pop(NULL, 0);
}

/**
 * moduloStack - computes rest from division of second top by top in the stack
 * @stack: a pointer to a pointer to the stack
 * @line_number: the line number at which mod was called
 *
 * Return: void
 */
void moduloStack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (var->top == NULL || var->top->next == NULL)
		handleError(1500);

	if (var->top->n == 0)
		handleError(1300);

	var->top->next->n %= var->top->n;
	pop(NULL, 0);
}
